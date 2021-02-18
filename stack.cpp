#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// 1. NEXT LARGEST ELEMENT to right --- in time complexity O(n)
/* For every element starting from right , correcponding erey element print the nerarest largest 
   in right hand side of arry, if not found ptint -1 */
vector<int> greaterRight(int a[],int n){
    vector<int> result ;
     stack<int> s;
     for (int i = n-1; i >=0; i--)
     {
        if(s.size()==0)
            result.push_back(-1);
        
        else if (a[i] < s.top())
        {
            result.push_back(s.top());
        }
        
        else if (a[i] >= s.top())
        {
            while (s.size()>0 and a[i]>=s.top() )
            {
                s.pop();
            }
            if (s.size()==0)
                result.push_back(-1);
            else
                result.push_back(s.top());
        }
        s.push(a[i]);
     }  
     return result;   
} //Complexity O(n)



// 2. NEXT LARGEST ELEMENT to left
/* For every element starting from right , correcponding erey element print the nerarest largest 
   in left hand side of arry, if not found ptint -1 */
vector<int> greaterLeft(int a[],int n){
    vector<int> result ;
     stack<int> s;
     for (int i = 0; i < n; i++)
     {
        if(s.size()==0)
            result.push_back(-1);
        
        else if (a[i] < s.top())
        {
            result.push_back(s.top());
        }
        
        else if (a[i] >= s.top())
        {
            while (s.size()>0 and a[i]>=s.top() )
            {
                s.pop();
            }
            if (s.size()==0)
                result.push_back(-1);
            else
                result.push_back(s.top());
        }
        s.push(a[i]);
     }  
     return result;   
} //Complexity O(n)



// 3. NEXT SMALLER ELEMENT to left
vector<int> smallerLeft(int a[],int n){
    vector<int> result ;
     stack<int> s;
     for (int i = 0; i < n; i++)
     {
        if(s.size()==0)
            result.push_back(-1);
        
        else if (a[i] > s.top())
        {
            result.push_back(s.top());
        }
        
        else if (a[i] <= s.top())
        {
            while (s.size()>0 and a[i]<=s.top() )
            {
                s.pop();
            }
            if (s.size()==0)
                result.push_back(-1);
            else
                result.push_back(s.top());
        }
        s.push(a[i]);
     }  
     return result;   
} //Complexity O(n)



// 4. NEXT SMALLER ELEMENT to right
vector<int> smallerRight(int a[],int n){
    vector<int> result ;
     stack<int> s;
     for (int i = n-1; i >= 0; i--)
     {
        if(s.size()==0)
            result.push_back(-1);
        
        else if (a[i] > s.top())
        {
            result.push_back(s.top());
        }
        
        else if (a[i] <= s.top())
        {
            while (s.size()>0 and a[i]<=s.top() )
            {
                s.pop();
            }
            if (s.size()==0)
                result.push_back(-1);
            else
                result.push_back(s.top());
        }
        s.push(a[i]);
     } 
     reverse(result.begin(), result.end()); 
     return result;   
} //Complexity O(n)



// 5. STOCK SPAN PROBLEM (Review-- Pair use in stack)
/* for a particular element find the number of Consecutive smaller or equal before it 
   e.g. i/p --> 100--80--60--70--60--75--85
        o/p -->   1   1   1   2   1   4   6
   
   Solution - This problem is same as finding the Nearest Greater to left 
              with difference of (element index - index of that nearest greater element)      
           */
vector<int> stockSpan(int a[],int n){
     vector<int> indx ;
     stack<pair<int,int>> s; // using pair to store element as well as its index at same time
     // pair of element , index
     for(int i = 0; i < n; i++){
        if(s.size()==0)
            indx.push_back(-1);
        else if (a[i] < s.top().first)
            indx.push_back(s.top().second);
        else if (a[i] >= s.top().first){
            while (s.size()>0 and a[i]>=s.top().first)
                s.pop();
            if (s.size()==0)
                indx.push_back(-1);
            else
                indx.push_back(s.top().second);
        }
        s.push({a[i],i});
     }  
     return indx;   
} //Complexity O(n)



// 6. MAXIMUM AREA RECTANGLE in HISTOGRAM-
/* It is combimation of both NSR and NSL 
Solution - For the given input array find the NSR and NSL index basis and 
           apply (NSR - NSL - 1)*element and take the max area among the all   */
int maxAreaHistogram(int a[], int n){
    
    vector<int> resultNSR ;
     stack<pair<int,int>> s; // <pair 'element' , 'index'>
     for (int i = n-1; i >= 0; i--){
        if(s.size()==0)
            resultNSR.push_back(n);
        else if (a[i] > s.top().first)
            resultNSR.push_back(s.top().second);        
        else if (a[i] <= s.top().first){
            while (s.size()>0 and a[i]<=s.top().first)
                s.pop();
            if (s.size()==0)
                resultNSR.push_back(n);
            else
                resultNSR.push_back(s.top().second);
        }
        s.push({a[i],i});
     } 
     reverse(resultNSR.begin(), resultNSR.end());


    vector<int> resultNSL ;
     stack<pair<int,int>> st;
     for (int i = 0; i < n; i++){
        if(st.size()==0)
            resultNSL.push_back(-1);
        else if (a[i] > st.top().first)
            resultNSL.push_back(st.top().second);
        else if (a[i] <= st.top().first){
            while (st.size()>0 and a[i]<=st.top().first)
                st.pop();
            if (st.size()==0)
                resultNSL.push_back(-1);
            else
                resultNSL.push_back(st.top().second);
        }
        st.push({a[i],i});
     }

    int maxArea = INT16_MIN;
   
    for (int i = 0; i < n; i++){
        int area = (resultNSR[i] - resultNSL[i] -1)*a[i];
        maxArea = max(area,maxArea);
    }
    return maxArea;
}



