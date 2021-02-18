#include<iostream>
# include<vector>
#include<cstring>
using namespace std;


// 1.  UNBOUNDED KNAPSACK
/*Same as 0_1 knapsack with only difference ii Items are available even once they are picked up.
  Repetition of items allowed , unlike 0_1 knapsack each iem was avilable only once.
  */
int unboundedKnapsack(int weight[], int value[], int maxWeight, int size){
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
            if(weight[i-1]<= j)
                t[i][j] = max(value[i-1] + t[i][j-weight[i-1]]  , t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
    }}
    return t[size][maxWeight];
}


// 2.  ROD CUTTING PROBLEM
/* A length of rod is given, and in an array as input sizes and their corresponding prices are given
   We have to find the max price for the given lenth of the rod.
   This probelem is exactly same as unbounded knapsack, just with different explanation.*/
int rodCutMaxPrice(int lengths[], int value[], int maxLength, int size){
    return unboundedKnapsack(lengths, value, maxLength,size);
}   


// 3.  COIN CHANGE PROBLEM-(max no of ways to get a sum)
/* Will infinite availability og given coins, form the given sum
   This problem is same as the COUNT OF SUBSET SUM in 0_1 knapsack*/
int coinChangeMaxWays(int coin[], int sum, int size){
    int t[size+1][sum+1];//2D array declaration

    //initizalizing the array (using base condn) -(check by making table)
   for (int i=0; i<=size; i++){
        for (int j=0; j<=sum; j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }}
  
    for (int i = 1; i <size+1; i++){
        for(int j = 1; j < sum+1; j++){
            if(coin[i-1]<= j)
                t[i][j] = t[i][j-coin[i-1]]  +  t[i-1][j];
            else
                t[i][j] = t[i-1][j];
    }}
    for (int i=0; i<=size; i++){
        for (int j=0; j<=sum; j++){
            cout<<t[i][j]<<"  ";
        }
        cout<<"\n";}
    return t[size][sum];
}



// 4.  COIN CHANGE (min no of coins req. to get a sum)
/*For a given coin array with each coin of multiple instances and the given sum find the minimum no of coins req to make that sum*/
// int coinChangeMinReq(int coin[], int sum, int size){

//     int t[size+1][sum+1];

//     //Inital Initialization (base condn)



// }



int main(){
int lenght[]= {1, 2,3}; 
// int value[]={10, 40, 50, 70}; 
// int maxlen = 8;
int sum = 5;
int size = 3;
// cout<<unboundedKnapsack(lenght,value,maxlen,size);
cout<<coinChangeMaxWays(lenght,sum,size);
return 0;
}