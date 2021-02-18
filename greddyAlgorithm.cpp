/*

--------------------------------GREDDY ALGORITHM-----------------------------------

Core Logic - Makingn optimal CHOICES at each stage, with hope of getting GLOBAL OPTIMUM

Req -- To apply GREEDY STRATEGY, following conditions has to be satisfied
    1) same as DP one--> Optimal Sub-Tree - An optimla soln will contains optimal solnof subparts
        optimal sub structes are solved using RECURSION
    2) GREDDY choice property - (in DP we seacrh exhaustivel, by using the solns of sub-prob) but in greedy
        At each step choices made greedly -> that will result in final/global optimal solution

    **2nd conditon neednot to be satisfied for all real word problems-- e.g.-
        for Fractional knapsack (Greedy)
        for 0_1 Knapsack (greedy will fail, will not result in optimal sol ].)

Problem -- 1) That decision is optimal locally, but that may not be optimal globally
           2) Greeedy approch DON'T reconsider its choices (In DP we reconsider our choices and always get optimal global )

Applications -- 
    1) Activity Selection
    2) Huffman Coding
    3) Job Sequence prob
    4) Fractional Knapsack
    5) Prim's minimum spanning tree

*/


# include<iostream>
# include <iterator>
# include<vector>
using namespace std;
#include <bits/stdc++.h>
# include<map>
# include<unordered_map>


// 1. FRACTIONAL KNAPSACK  -- Complexity - O(nlogn)
//Same as 0_1 knapsack with difference here we can take fractional value of weights also get max output

class Node{
public:
    int weight;
    int value;

    //constructor for 2D array input (weight and value)
    Node(int weight, int value){
        this->weight = weight;
        this->value = value;
    }
};

bool compare(Node a, Node b){
    double l1 = double(a.value)/double(a.weight);
    double l2 = double(b.value)/double(b.weight);
    return l1>l2;    // descending order
} 

int fractionalKnapsack(Node arr[], int size, int limit){

    //std library SORT(start pos ,end pos, on what basis to sort)
    sort(arr,arr+size,compare);

    int curWeight = 0;  
    double finalvalue = 0;

    for (int i = 0; i < size; i++)
    {
        if (curWeight + arr[i].weight <= limit)  
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        // If we can't add current Item, add fractional part 
        // of it 
        else 
        { 
            int remain = limit - curWeight; 
            finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight); 
            break; 
        } 
    }
     return finalvalue;
}





// 2. ACTIVITY SELECTION PROBLEM  -- Complexity -O(nlogn)
/* Given a 2D array with start and finish time--> sort array a/c to finish time, start with 1st finish time
   after that take that activity with start time > preceding finish time*/

class ActivityArr{
public:
    int start;
    int finish;

    ActivityArr(int start, int finish){
        this->start = start;
        this->finish = finish;
    }
};

// function to be passed in sort function to get array soreted according to finish time
bool activityCompare(ActivityArr a, ActivityArr b){
    int f1 = a.finish;
    int f2 = b.finish;
    return f1<f2; // ascending order
}

int activitySelection(ActivityArr arr[], int size){

    sort(arr,arr+size,activityCompare);

    int maxAcitivity = 1; // first activity always selected
    int j = 0;
    for (int i = 1; i < size; i++)
    {
        if( arr[i].start >=  arr[j].finish){
            maxAcitivity+=1;
            j=i;
        }
    }
    return maxAcitivity;

}

  

// 3. JOB SEQUENCING PROBLEM WITH DEALINE -- complexity - O(n^2)]
/*  Given job -> Deadline and profit associated with each job it
    Profit is gaines if job is done before the deadline
    Time to complete each job is 1 unit time
    Schedeule the job such as to gain the maximum profit*/
class JobItems{

    public:
    char jobName;
    int deadLine;
    int profit;

    JobItems(char jobName, int deadLine, int profit){
        this->jobName = jobName;
        this->deadLine = deadLine;
        this->profit = profit;
    }
};

//Fn to sort 2D array on basis of price
bool jobCompare(JobItems a, JobItems b){
    return (a.profit >b.profit); // descending order
}

