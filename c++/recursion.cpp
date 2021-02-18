# include<iostream>
# include <vector>
# include<string>
# include<unordered_set>
using namespace std;

// fn to find the first occurance of a no
int first_occur(int arr[], int size, int no ){
    if (size<1){
        return -1;
    }
    if (arr[0]==no){
        return 0;
    }
    else{
        int ans = first_occur(arr+1 , size-1, no);
        if (ans!=-1)
            return ans+1;
        else
            return -1;
        
    }
}

// fn to find the last occurance of a no from the back of array : 
int last_occ_1(int a[], int size, int no){
    if (size<1)
    return -1;

    if (a[size-1]==no)
        return size-1;
    else
        last_occ_1(a,size-1,no);
}

// fn to find the last occurance of a no from the starting of array :
int last_occ_2(int a[], int size, int no)
{
    if (size == 0)
      return -1;
    // Just assume recusrion was applied on a+1 part and it has done job and returned last occ of no.
    int answer = last_occ_2(a + 1, size - 1, no);

    if (answer != -1)
      return answer + 1; // bcz actual array was 'a', and in recursion it was 'a+1'

    // Calculation for the first term (recursion worked on a+1 array)
    if (a[0] == no)
      return 0;
    else
      return -1;
}

// fn to store all the ocuuracne of number by doing calculation first
int all_occ(int a[], int size, int no, int count=0){
    if (size==0)
        return count;
    
    if (a[0]==no)
        all_occ(a+1, size-1, no, count+1);
    else
        all_occ(a+1, size-1, no, count);
}

// fn to store all the ocuuracne of number by calling recursion first
int all_occ_2(int a[], int size, int no){
    if (size<0)
        return 0;
    // Just assume recusrion was applied on (1 to n-1) part and it has done job and returned no of occ
    int ans = all_occ_2(a, size-1, no);
    // Dealing with last item of array
    if (a[size]==no)
        return (ans+1);
    else
        return ans;
}

// Length of string 
int length_str(char s[]){

    //1. Base condition -- Minimum possible output
    if (s[0]=='\0')   
        return 0;

    //2. Recursion (with smaller/larger input)
    int len = length_str(s+1);// if recc called ans will be stored/ our work done

    // Calculation
    return 1+ len;
    // return (1 + length_str(s+1));
}

// Removing a Character from string
void remove_char(char s[]){
    if (s[0]=='\0')
    return;
    if (s[0]=='x'){
        int i=1;
        for(;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        s[i-1] = s[i];
        return remove_char(s);
    }
    else{
        return remove_char(s+1);
    }

}


// MERGE SORT (array) -- complexity - O(nlogn)
/* Divide array in two equal half till one one element left in array, then merge the sub sorted array*/
void mergeArray(int arr[], int l, int m, int r){
    int n1 = m-l+1; // given the starting, mid and end index of array
    int n2 = r-m;

    int a[n1];// copying the data from single array to 2 Array
    int b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l+i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[m+1+i];
    
    int i=0 ; 
    int j =0;
    int k=l;
    
    while(i<n1 and j<n2){
        if(a[i] > b[j]){
            arr[k] = b[j];
            j++;
        }
        else{
            arr[k] = a[i];
            i++;
        }  
        k++; 
    }

     while (i < n1) 
    {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r){
    if (l<r){
        int m = l + (r - l) / 2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        mergeArray(arr,l,m,r);
    }
}


// TOWER OF HANAOI
void towerOfHanoi(int n, char from_rod, char to_rod, char help_rod)  
{    //base condn -
    if (n == 1)  
    {  
        cout << "Move disk 1 from rod " << from_rod <<  " to rod " << to_rod<<endl;  
        return;  
    }  

    //Recursion Hypothesis (recursion done the work on (n-1) piles moved to HELPER pile)
    towerOfHanoi(n - 1, from_rod, help_rod, to_rod);  

     //Inductio Step - (1 plate left on source, (n-1)moved to helper -> 1 to be moved on destination)
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;

    towerOfHanoi(n - 1, help_rod, to_rod, from_rod);  //movement of (n-1) plates on helper to destination
}  


// SUBSEQUENCES of input (repition allowed) -- by Recursion decision tree
void allSubset(string ip,string op){
    // base condition
    if(ip.size()==0){
        cout<<op<<endl;
        return;
    }

    // Now making decision tree--
    string op1 = op; // character not taken
    string op2 = op; // character taken
    op2.push_back(ip[0]);

    ip.erase(0,1);// making input smaller by earsing processsed first character

    allSubset(ip,op1);
    allSubset(ip,op2);
}


// SUBSEQUENCES of input (without repetition) -- by Recursion decision tree
void uniqueSubset(string ip, string op){
    
    static unordered_set<string> str;

    // base condition
    if(ip.size()==0){
        if (str.count(op)==0)
        {
           str.insert(op);
           cout<<op<<endl;
        }
        
        return;
    }

    // Now making Choices (DT)--
    string op1 = op; // character not to be taken
    string op2 = op; // character to be taken
    op2.push_back(ip[0]);

    ip.erase(0,1);// making input smaller by earsing processsed first character

    uniqueSubset(ip,op1);
    uniqueSubset(ip,op2);


}


// PERMUTATION with SPACES--
void spacePermutation(string ip, string op){
    // abse condition
    if (ip.size()==0){
        cout<<op<<endl;
        return;
    }

    // CHoices available - 
    if (ip.size()==1){
        op.push_back(ip[0]);
        ip.erase(0,1);
        spacePermutation(ip,op); 
        }
    else
    {   // Choice 1- taking element without spaces
        string op1 = op; 
        op1.push_back(ip[0]);

        // Choice 2 - taking element with spaces
        string op2 = op;
        op2.push_back(ip[0]);
        op2.push_back(' ');

        //making input smaller
        ip.erase(0,1); //earse 1 element starting from oth index

        spacePermutation(ip,op1);
        spacePermutation(ip,op2);
    }
    
    


    
}


// PERMUTATION with CASECHANGE - 
void casePermutation(string ip, string op){
    if (ip.size()==0)
    {
        cout<<op<<endl;
        return;
    }

    string op1 = op;
    op1.push_back(ip[0]);

    string op2 = op;
    op2.push_back(toupper(ip[0]));

    ip.erase(0,1);

    casePermutation(ip,op1);
    casePermutation(ip,op2);
    
}



// BALANCED PARANTHESIS -
void balancedParanthesis(int open, int close, string op){
    if(open==0 and close==0){
        cout<<op<<endl;
        return;
    }
 
    if(open!=0){
        string op1=op;
        op1.push_back('(');
        open = open-1;
        balancedParanthesis(open,close,op1);
    }

    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        close=close-1;
        balancedParanthesis(open,close,op2);
    }
    return;
}


int main()
{
   string ip = "ab";        
   string op = "";
   
    // allSubset(ip,op);
    // uniqueSubset(ip,op);
    // spacePermutation(ip,op);    
    // casePermutation(ip,op);
    balancedParanthesis(3,3,op);
    return 0;
}
