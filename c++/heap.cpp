/* 

For the implementation of the "PRIORITY QUEUES" -  the best DS that can be implemented with minimum time comeplexity
of O(logn) is BINARY TREE. 
But for this to be effective BST has to be balanced always, to achevie this complexity.
Thus to staisfy this BST are addede with below property and was named HEAP.


HEAPS -are DS which satisfy below two condns 
    1. Heap are the "Compete binary tree - CBT" i.e. all the levels has to be complete, 
       only eception in last level from left to right conituity
    2. CBT must satify the HEAP ORDER PROPERTY--
       MIN HEAP -- > (each root must be smaller then its both child)
       MAX HEAP  --> (each root must be greater then its both children)

HEaps are used to implement the PRIORITY QUEUES 
Height of CBT -> logn - always in worst and in best case both.
Thus for all the opertaions complexity will be O(logn)

Insertion in CBT can be possible by LEVEL ORDER - complexity in that is O(n)
Thus converting CBT to array (PQ are actually implementes as array , just assumed as CBT structure)
For each node its child are stored at (2i+1 , 2i+2) position in array.
Thus by this CBT to array  -INSERTIN and DELETION will be of complexity O(1) only.


-----" Here we are actually implementing on array but it has to be visulaized as CBT "-----
* In arrray relation between childs and parent index--> 
                Child Indexs = 2(Parent Index)+1 , 2(Parent index)+2


Priority Queues - Are of two types
        * Min PQ
        * Max PQ


* HEAP DS is used in sorting type of ques
* IDENTIFICATION -- Kth elemnt and MIN/MAX is asked
* WHY HEAP --> Complexity in best sorting - O(nlogn)
               Complexity with heap to find 'kth' element out of 'n' element - O(nlogk) 


--> STL LIBARAY inbuilt heaps - 
    1) Max Heap --> priority_queue<int> maxHeap;
    2) Min Heap --> priority_queue(int, vector<int>, greater<int>) minHeap ; 



*/

# include<iostream>
#include <bits/stdc++.h>
# include<unordered_map>
#include<vector>
using namespace std;


// 1. Implementation MINIMUM Priorty Queue
class PriorityQueue
{
private:
    vector<int> pq;
public:

    int getsize(){
        return pq.size();
    }
    
    bool isempty(){
        return pq.size()==0;
    }

    int getmin(){
        if (pq.size()==0)
        return 0;
        else
        return pq[0];
    }

    void insertdata(int data){
        pq.push_back(data);
        int child_idx = pq.size()-1;

        while (child_idx > 0)
        {
            int parent_idx = (child_idx-1)/2;
            if (pq[child_idx] < pq[parent_idx])
            {   //swap the values
                int temp = pq[parent_idx];
                pq[parent_idx] = pq[child_idx];
                pq[child_idx] = temp;
                child_idx = parent_idx;
            }
            else
            {
                break;
            }   
        }
        

    }

    void print_pq(){
        cout<<"\n";
        for (int i = 0; i < pq.size(); i++)
        {
            cout<<pq[i]<<" - ";
        }
        
    }

int removeMin(){ // i.e. removing the very first element of array or root element of CBT
    if (pq.size()==0){
        return 0;
    }

    int ans = pq[0];
    pq[0] = pq[pq.size()-1];
    pq.push_back(pq.size()-1);

    int p_idx = 0;
    int c1_idx = (2*p_idx) + 1;
    int c2_idx = (2*p_idx) + 2;
    int min_idx = 0;

    while (c1_idx < pq.size() and c2_idx < pq.size() )
    {
        if (pq[c1_idx] > pq[c2_idx]){
            min_idx = c2_idx;
        }
    }
    

    return ans;
}

} ;


// 2. Kth Smallest Element  --- complexity - O(nlogk)
/* If sorting applied Complexity becomes O(nlogn)*/
int kSmallElement(int a[],int size, int k){
    priority_queue<int> maxHeap;
    if(size==0)
        return -1;

    for (int i = 0; i < size; i++)
    {
        maxHeap.push(a[i]);
        if (maxHeap.size() > k)
            maxHeap.pop();
    }
    return maxHeap.top();
}


// 3. return K Largest Element --- complexity - O(nlogk)
vector<int> kLargestElement(int a[], int size, int k){
    priority_queue<int,vector<int>, greater<int>> minHeap;

    vector<int> result;
    
    if(size==0)
        return result;

    for (int i = 0; i < size; i++)
    {
      minHeap.push(a[i]);
      if(minHeap.size()>k)
        minHeap.pop();   
    }
    while (minHeap.size()!=0)
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
 }


// 4. Sort a K-SORTED array | Nearly sorted array
int kSortedArray(int a[], int size, int k){

    int flag=0;
    priority_queue<int,vector<int>, greater<int>> minHeap;

    for (int i = 0; i < size; i++)
    {
        minHeap.push(a[i]);
        if(minHeap.size()>k)
        {
            a[flag] = minHeap.top();
            minHeap.pop();
            flag++; 
        }
    }

    while (minHeap.size()!=0)
    {
        a[flag] = minHeap.top();
        minHeap.pop();
        flag++;
    }    
}
    

