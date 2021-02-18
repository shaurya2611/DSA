# include<iostream>
# include<unordered_map>
# include<string>
# include<vector>
using namespace std;


/*  Map is asame as dictionary in python,
    MAP are of two types
    1) ORDERED MAP - keys will be arranged in increasing orders
                     implemented using BST , O(logn) oprations
                     Decleation - map<int,int> m;

    2) UNORDERED MAP - Keys are randomly arranged in saem order as insertion
                       implemented using HASH FUNCTION(hash table) , O(1) operations
                       Decleation - unordered_map<int,int> m;


    e.g.--
        Inserting Duplicate KEYs - 
        * USing square bracket notation "map[key] = value" - allows insertion of duplicate keys and the duplicate key last inserted in stored
        * Using the "map.insert(pair<int,int>(key,value))" duplicate key not inserted, and first inserted key is stored.

            map.count('key') --> it give output as '0' if key not present and '1' if key present in map.
            map.begin()  --> gives the starting address of the map first element
            map.end()    --> address after the last element
            map.erase('key')
            map.erase(iterator_from, iterator_to)

 

Itesrators - use for the traversal. Following DS have iterators --
  vector, list, map, unorderd map, set(same as unordered map with key only) , unordered set
*/

// 1. Fn to take an Array and return vector of unqiue elements only in order - 
vector<int> dublicateRemove(int arr[], int size){
    unordered_map<int,int> map ;
    vector<int> op;

    for (int i=0; i<size; i++){
        if (map.count(arr[i])<1){
            map[arr[i]]=1;
            op.push_back(arr[i]);
        }
    }
    return op;
}




/* 2. TWO SUM PROBLEM -- complexity from O(n^2) to O(n) using MAPS
   Given an array and target no, fing the two no whose sum equals target sum*/
vector<int> targetSum(int a[],int size, int target){

    unordered_map<int,int> mp;
    vector<int> result;
    for (int i = 0; i < size; i++)
    {
        int diff = target - a[i];
        if (mp.find(diff)!=mp.end())
        {   
            result.push_back(i);
            result.push_back(mp.find(diff)->second);
            break;
        }
        else
            mp[a[i]] = i;   
    }
    return result;
}





int main(){

int a[] = {2,6,5,8,11};
int size = sizeof(a)/sizeof(a[0]);
vector<int> result = targetSum(a,size,14);
for (int i = 0; i < result.size(); i++)
{
    cout<<result[i]<<"  ";
}


return 0;


}