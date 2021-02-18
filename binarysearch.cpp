# include<iostream>
# include<vector>
# include<string>
# include<cmath>
using namespace std;


/*------------------ If an array is sorted given - HINT given to use the BINAEY SEARCH logic any how------------------------*/


// 1. BINARY SEARCH in sorted array --O(logn)
int binarySearch(int a[],int size,int no){
    int start = 0;
    int end = size-1;

    while(start<=end){
        int mid = start + (end - start)/2; // to prevent int overflow --> start + (end-start)/2
        if (a[mid]==no)
            return mid;
        if (a[mid] > no)
            end = mid-1;
        else
            start = mid+1;        
    }
    return -1;
}


// 1.1 BINARY SEARCH using RECURSION
int binarySearchRecursion(int a[], int start, int end, int no){
    if (start<=end)
    {
        int mid = start +(end-start)/2; // -- same as ---(start+end)/2

        if(a[mid]==no)
            return mid;
        else if (no < a[mid])
            return binarySearchRecursion(a,start,mid-1,no);
        else
            return binarySearchRecursion(a,mid+1,end,no);
    }
    else
        return -1;
}


// 2. FIRST OCCURANCE of a no in sorted array--
int firstOcc(int a[], int size, int no){
      int start = 0;
    int end = size-1;
    int occ = -1;

    while(start<=end){
        int mid = start + (end - start)/2; // to prevent int overflow --> start + (end-start)/2
        if (a[mid]==no){
            occ =  mid;
            end = mid-1;}
        else if (a[mid] > no)
            end = mid-1;
        else
            start = mid+1;        
    }
    return occ;
}


// 3. LAST OCCURANCE of a no in sorted array--
int lastOcc(int a[], int size, int no){
      int start = 0;
    int end = size-1;
    int occ = -1;

    while(start<=end){
        int mid = start + (end - start)/2; // to prevent int overflow --> start + (end-start)/2
        if (a[mid]==no){
            occ =  mid;
            start = mid+1;}
        else if (a[mid] > no)
            end = mid-1;
        else
            start = mid+1;        
    }
    return occ;
}


// 4. NO OF OCCURANCE of a no in sorted array--
int noOfOcc(int a[],int size, int no){
 return lastOcc(a,size,no) - firstOcc(a,size,no) +1;
}


// 5. NO OF TIMES SORTED ARRAY ROTATED CLOCKWISE -- {15, 18, 2, 3, 6, 12}
/* Main concept - Find min element and return its index;
    if mid is smallest --> mid < mid-1
    If no mid-1 element present i.e. already soreted no such element present
    else Find mid and move it towards the unsorted array*/
int noOfRotation(int a[], int size){
    int start = 0;
    int end = size-1;

    while (start<=end)
    {
        if(start==end)
            return start;

        int mid = start + (end - start)/2;

        //If mid element is minimum element
        if (start<mid and a[mid]<a[mid-1])
            return mid;

        //If mid+1 is the minimum element
        if(mid<end and a[mid]>a[mid+1])
            return mid+1;
        
        //move towards unsorted array section
        if (a[mid]<=a[start]) // i.e. array is  
            end = mid - 1;
        else //(a[mid]>=a[start])
            start = mid+1;        
    }
    return 0;

    }


// 6. SEARCHING ELEMENT in ROTATED ARRAY
int searchRoated(int a[],int size,int no){

    int midIndx = noOfRotation(a,size);

    if(no==a[midIndx])
        return midIndx;
    else if (no > a[midIndx])
        return max(binarySearchRecursion(a,0,midIndx-1,no),binarySearchRecursion(a,midIndx+1,size-1,no));
    else //(no < a[midIndx])
        return -1;
    
}


// 7. SEARCHING IN NEARLY SORTED ARRAY
/* Nearly sorted i.e. element can present in a[i], a[i+1] or a[i-1] position*/
int nearlySorted(int a[], int size, int no){
    int start = 0;
    int end = size-1;
    while (start<=end)
    {
        int mid = start + (end-start)/2;

        if (a[mid]==no)
            return mid;
        else if (start<mid and a[mid-1]==no)
            return mid-1;
        else if (mid<end and a[mid+1]==no)
            return mid+1;
        else{
            if(no > a[mid])
                start = mid+1;
            else 
                end = mid-1; 
        } 
    }
    return -1; // if not found
}


// 8. FLOOR OF ELEMENT 
/* For the given input, find that no and return it, if not found then return gratest number smaller then given no
   same as binary ssearch only diff --> when (a[mid] < no) store mid as result and return it.*/
int floorElement(int a[], int size, int no){
    int start = 0;
    int end = size-1;
    int floor = -1;

    while (start<=end)
    {
        int mid = start + (end - start)/2;
        
        if (a[mid]==no)
            return a[mid];
        else if (a[mid] > no)
            end = mid-1;
        else{
            floor = a[mid];
            start = mid+1; }    
    }
    return floor;
}



// 9. CEIL oF ELEMENT
/* For a given no - find the smallest noo greater then the given no*/
int ceilElement(int a[], int size, int no){
    int start = 0;
    int end = size-1;
    int floor = -1;

    while (start<=end)
    {
        int mid = start + (end - start)/2;
        
        if (a[mid]==no)
            return a[mid];
        else if (a[mid] > no){
             floor = a[mid];
            end = mid-1;}
        else{
            start = mid+1; }    
    }
    return floor;
}