// 5. L CLOSEST number
/*  For given number fine the k nearest number - by considering absolute difference
    abs(number - each element),i In heap take pair wise input pair<int,int> --> <difference,number>
    in heap by default it sort according to the pair's first element */
vector<int> kClosestNumber(int a[], int size, int no, int k){
    priority_queue<pair<int,int>> pq;
    pair<int, int> p;
    for (int i = 0; i < size; i++)
    {
            p.first = a[i]-no;
            p.second = a[i];
        pq.push(p); // heap by default sort according ot 1st element of pair
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int> result;
    while (pq.size()!=0)
    {
        p = pq.top();
        pq.pop();
        result.push_back(p.second);
    }
    return result;
}




// 6. Top K Frequent Number
/*  First MAP has to be made to keep the occutrance of all the elements.
    Then take all the top k elements by palcing all the elements from map to heap
*/
vector<int> mostFrequentElement(int a[],int size, int k){

    unordered_map<int,int> mapCount; // map<key, value>
    for (int i = 0; i < size; i++)
        //as by deafult all the value of map for a key are imitalized to zero
        mapCount[a[i]] = mapCount[a[i]] + 1;

    // most asked --> min Heap req.
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    unordered_map<int,int>::iterator itr = mapCount.begin();
    // 'auto' keyworf can aslso be used as iterator--> auto i = mapCount.begin();
    // for(auto i=map.begin(), i<map.end(), i++)

    pair<int,int> p;
    while (itr!=mapCount.end())
    {
        p.first = itr->second;
        p.second = itr->first;
        minHeap.push(p);
        if(minHeap.size()>k){
            minHeap.pop();
        }
        itr++;
    }
    vector<int> result;
    while (minHeap.size()!=0)
    {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

 

 // 7. Frequeancy Sort
 /* Element sorted in descending order of their reptition count
    e.g.-> 9,9,9,9,9,1,1,1,8,8,2*/
 void frequencySort(int a[], int size){

     //map to count occu. of each key
     unordered_map<int,int> mapCount;
     for (int i = 0; i < size; i++)
         mapCount[a[i]] = mapCount[a[i]]+1;

    priority_queue<pair<int,int>> pq; // max heap 

    // max heap-- as we want max frequeany at top
    unordered_map<int,int>::iterator itr = mapCount.begin();
    while(itr!=mapCount.end())
     {
        pair<int,int> p;
        p.first = itr->second;
        p.second = itr->first;    
        pq.push(p); 
        itr++; 
     }

     int idx=0;
     
     while (pq.size()!=0)
     {
         pair<int,int> p;
         p = pq.top();
        int no = p.second;
        int times = p.first;
        for (int i = 0; i < times; i++)
        {
            a[idx] = no;
            idx++;
        }
        pq.pop();
        
     }  

 }



// 8. K Closest Point from ORIGIN
vector<pair<int,int>> closePointOrigin(pair<int,int> a[], int size, int k){
    // Max heap -- to remove the max distances -
    priority_queue<pair<int,int>> pq; 

    for (int i = 0; i < size; i++)
    {
            int x = a[i].first;
            int y = a[i].second;
            int distance = sqrt( (x*x) + (y*y) );//pow(x,2)
            
            pair<int,int> p;
            p.first = distance;
            p.second = i;
            pq.push(p);
            if (pq.size() > k)
                pq.pop();
    }

    vector<pair<int,int>> result;
    while(pq.size()!=0){
        
        pair<int,int> p = pq.top();
        result.push_back(make_pair(a[p.second].first,a[p.second].second));
        pq.pop();
    }
    return result;  

}




// 9. CONNECT ROPES TO MINIMIZE COST
int minimizeCost(int a[], int size){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < size; i++)
    {
        minHeap.push(a[i]);
    }

    int cost = 0;
    while (minHeap.size()!=1)
    {           
        //min to addition req.
        int a = minHeap.top();
        minHeap.pop(); // after pop again the heap reaarange with min element at top
        int b = minHeap.top();
        minHeap.pop();

        int sum = a+b;
        cost+=sum;
        minHeap.push(sum);
    }
    return cost;    
}







int main(){
    // PriorityQueue p;
    // p.insertdata(10);
    int a[] = {2,3,4,6};
    int size = sizeof(a)/sizeof(a[0]);
    // cout<<kSmallElement(a,size,1);  
    
    // vector<int> result = mostFrequentElement(a,size,2);
    
//     pair<int,int> arr[] = {make_pair(1,3),make_pair(2,2),make_pair(5,8),make_pair(0,11)};
//     int size= sizeof(arr)/sizeof(arr[0]);
//     vector<pair<int,int>> result = closePointOrigin(arr,size,2);

//  for (int i = 0; i < result.size(); i++)
//  {
//      cout<<result[i].first<<"  "<<result[i].second<<endl;
//  }
 cout<<minimizeCost(a,size);
 return 0;



}

