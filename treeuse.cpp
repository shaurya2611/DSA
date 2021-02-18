# include<iostream>
# include<queue>
# include "treenode.h"
using namespace std;

// fn to print tree
void print_tree(treenode<int>* root){
        
    /* EDGE CASE not base case (bcz base case is visited once during recursion, tis is edge case as 
    if tree us there never this condn will be hit.)*/
    if (root==NULL){
        return;
    }

    // BAse case -  Generally no base case in generic tress as it is handled by for loops.

     // Calcualtions for first node only
     // assume a singl enode as  -- [[data][an vector of adresses]]
     cout<<root->data<<" : ";
     for(int i=0;i<root->children.size();i++){
         cout<<root->children[i]->data<<" , ";
     } 
     cout<<endl;

     // Recursive call
     for(int i=0;i<root->children.size();i++){
         print_tree(root->children[i]);
     }

}

// fn to take input in tree 
treenode<int>* take_input(){

    // Calculation part - doing for the first node
    int data;
    cout<<"Enter data : ";
    cin>>data;
    treenode<int>* root =  new treenode<int>(data);
    int n;
    cout<<endl<<"No of childeren of "<<data<<" : ";
    cin>>n;

    // Recursion assumning after calling this all n-1 node done
    for (int i = 0; i< n; i++)
    {
       treenode<int>* child_node = take_input();
       root->children.push_back(child_node);  
    }
    
    return root;

}

// fn to take LEVEL WISE tree input (using Queue DS )
treenode<int>* take_input_levelwise(){
    int data;
    cout<<"Enter root data :";
    cin>>data;
    treenode<int>* root = new treenode<int>(data);

    queue<treenode<int>*> pendingnodes;//declaring a queue
    pendingnodes.push(root);

    while (pendingnodes.size()!=0){
        treenode<int>* node = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Number of Childeren for "<<node->data<<" : ";
        int num;
        cin>>num;
        for (int i = 0; i < num; i++)
        {
            cout<<"Enter "<<(i+1)<<" chid of "<<node->data<<" : ";
            int data;
            cin>>data;
            treenode<int>* child = new treenode<int>(data);
            node->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}


// Fn to print tree Level Wise ()using Queue
void print_levelwise(treenode<int>* root){
    if (root==NULL)
    return;

    queue<treenode<int>*> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size()!=0)
    {
        treenode<int>* node = pendingnodes.front();
        pendingnodes.pop();
        int num = node->children.size();
        cout<<node->data<<" : ";
        for (int i = 0; i < num; i++)
        {
            cout<<node->children[i]->data<<" , ";
            pendingnodes.push(node->children[i]);
        }
        cout<<endl;
    }
}


// Fn to find the size of Tree
int size_tree(treenode<int>* root){
    int ans=1;    
    for (int i = 0; i <root->children.size(); i++)
    {
        ans+= size_tree(root->children[i]);
    } 
    return ans;    
}


int main(){
    treenode<int> *root = take_input_levelwise();
    print_levelwise(root);
    int len = size_tree(root);
    cout<<endl<<len;
    return 0;
}