// 7. MAXIMUM AREA RECTANCGLE fron 2D ARRAY- (Review)
/* Given a 2D array find the max possible area of reactangle possible
   Solution - Covert the 2D array into 1D arrya each row wise, with preceding row as addition, starting from 2 row 
              i.e. m*n 2D array gives --> m histograms
              Apply the Max Area Rectangle on each row and find the maximum area. */
int maxAreaMatrix(int a[4][4]){

    int v[4];
    for (int i = 0; i < 4; i++)
        v[i] = a[0][i];

    int maxArea = maxAreaHistogram(v,4);

    for (int i = 1; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(a[i][j]!=0)
                v[j] = v[j] + a[i][j];
            else
                v[j] = 0;
     }
     int area = maxAreaHistogram(v,4); 
     maxArea = max(area, maxArea); 
    }
    return maxArea;
}



// 8. RAIN WATER TRAPPING
int rainWaterTrap(int a[], int n){  // a[] = {3,5,0,4,6,9}

    int maxLeft[n] ; 
    int maxl = a[0] ;

    int maxRight[n] ; 
    int maxR= a[n-1];
    
    for (int i = 0; i < n; i++){
        maxLeft[i] = max(a[i],maxl);
        maxl = maxLeft[i];

        maxRight[n-1-i] = max(a[n-1-i],maxR);
        maxR = maxRight[n-1-i];
    }
    

    int rainTrap = 0;
    for (int i = 0; i < n; i++) 
    {
        int minArea = min(maxLeft[i],maxRight[i]);
        rainTrap += (minArea - a[i]) ;
    }
    
       return rainTrap;
     

}



// 9. MINIMUM ELEMENT IN STACK (using 2 stack)
    stack<int> s;
    stack<int> ss;
void push(int x){
    if(s.size()==0){
        s.push(x);
        ss.push(x);}
    else{
        s.push(x);
        if(ss.top() > x )
            ss.push(x);}
}
void pop(){
    if (s.size()==0)
    {
        cout<<"STACK is empty!!!";}
    
    else if (s.top() == ss.top()){
        s.pop();
        ss.pop();
    }
    else
        s.pop(); 
    
}



// 10. REVERSE STRING (using STACK)
void stringReverse(string s){

    stack<char> st;
    for (int i = 0; i < s.size(); i++)
          st.push(s[i]);
    
    int j=0;
    while (st.size()!=0)
    {
        s[j] = st.top();
        st.pop();
        j++;
    }
}



// 12 PLACING ELEMENT AT STACK BOTTOM (without using any Data structure) using recusrion
void placeBottom(stack<int> st, int x){
    /* This fn will place the element at the end of stack*/
    if (st.size()==0){
        st.push(x);
        return;
      }  
    
    int temp = st.top();
    st.pop();
    placeBottom(st,x);
    st.push(temp);
    return;

} 



// 11. SORT STACK (using RECURSION)
/* Take a stack as input and pop all the elements of stack a d store in a variable
then place each element in right position*/
void insertCorrectPos(stack<int> st, int x){
    if (st.size()==0 or st.top()<x){
        st.push(x); // push element in stack if stack is empty or insert element is greater then top.
        return ; }  

    int temp = st.top(); // poping top from the stack as it is greater then the element
    st.pop();
    insertCorrectPos(st,x); // assuming elemnt inserted at correct pos.
    st.push(temp); // again pushing the poped element in stack
}
void sortStack(stack<int> st){
    // base condition
    if(st.size()==0)
        return;
    
    // Emptying whole stack
    int temp = st.top();
    st.pop();
    sortStack(st);

    //Placing the elements at correct position
    insertCorrectPos(st,temp);
}



// 12. REVERSE STACK (using RECURSION) - space complexity --> O(1) i.e. no extra sapce be used
void reverseStack(stack<int> st){
    if (st.size()==1)
        return;
    
    int temp = st.top();
    st.pop();

    //Hyothesis (assuming stack reversed , only work left to place the first poped element)
    reverseStack(st);

    placeBottom(st,temp);

    return;
}



// 13. DELETION OF MID ELEMENT (recursively)
void deleteMidElement(stack<int> st, int mid){
    if(st.size()==0 or mid==0)
        return;

    int temp = st.top();
    st.pop();
    deleteMidElement(st,mid-1);
    if(mid!=1)
        st.push(temp); 
    }



//



int main(){
   stack<int> s;
   s.push(2); s.push(3);s.push(4);s.push(5);
    placeBottom(s,1);
    while (s.size()!=0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}