// 10. NEXT ALBHABET ELEMENT
/* Fora given input Alphabet, find the albhabat in the array just greater then the given input
    Same as CEIL function*/
char nextAlpha(char a[], int size, char no){
    int start = 0;
    int end = size-1;
    char floor = '#' ;

    while (start<=end)
    {
        int mid = start + (end - start)/2;
        
        if (a[mid]==no and mid<end)
            return a[mid+1];
        else if (a[mid] > no){
             floor = a[mid];
            end = mid-1;}
        else{
            start = mid+1; }    
    }
    return floor;
}


// 11. POSITION ELEMENT in "INFINITLY length" SORTED ARRAY
/*  Infinite length array -- i.e. size array unknown
    Ques apprcoh same as FINDING LENGHT OF LINKED LIST*/
int posInfiniteArray(int a[],int no){
    int start = 0;
    int end = 1;

    while (a[end] < no)
    {
        start = start+1;
        end = end*2;
    }
    return binarySearchRecursion(a,start,end,no);
}


// 12. Minimum ABOSLITE Difference Element in a Sorted Array
/* In Binary Search when no is not found the 'START' and 'END' both variables gives position of neighbours of given number
    Find the no at boht position and among them find absolute and return min.*/
int minAbsoluteDiff(int a[], int size, int no){
    
    int start = 0;
    int end = size-1;
    
    while(start<=end){
        int mid = start + (end - start)/2; // to prevent int overflow --> start + (end-start)/2
        if (a[mid]==no)
            return 0;
        if (a[mid] > no)
            end = mid-1;
        else
            start = mid+1;        
    }
    return min(abs(no - a[start]) , abs(no - a[end]));
    
}


// 13. PEAK ELEMENT / MAXIMUM ELEMENT IN BIOTONIC ARRAY
/* PEAK element is NOT SMALLER then its both neighbour elemets i.e ....3,3,3.... --> 3 is also peak element (not smaller)
   More then one peak element may present in array - return any one of them
   For corner elements check only one neighbour
   If array sorted last element peak element
   If al elemets of input same each element peak ele.
   BIOTONIC ARRAY - first element in monotonicaly increasing then decreasing form a peak
   */
int peakElement(int a[], int size){

    int start = 0;
    int end = start-1;

    while (start<=end)
    {
        int mid = start + (end - start)/2;

        if(mid>0 && mid <size-1) // for cases except edge one
        { 
            if (a[mid]>a[mid+1] && a[mid]>a[mid-1])
                return mid;
            else if (a[mid] < a[mid+1])
                start = mid + 1;
            else //(a[mid-1] > a[mid])
                end = mid - 1;
                }
        
        else{ // for boundary cases
            if(mid==0 ){
                if(a[0]> a[1])
                    return 0;
                else
                    return 1;}

            if(mid==size-1){
                if( a[mid]>a[mid-1])
                    return size-1;
                else
                    return size-2;
            }
        }
            

    }
    
}



// 14. SEARCHING IN COULMN & ROW WISE SORTED 2D ARRAY -- complexity O(r + c)
/*  Since array is sorted both row and column wise syart from the top right element
    For each coparisonwe have 2 choices either left side or downward side*/
string search2DSortedArray(int a[4][4], int no){
    int r=0 ; int c=3;

    while (r>=0 and c>=0)
    {
        int comp = a[r][c];

        if (comp==no){
            string s = "Found at " + to_string(r+1) + " row " + to_string(c+1)+" column"; 
            return  s;}
        else if (no < comp)
            c--;
        else // no > comp;
            r++;
    }
    return "Not Found";
}


// 15. ALLOCATE NO OF PAGES ----- (REVIEW IT)
/*  Prob - To Minimize the maximimum no pages a student has to read
    Books pages given in ascending order, and no of students given.(not necessary array is sorted)
    Divide the books/pages to students in continuous manner with atleast one book to each student 
    and use all the available books such that ..(prob statemeng)
    
    SOLITION - Apply BS on maximum no of pages statring from max of array to sum of array*/
    bool isValid(int a[],int size,int student, int midMax){ 
        int flag = 1;
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum+=a[i];
            if (sum > midMax)
            {
                flag++;
                sum = a[i];
            }
            if(flag>student){
                return false;}
        }
        if(flag==student)
            return true;
        else
            return false;
    }
int pagesAllocate(int pages[], int size, int student){
    
    if(student > size)
        return -1;
    
    int start = INT16_MIN;  // START of binary search - max pages can be allocated to a student - max of array
    int end = 0; // END of binary search -- sum of aal the available pages - sum of array
    for (int i = 0; i<size; i++)
    {
        start = max(start,pages[i]);
        end+= pages[i];
    }

    int result = -1;
    while (start<=end)
    {
        int mid = start + (end - start)/2; //pages[mid] = max no pages per student

        if (isValid(pages,size,student,mid))//partiotn scheme is possible 
            {
                result = mid;
                end = mid-1; // partion possible now try to minimize the max
            }
        else
            start = mid+1;
    }
    return result;    
}




int main(){
    int a[] = {12, 34, 67, 90};

    int size = sizeof(a)/sizeof(a[0]);
    
    cout<<pagesAllocate(a,size,2)<<endl;
    // cout<<pagesAllocate(a,size,1)<<endl;
  
 

    return 0;
}