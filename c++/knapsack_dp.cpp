#include<iostream>
# include<vector>
#include<cstring>
using namespace std;


// 1.  0-1 KNAPSACK implementatio using RECURSION + MEMOIZATION
int knapsackhelper(int weight[], int value[], int maxWeight, int size, int **dp_array ){

    //base condition or initialization in term of top down approch
    //(check by making table)
    if (size==0 or maxWeight==0){
        return 0;
    }

    if (dp_array[size][maxWeight]!=-1)
        return dp_array[size][maxWeight];

    //calculation for one weight
    if (weight[size]<= maxWeight){
        return  dp_array[size][maxWeight]= max(value[size] + knapsackhelper(weight,value, maxWeight-weight[size],size-1,dp_array) , 
                    knapsackhelper(weight, value, maxWeight, size-1,dp_array) );
    }
    else
    {
        return dp_array[size][maxWeight] = knapsackhelper(weight, value, maxWeight, size-1,dp_array); 
    }
    
}
int knapsack(int weight[], int value[], int maxWeight, int size){

    // Dynamic creation of 2D array --
    int ** dp_array = new int*[size+1]; //array of pointers
    for (int i = 0; i <= size; i++)
        dp_array[i] = new int[maxWeight+1]; 
    
    for (int i = 0; i <= size; i++)
        for (int j = 0; j <= maxWeight; j++)
            dp_array[i][j] = -1; // initializing al elements of array to -1
     
    return knapsackhelper(weight,value,maxWeight,size,dp_array);
}

 
   

