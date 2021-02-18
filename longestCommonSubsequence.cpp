#include<iostream>
# include<vector>
#include<cstring>
#include<string>
using namespace std;

// SUBSEQUENCE --> continuous or non continuous (in same order) 
// SUBSTRING --> Continuous (in same order)


// 1.  LONGEST COMMON SUBSEQUENCE (by recursion) -- 
/*In both the string common elements have to be in same sequence also, 
  Common elements may or may not be together but have to in same sequence*/
int lcsRecursive(string x,string y, int n, int m){
    //base condition
    if(n==0 or m==0)
        return 0;

    //Choice diagram for 1 element(starting from last here)
    if (x[n-1]==y[m-1])
        return 1 + lcsRecursive(x,y,n-1,m-1);
    else
        return max(lcsRecursive(x,y,n-1,m) , lcsRecursive(x,y,n,m-1));
} 



// 2.  LENGTH LONGEST COMMON SUBSEQUENCE (by TOP DOWN approch)
int lcs(string x,string y, int n, int m){
    int t[n+1][m+1];
    //Initialization (base condn)
    for (int i = 0; i <= n; i++)
        for(int j=0; j<=m; j++){
            if (i==0)
                t[i][j]=0;
            if (j==0)
                t[i][j]=0;
        }

    for (int i = 1; i <= n; i++)
        for(int j = 1; j<=m; j++){
            if(x[i-1]==y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j] ,t[i][j-1]);
        }
   
    return t[n][m];
}
    


