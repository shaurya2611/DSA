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



/* 4. --------------MINIMUM NO OF COINS REQUIRED TO MAKEUP SUM----------------------
	 * 
	 * Given a value V, if we want to make change for V cents, and we have infinite supply 
	 * of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins 
	 * to make the change? If it’s not possible to make change, print -1.*/
	
	// ONLY DP ques in which 2nd row is also initialized.
	public static int coinChangeMinReq(int[] coins, int size, int sum) {
		
		int[][] dpArr = new int[size+1][sum+1];
	
		// 1st ROW initialization with MAX_VALUE
		for (int i = 0; i < sum+1; i++)
			dpArr[0][i] = Integer.MAX_VALUE-1;
		// 1st COLUMN initialization with 0
		for (int i = 1; i < size+1; i++)
			dpArr[i][0] = 0;
		// 2nd ROW initialization --
		// If first element of array is fully divide fill by quotient else by MAX_VALUE-1
		for (int i = 1; i < sum+1; i++) {
			if(i%coins[0]==0) 
				dpArr[1][i] = i/coins[0];
			else
				dpArr[1][i] = Integer.MAX_VALUE-1;
		}
		
		// Low same logic of unbounded knapsack
		for (int i = 2; i < size+1; i++) { // i-> size , j-> capacity
			for (int j = 1; j < sum+1; j++) {
				if(coins[i-1] <= j)
					dpArr[i][j] = Math.min(1 + dpArr[i][j-coins[i-1]], dpArr[i-1][j]);
				else
					dpArr[i][j] = dpArr[i-1][j];
					
			}
		}
		return dpArr[size][sum];
	}



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
