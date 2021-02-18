#include<iostream>
using namespace std;
#include<vector>
# include<string>
# include<stack>
# include<unordered_map>
# include<map>
# include<iterator>

//2D array - 


void sam(string *s){
    (*s) = (*s) +" singh";
}

string sam2(string s){
    (s) = (s) +" singh";
    return s;
}

void sam4(string s){
    s = s + "subham";
}
// int sam2(int a[]){
//     a[2] = 100;
//     return a;
// }

void sam3(int a[]){
    a[2] = 100;
}


void array2D(int *a){

}

int main(){

        map<int,int> m;
        // m[1] = 10;
        // m[6] = 60;
        // m[3] = 30;
        // m[1] = 100;
        m.insert(pair<int,int>(1,10));
        m.insert(pair<int,int>(6,60));
        m.insert(pair<int,int>(3,30));
        m.insert(pair<int,int>(1,100));

        // map<int,int> :: iterator itr;
        // itr = m.begin();
        // while (itr!=m.end())
        // {
        //     cout<<itr->first<<" --> "<<itr->second<<endl;
        //     itr++;
        // }
    // string s = "shaurya";
    // cout<<s<<endl;
    // sam(&s);
    // cout<<s<<endl;
    // string s2 = sam2(s);
    // cout<<s2<<endl;
    // sam4(s);
    // cout<<s;
    // int a[] = {1,2,3,4,5,6};
    // int size = sizeof(a)/sizeof(a[0]);
    
    // sam3(a);
    


    // for (int i = 0; i < size; i++)
    //     cout<<a[i]<<" -> ";
    // cout<<endl;
    // int z = 10;
    // string x = "found at " + to_string(z);
    // cout<<endl<<" ----"<<endl<<z;
    // cout<<x;
    char a = NULL;
    int b = 19;
    cout<<a<<endl<<b<<endl;
    if (a==NULL)    
    {
        cout<<"Yes";
    }
    
    return 0;
}