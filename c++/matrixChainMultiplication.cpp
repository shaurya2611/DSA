#include<iostream>
# include<vector>
#include<cstring>
#include<string>
using namespace std;

// 1. MCM (recursion)

// 2. MCM (Memozied)


// 3. Palindrome  Partition (recursively)
/*Given a string find the minimum no of partions are required to make the string palindrome*/
bool palindrome(string s ,int i, int j){
    if (i==j)
        return true;
    if (i>j)
        return true;
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    } 
}
int minPartition(string s, int i, int j){
    // base condition
    if (i>j)
       return 0;
    // base condition
    if (palindrome(s,i,j)==true)
        return 0;

    int minAns = INT16_MAX;

    for (int k = i; k < j; k++)
    {
        int tempAns = minPartition(s,i,k) + 1 + minPartition(s,k+1,j);
        minAns = min(tempAns,minAns);
    }
    return minAns;
}


// 4. Palindrome  Partition (Memomized version)



// 5. SCRAMBELED STRING
bool scrambledCheck(string a, string b){
    if(a.length()!=b.length())
        return false;
    
    if(a.compare(b)==0) // i.e. both string are same
        return true;
}



int main(){

    string s = "nitin";
    cout<<minPartition(s,0,s.length()-1);
    return 0;
}