vector<char> jobScheduler(JobItems arr[], int size){

    sort(arr,arr+size,jobCompare); // Complexity nlogn
 

    int maxSchedule = INT16_MIN;
    // loop to find length of schedule array
    for (int i = 0; i < size; i++) // O(n) 
        maxSchedule = max(arr[i].deadLine , maxSchedule);

    //initializing all elemnts of vector with 0
    vector<char> v;
    for (int i = 0; i < maxSchedule; i++)
        v.push_back('0');
    
    int maxProfit = 0;

    for (int i = 0; i < size; i++)
    {
        int slot = arr[i].deadLine-1;
        while (slot>=0)
        {
            if (v[slot]=='0') // enter in sheduler only if slot is free
            {
                v[slot] = arr[i].jobName;
                cout<<arr[i].jobName;
                maxProfit+=arr[i].profit;
                break;
            }
            slot--;
        }

    }
    cout<<"Max Profit : "<<maxProfit;
    return v;
}






// 4. HUFFMAN ENCODING
/*  It's compression technique used to compress the data BITs WISE
    In ASCII format character ranges from 0-127, hence Bits req to represent each character = 7
    Problem - Less transmission speed while msg transmission as BITS are more
    Solution - Using Greedy Technqiue bits req per character can be reducred based on their frequency*/






// 5. Minimum coins to remove such that absolute difference between any two piles is less than K
int minCoinsRemoved(int a[], int size, int maxDifference){

    //findinf minimum elenet of array
    int minElement = INT16_MAX;
    for (int i = 0; i < size; i++)
        minElement = min(a[i],minElement);
    
    int coinsCount = 0;

    //Iterating whole array
    for (int i = 0; i < size; i++)
    {
        // Difference between Minelement of array to each element
        int diff = a[i] - minElement;
        
        // If the difference between the current pile and the minimum coin pile is greater than k 
        if (diff > maxDifference)
            coinsCount+=(diff - maxDifference);
    }
    return coinsCount;
}





// 6. MAXIMUM TRAIN STOPPAGE
/*  each train has three value first arrival time, second departure time and third required platform number. 
    We are given m such trains you have to tell maximum number of train for which you can provide stoppage at your station
    
    This problem same as ACTVITY SELECTION PROBLEM--(sort in ascending order of depature time)
    */
class Train{
    public:
        int arrival;
        int departure;
        int platform;

    Train(int arrival,int departure, int platform){
        this->arrival = arrival;
        this->departure = departure;
        this->platform = platform;
        }
};

bool departureCompare(Train a, Train b){
    return  (a.departure < b.departure);// In ascending ordre of departure time
}
/* Input for the question ---
Train arr[] = {{900, 1005, 1}, {1000, 1020, 2}, {1000, 1030, 1}, {1010, 1030, 1}, {1030, 1230, 2 },{1200, 1230, 3}}; */
int maxTrainStopped(Train arr[],int size){

    // sorting array accordint to DEparture time (ascending order)
    sort(arr,arr+size,departureCompare);

    // using ORDERED MAP --> Key as uniform and initializing all platform as 100 as empty stations
    map<int,int> m;
    for (int i = 0; i < size; i++)
        m.insert(pair<int,int>(arr[i].platform,100)); // using insert fn duplicate keys are not allowed

    // Iterating through sorted array
    int trainStopped = 0;

    for (int i = 0; i < size; i++)
    {
        // If platform is empty-- assign it train
        if (m[arr[i].platform]==100)
        {
            m[arr[i].platform]=i;
            trainStopped++;
        }
        // else assign train by comparing it with copatible platform no comparing last train defature and next train  arrival
        else
        {
            int platformCheck = arr[i].platform;
            int currentTrainIndx = m[platformCheck];

            if (arr[currentTrainIndx].departure <= arr[i].arrival)
            {
                m[platformCheck]=i;
                trainStopped++;
            }
            
        }
        
        
    }
    
    return trainStopped;

}