// 3.  PRINTING LONGEST COMMON SUBSEQUENCE
void printLcs(string x,string y, int n, int m){
    int t[n+1][m+1];
    for (int i = 0; i <= n; i++)
        for(int j=0; j<=m; j++){
            if (i==0)
                t[i][j]=0;
            if (j==0)
                t[i][j]=0;
        }
    
    for (int i = 1; i <= n; i++)
        for(int j=1; j<=m; j++){
            if (x[i-1]==y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
        }

    int i = n ; 
    int j = m;

        while (j>=1 and i>=1)
        {
            //if ((t[i][j-1] == t[i-1][j]) and (t[i][j] = t[i-1][j-1] + 1)){
            if (x[i-1]==y[j-1]){
                cout<<y[j-1]<<" ";
                i = i-1;
                j = j-1;
        }
            else{
                if (t[i-1][j] > t[i][j-1])
                    i = i-1;
                else
                    j = j-1;                
            }   
        }
}



// 4.  LENGTH LONGEST COMMON SUBSTRING
/*All the possible substring length will be present in the dp arrya.
By itearating thpugh 2D dp array we can get the maximum length size*/ 
int largestCommonSubstring(string x,string y, int n, int m){
    int t[n+1][m+1];

    //Initislization
    for (int i = 0; i <= n; i++)
        for(int j=0; j<=m; j++){
            if (i==0)
                t[i][j]=0;
            if (j==0)
                t[i][j]=0;
        }

    for (int i = 1; i <= n; i++)
        for(int j = 1; j<=m; j++){
            if(x[i-1]==y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = 0;  //If not continuous turn to 0 , // max(t[i-1][j] ,t[i][j-1]);
        }
    

    int maxLen = INT8_MIN;
    for (int i = 0; i <= n; i++){
        for(int j = 0; j<=m; j++){
            cout<<t[i][j]<<"  ";
            maxLen = max(maxLen,t[i][j]);
        }cout<<"\n";}
  
    return maxLen;
}



// 5.  SORTEST COMMON SUPERSEQUENCE
/* Given two strings  form a single string such that it contains all the elements of both the strings in sequence
   Form a such supersrquence abd return the legth of such shortest superseq. string
   Solution -  Find the LCS and sub it from both*/
int sortestSuperSequence(string x, string y, int n,int m){
    int largestSeq = lcs(x,y,n,m);
    return ((n-largestSeq) + (m-largestSeq) + largestSeq);
}



// 6. PRINTING SORTEST COMMOM SUPERSEQUENCE (review it)
/* Witha same logic as printing the LCS, but along with LCS print all uncommon elments
   Given Strings a and b --> (SCS = n + n - LCS) 
*/
void printSCS(string x, string y,int n,int m){
    int t[n+1][m+1];
    //Initialization (base condn)
    for (int i = 0; i <= n; i++)
        for(int j=0; j<=m; j++){
            if (i==0)
                t[i][j]=0;
            if (j==0)
                t[i][j]=0;
        }

    for (int i = 1; i <= n; i++)
        for(int j = 1; j<=m; j++){
            if(x[i-1]==y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j] ,t[i][j-1]);
        }
    cout<<endl<<"String 1 : "<<x;
    cout<<endl<<"String 2 : "<<y;
    cout<<endl<<"SCS length : "<<(m+n-t[n][m]);
    cout<<endl<<"SCS String : ";

    int i = n;
    int j = m;
    while (i>=1 and j>=1)
    {
        if(x[i-1]==y[j-1]){
            cout<<y[j-1];
            i--;
            j--;
        }
        else
        {
            if (t[i-1][j] > t[i][j-1]){
                    cout<<x[i-1];
                    i = i-1;}
                else{
                    cout<<y[j-1];
                    j = j-1; }
        }
        //To print remaiming string if in case:--
        while(i>0){
            cout<<x[i];
            i--;
        }
           while(j>0){
            cout<<y[j];
            j--;
        }
               
    }
    



}



// 6.  MIN NUMBER OF INSERTION AND DELETION (to convert Sting A to string B)
/* Find the LCS between 2 strigns then --
   Len String A - LCS = No of deletion req. 
   Len String B - LCS = No of insertion req. */
void minInsertDelete(string x, string y, int n, int m){
   
   int longestSeq = lcs(x,y,n,m);
   cout<<endl<<"No of INSERTION req. to convert : "<<x<<"  , to : "<<y<<"  -->  "<<(y.size() - longestSeq);
   cout<<endl<<"No of DELETION req. to convert : "<<x<<"  , to : "<<y<<"  -->  "<<(x.size() - longestSeq);
    
}



// 7.  LONGEST PALINDROMIC SEQUENCE
/* Given a input string we havr to find the longest PALINDOMIC substring
   Solution - To apply LCS - LCS takes two input string and return an int.
   Here we have only one input string, SECOND STRING can be taken as reverse of first one, and appky LCS
 */
int longestPanlindomeSeq(string x, int n){
    string y;
    for (int i = n-1; i >= 0; i--)
        y+=x[i];
    int longPalindSeq = lcs(x,y,n,n);
    return longPalindSeq;
}



// 8. MIN DELETION/INSERTION TO MAKE STRING PALINDROME -   
/* Same as 7 ques. 
   Find the longest Palindroin Subsequence(from LCS) and subtract its length by input string lengh.  
*/
int minDeletionPanlindomeSeq(string x, int n){
    string y;
    for (int i = n-1; i >= 0; i--)
        y+=x[i];
    int longPalindSeq = lcs(x,y,n,n);
    return (n - longPalindSeq);
}



// 9. LONGEST REPEATING SUBSEQUENCE (review)
/* SUbsequence - Order of elements matters and elements can be discontinuous.
   Ques- In a given string find the substring from  it that are repeated and among all the substrings find the length of maimum one.
   e.g. - "AABEBDCD" --> repeating subseqs - {ABD*2 , AB*2, BD*2, AD...etc} -ABD longest repeating 
*/
int longestRepeatingSubseq(string x,string y, int n, int m){
    //base condition
    if(n==0 or m==0)
        return 0;

    //Choice diagram for 1 element(starting from last here)
    if (x[n-1]==y[m-1] and n!=m)
        return 1 + longestRepeatingSubseq(x,y,n-1,m-1);
    else
        return max(longestRepeatingSubseq(x,y,n-1,m) , longestRepeatingSubseq(x,y,n,m-1));
} 


int main(){
    string x = "aabcbedd";
    int n = x.length();
    cout<<longestRepeatingSubseq(x,x,n,n);
    // cout<<endl<<longestPanlindomeSeq(x,n);
    // cout<<endl<<"INPUT STRING - "<<x;
    // cout<<endl<<"Min deletion req - "<<minDeletionPanlindomeSeq(x,n);
    // string y = "acbcf";
    // int m = y.length();

    // printSCS(x,y,n,m);

    // cout<<endl<<lcsRecursive(x, y, x.length(), y.length());
    // cout<<"\n";
    // cout<<endl<<lcs(x,y,n,m)<<endl;
    // printLcs(x,y,n,m);
    // cout<<endl<<sortestSuperSequence(x,y,n,m);
    //  minInsertDelete(x,y,n,m);
    // cout<<endl<<largestCommonSubstring(x,y,n,m)<<endl;
    return 0;
}