// 2.  0-1 KNAPSACK implementatio using TOP-DPWN approch
int knapsacktopdown(int weight[], int value[], int maxWeight, int size){
    int t[size+1][maxWeight+1];//2D array declaration

    //initizalizing the array (using base condn) -(check by making table)
    for (int i = 0; i <size+1; i++){
        for(int j = 0; j < maxWeight+1; j++){
            if(j==0 || i==0)
                t[i][j]=0;
        }}
    //from the recursion eqautions
    for (int i = 1; i <size+1; i++){
        for(int j = 1; j < maxWeight+1; j++){
            if(weight[i-1]<= j){
                t[i][j] = max(value[i-1] + t[i-1][j-weight[i-1]]  , t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
            
        }}
        
        return t[size][maxWeight];
}



// 3.  SUBSET SUM  - 
/*For a given array - to find if any subset present for which subset sum == given number
  e.g.-> 2,3,7,8,10, sum=14 --> Ans- False {no such subset}
                     sum=11 --> Ans- True  {3,8}
*/
bool subsetsum(int arr[], int sum, int n){
    int dp_arr[n+1][sum+1];

    //initialization(check by making table)
    for (int i = 0; i <=n; i++){
        for (int j = 0; j <= sum; j++){
          if(i==0)
            dp_arr[i][j]= false;  
          if(j==0)
            dp_arr[i][j]= true;
        }}  
    
    for (int i = 1; i <=n; i++){
        for (int j = 1; j <= sum; j++){
            if (arr[i-1]  <= j)
                dp_arr[i][j] = (dp_arr[i-1][j - arr[i-1]]) or (dp_arr[i-1][j]);
            else
                dp_arr[i][j] = dp_arr[i-1][j];
        }}

        for (int i = 0; i <=n; i++){
            for (int j = 0; j <= sum; j++){
                cout<<dp_arr[i][j]<<"  ";
            }cout<<endl;}
        return dp_arr[n][sum];
}




// 4.  COUNT OF SUBSET SUM -
//For a given array count the number of subsets possible for the given sum
int countSubset(int arr[], int sum, int n){

    int t[n+1][sum+1];
    //Initialization (check by making table)
    for (int i=0; i<=n; i++)
        for (int j=0; j<=sum; j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=sum; j++) {   
            if (arr[i-1]<=j){
                t[i][j] = (t[i-1][j - arr[i-1]])  +  (t[i-1][j]);
            }
            else
                t[i][j] = t[i-1][j];
         }
         for (int i = 0; i <=n; i++){
            for (int j = 0; j <= sum; j++){
                cout<<t[i][j]<<"  ";
            }cout<<endl;}
    return t[n][sum];
}




// 5.  EQUAL SUBSET SUM PARTITION -
// a given array to divide the array in two subset such that sum of each part is equal.
bool equalsumpartiton(int set[], int n){
    
    // such partiton is only possible if sum of all set element is even
    int sum=0;
    for (int i = 0; i < n; i++)
        sum = sum + set[i];

    //If sum is odd two equal partition not possible.
    if (sum%2!=0)
        return false;
    // If sum is even partiton can be possible
    else
    {
      // since 2 equal partion has to be made one subset must have to be sum of given array/2
      sum = sum/2; 
      return subsetsum(set,sum,n);  
    }
}





// 6.  MINIMUM SUBSET DIFFERENCE - 
//For a given array form two subset such that sum of difference of both subset is minimum
int minSubSetDiff(int arr[], int n){
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];

    //-- Now solving the subset sum problem with sum = range --
    int t[n+1][range+1] ;
    //Matrix initialization
    for (int i = 0; i <=n; i++) // i -> rows -> n , j -> columns -> range
        for(int j=0; j<=range; j++){
            if(i==0)
                t[i][j]=false;
            if (j==0)
                t[i][j]=true;
        }
    //Filling the matrix by TOP-DOWN approch  (SUBSET SUM PROBLEM CODE)
    for (int i = 1; i <=n; i++) // i -> rows -> n , j -> columns -> range
        for(int j=1; j<=range; j++){
            if (arr[i-1]<=j)
                t[i][j] = (t[i-1][j - arr[i-1]]) or (t[i-1][j]);
            else
                t[i][j] = t[i-1][j];  
        }

    /*Main aim is to get the last row of the matrix i.e. It will contains below scenrio --
    Aarray availabe will be = Size = n(full array) and coreesponding columns[0-range] will reresent
    wether with full available array for  particular column no SUBSETSUM is possible or not.
     */
    int minDiff = INT8_MAX;
    //range/2 bcz (s2-s1 = min subset sum) and (s1+s2=Range) hence -> [min subset sum = (Range - 2*s1)]   
    for(int i=0;i<=range/2;i++) {
        if (t[n][i]==true){
            minDiff = min( minDiff , (range-(2*i)) );
        }
    }
    return minDiff;
    
}



// 7.  COUNT OF SUBSETS OF GIVEN DIFFERENCE - 
/*An array and a diference will be input --> finding the no of different subset having same difference
  Make two sub array from array - a1 and a2 and finiding there sum of elements as s1 and s2.
  given --> s1 - s2 = d  , 
  and   --> s1 + s2 = range
  thus  --> s1 = (d + range)/2 {d a dn range are known, thus s1 and s2 can be finded out}

  Problem reducered to "COUNT OF SUBSET SUM"  for S1 or S2 any one. 
*/
int countSubSetDiff(int arr[], int diff, int n){ 
    
    //finding range--> sum of array = s1 + s2
    int range=0;
    for (int i = 0; i < n; i++)
        range +=arr[i];
    
    int s1 = (diff + range)/2;

    int count_subsets = countSubset(arr, s1, n);
    return count_subsets;
}



// 8.  COUNT OF SUBSETS OF GIVEN TARGET SUM - 
/*For a given array and a target_sum, insert + and - operators among the elemensta of array such that the
  final sum of array = target_sum variable given in input.
  This problem is same as the Counting the number of subset for given difference
  Just another way to represent the same problem
  */
int targetSum(int arr[], int target_sum, int n){
    return countSubSetDiff(arr, target_sum, n);
}




int main(){
    int arr[] = {2,3,4,7,8,10};
    int sum = 11;
    int diff = 1;
    int n =sizeof(arr)/sizeof(arr[0]);
    // cout<<minSubSetDiff(arr,n);
    cout<<endl<<subsetsum(arr,sum,n);
    cout<<endl<<"--------------------";
    cout<<endl<<countSubset(arr,sum,n); 
    // cout<<countSubSetDiff(arr, diff, n);
    return 0;
}