// 7. MINIMUM PLATFORM NEEDED
/* Given arrival and departure of train in two array. FInd the minimum no of platform req. to allow their passagae without waiting.*/
int minPlatform(int arrival[], int departure[], int size){

    // creating pair of arrival and departure trains.
    vector<pair<int,int>> trainSchedule;

    for (int i = 0; i < size; i++)
        trainSchedule.push_back(make_pair(departure[i], arrival[i]));//pair<int,int>(arrival[i],departure[i]) -- same 
        // departure taken first in pair as sort function by default ort on first lelement of pair
        // to sort on seco nd element we eill have to make a boolean function

    sort(trainSchedule.begin(),trainSchedule.end());

    vector<int> platform;

    //initially assiging 1st train to platform 1
    platform.push_back(0);

    for (int i = 1 ; i < size; i++)
    {
        // second --> Arrival time , first --> Departure Time
        int j=0;
        int flag=0;
        while (j<platform.size()){       
        if ( trainSchedule[i].second  >=trainSchedule[platform[j]].first)
        {
            platform[j]=i;
            flag=1;
            break;
        }
        j++;
        }

        if(flag==0)
            platform.push_back(i);
    }
    return platform.size();    
}





// 8. CHOCALATE DISTRIBUTION PROBLEM
/*  Distrubute 'n' packets among 'm' students such that the diffrenec between the min and max of 
    distribution is minimum
    e.g. - Packet Sizes - 3 4 1 9 56 7 9 12 , students - 5, min diff - 9-3 = 6

    Sort the packet array and as per teh given students find the diff of subsets. */
int minDiffChoclate(int arr[], int size, int students){

    sort(arr,arr+size);

    int minDiff  = INT16_MAX;

     int i=0;
     int j = students-1;
     while (j<size)
     {
        int diff = arr[j] - arr[i];
        minDiff = min(minDiff,diff);
        i++;
        j++;
     }
     return minDiff;
}






// 9. Find maximum meetings in one room
/*  There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) 
    where S[i] is the start time of meeting i and F[i] is finish time of meeting i. The task is to 
    find the maximum number of meetings that can be accommodated in the meeting room. Print all meeting numbers*/
//Input : s[] = {1, 3, 0, 5, 8, 5}, f[] = {2, 4, 6, 7, 9, 9} -- Output : 1 2 4 5 
void maxMeeting(int start[], int finish[], int size){
    // forming pair 
    vector<pair<int,int>> schedule;

    for (int i = 0; i < size; i++)
        schedule.push_back(make_pair(finish[i],start[i]));//finish first as sort fn by deafaut sort by first value in pair

    // sorted array by finish time in ascending order
    sort(schedule.begin(),schedule.end());

    int lastIndx = 0;
    cout<<"Arrival : "<<schedule[0].second<<"   Departure : "<<schedule[0].first<<endl;
    for (int i = 1; i < size; i++)
    {
        if (schedule[i].second >= schedule[lastIndx].first)
        {
            lastIndx = i;
            cout<<"Arrival : "<<schedule[i].second<<"   Departure : "<<schedule[i].first<<endl;
        }
        
    }
        
    
}






int main(){
    int limit = 50; //    Weight of knapsack 
    // Node arr[] = { { 10,60}, {20, 100 }, { 30,120} }; // 2D array of (weight, value)

    // ActivityArr arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};

    // JobItems arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
    //                {'d', 1, 25}, {'e', 3, 15}}; 

    // int n = sizeof(arr)/sizeof(arr[0]); 
  
    // vector<char> v = jobScheduler(arr,n);
    // cout<<endl;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" --> ";
    // }
    // int a[] = { 1, 5, 1, 2, 5, 1 }; 
    // int n = sizeof(a) / sizeof(a[0]); 
    // int k = 3; 
  
    // cout << minCoinsRemoved(a, n, k); 
    // Train arr[] = {{900, 1005, 1}, {1000, 1020, 2}, {1000, 1030, 1}, {1010, 1030, 1}, {1030, 1230, 2 },{1200, 1230, 3}}; 
    
    // int n = sizeof(arr) / sizeof(arr[0]);

    // cout << "Maximum Stopped Trains = "
    //      << maxTrainStopped(arr,n); 
    // int arrival[] = {900,1100,1235};//{900 , 940, 950 , 1100, 1500, 1800};
    // int departure[] = {1000,1200,1240};//{910 ,1200, 1120, 1130, 1900, 2000};
    // int size = sizeof(arrival)/sizeof(arrival[0]);
    // cout<<minPlatform(arrival,departure,size);
    // 	int a[] = {3, 4, 1, 9, 56, 7, 9, 12};
	// int n = sizeof(a)/sizeof(a[0]);
	// int m = 5;
	int s[] = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
    int f[] = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252 };
    int n = sizeof(s) / sizeof(s[0]);
    maxMeeting(s,f,n);
    return 0; 
}