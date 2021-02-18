# include<iostream>
# include<queue>
# include<algorithm>
# include "binarytreenode.h"
using namespace std;



/* ---------------------------------------BINARY TREE ------------------------------------------- */



// PRE ORDER TRAVERSAL - print root first then children 
// (root node - left - right)
void print_preorder(binarytreenode<int>* root){
    //Base case
    if (root==NULL)
    return ;

    //Recursion on both right and left part of tree
    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);

}



// POST ORDER TRAVERSAL - print childers first then nodes
// (left most - right - node)
void print_postorder(binarytreenode<int>* root){
    if(root==NULL)
    return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout<<root->data<<" ";
}




// INORDER TRAVERSAL - only in binary tree
// (left most - node - right)
void print_inorder(binarytreenode<int>* root){
    if (root==NULL)
    return;

    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}



// LEVEL ORDER TRAVERSAL  - print all from left to right in a level (using Queue)
// Also called BFS - breath first search
void print_levelorder(binarytreenode<int>* root){
    if (root ==NULL)
    return;

    queue<binarytreenode<int>*> pendingnodes;
    pendingnodes.push(root); 

    while (pendingnodes.size()!=0)
    {
        binarytreenode<int>* node = pendingnodes.front();
        pendingnodes.pop();
        cout<<node->data<<" : ";
        if(node->left !=NULL){
             pendingnodes.push(node->left);
             cout<<" L "<<node->left->data<<", ";
        }
          if(node->right !=NULL){
             pendingnodes.push(node->right);
             cout<<" R "<<node->right->data;
        }
        cout<<endl;
    }
    



}



// Fn to take input from user (leg wise usign recursion)- 
binarytreenode<int>* take_input(){
    cout<<"Enter data: ";
    int data;
    cin>>data;

    if(data==-1)
    return NULL;
    // by this process whole left tree and sub tree will be assigned first  then right from last
    binarytreenode<int>* node = new binarytreenode<int>(data);
    binarytreenode<int>* left_node = take_input();
    binarytreenode<int>* right_node = take_input();
    node->left = left_node;
    node->right = right_node;

    return node;
}



// Fn to take input LEVEL wise- (using QUEUE)
binarytreenode<int>* take_input_levelwise(){
    cout<<"Enter data of root : ";
    int data;
    cin>>data;
    if (data==-1)
    return NULL;
    
    queue<binarytreenode<int>*> pendingnodes;

    binarytreenode<int>* root = new binarytreenode<int>(data);
    pendingnodes.push(root);

    while (pendingnodes.size()!=0)
    {
        binarytreenode<int>* node = pendingnodes.front();
        pendingnodes.pop();
        cout<<"Enter Left node data of "<<node->data<<" : ";
        cin>>data;
        if (data!=-1){
            binarytreenode<int>* left_node = new binarytreenode<int>(data);
            pendingnodes.push(left_node);
            node->left = left_node;
        }
        cout<<"Enter Right node data of "<<node->data<<" : ";
        cin>>data;
        if (data!=-1){
            binarytreenode<int>* right_node = new binarytreenode<int>(data);
            pendingnodes.push(right_node);
            node->right = right_node;
        }
    }
    return root;    

}



// Count nodes in Binary Tree
int count_node(binarytreenode<int>* root){

    //base condition
    if (root==NULL)
    return 0;

    return 1 + count_node(root->left) + count_node(root->right);
}




// Fn to find height of binary tree- i.e = heigth of root node = max no of edges b/w root and leaf node.
int heigth_tree(binarytreenode<int> * root){
// height of root node can be find  as- max(left sub tree, right sub tree) + 1
    //base case
    if (root==NULL)
    return -1;

    //recursion
    int left_height = heigth_tree(root->left);
    int right_height = heigth_tree(root->right);
    
    // calculation -- do calculation considering the root node only
    return max(left_height , right_height) + 1 ;
}// Complexity - O(n)



// diameter of tree = max no edges between any two leave node.
int diameter_tree(binarytreenode<int>* root){
    if (root==NULL)
    return 0;

    int option_1 = heigth_tree(root->left) + heigth_tree(root->right)+ 2; // if diameter passes through root
    int option_2 = diameter_tree(root->left); // if diameter lies in left subtree
    int option_3 = diameter_tree(root->right); // if diameter lies in rigth sub tree
    return max(option_1 , max(option_2, option_3)); // return max of above
}// Complexity - O(n*height tree)



// Diameter of tree with better time cimplexity -  multiple return parameter i.e. height and dia same time
pair<int, int> diameter_2(binarytreenode<int>* root){
    //base case
    if (root==NULL){
        pair<int, int> p; // definig a pair template
        p.first = 0 ;//height
        p.second = 0;// diameter
        return p;
    }
 
    //Recursion hypothesis
    pair<int, int> left_ans  = diameter_2(root->left);
    pair<int, int> right_ans  = diameter_2(root->right);

    //Work on ROOT node only
    int left_dia = left_ans.second;
    int left_height = left_ans.first;
    int right_dia =  right_ans.second;
    int right_height = right_ans.first;

    int height = 1 + max(left_height, right_height);
    int diameter = max(left_height+right_height , max(left_dia, right_dia));
    pair<int , int> p;
    p.first = height;
    p.second = diameter;
    return p;
}// Complexity - O(n)




// Diameter of tree using the DP and from same height fn
/*This method also have complexity of O(n)
  This is same as finding the height , maxing extra calcualtions to find dia.
  DP - as result gettig passed and getting changed through call by refernce*/
int diameter_3(binarytreenode<int>* root, int* result){//result variable by call by refernce as FINAL ANS
    //base case
    if (root==NULL){
        return 0;
    }

    //hypothesis for calculating the height --
    int d_left = diameter_3(root->left,result);
    int d_right = diameter_3(root->right, result);

    // Calculations for root node
    int height = 1 + max(d_left,d_right); //calculating height
    int diameter = 1 + d_left + d_right;
    *result = max( *result , max(height,diameter)); //final answer getting changed in result variable by call by refernce

    return height; // this return is for recursive funtion call

}




// MAX PATH SUM from any node to any node
//Same as finding diameter by applying Dp
int maxSumAny(binarytreenode<int>* root, int* result){//result variable by call by refernce as FINAL ANS
    //base case
    if (root==NULL){
        return 0;
    }

    //hypothesis for calculating the height --
    int d_left = maxSumAny(root->left,result);
    int d_right = maxSumAny(root->right, result);

    // Calculations for root node
    int height = max(root->data , root->data + max(d_left,d_right)); //calculating height
    int diameter = root->data + d_left + d_right;
    *result = max( *result , max(height,diameter)); //final answer getting changed in result variable by call by refernce

    return height; // this return is for recursive funtion call

}




// MAX PATH SUM from leaf node to leaf node
//Same as finding diameter by applying Dp
int maxSumLeaf(binarytreenode<int>* root, int* result){//result variable by call by refernce as FINAL ANS
    //base case
    if (root==NULL){
        return 0;
    }

    //hypothesis for calculating the height --
    int d_left = maxSumLeaf(root->left,result);
    int d_right = maxSumLeaf(root->right, result);

    // Calculations for root node
    int temp = root->data + max(d_left,d_right); //calculating height
    int ans = root->data + d_left + d_right;
    *result = max( *result , max(temp,ans)); //final answer getting changed in result variable by call by refernce

    return temp; // this return is for recursive funtion call

}


// To get the maximum number from the binary tree - 
int maximum(binarytreenode<int>* root){
    // base case
    if (root==NULL)
    return INT8_MIN;

    // recursion ypothesis
    int max_lefttree = maximum(root->left); 
    int max_righttree = maximum(root->right) ;


    // Work on root node
    return max(root->data , max(max_lefttree, max_righttree));  
} // Complexity - O(n)



// To get the minimum number from the binary tree - 
int minimum(binarytreenode<int>* root){
    //base case
    if (root==NULL)
    return INT8_MAX;

    //Recursion hypothesis
    int min_lefttree = minimum(root->left);
    int min_righttree = minimum(root->right);

    //Work on first Node
    return min(root->data , min(min_lefttree,min_righttree));
} // Complexity - O(n)





 
/* -----------------------------------BINARY SEARCH TREE (BST)----------------------------------- */



// Check given tree is BST 
/* {max of left subtree} > Root Data <= {min of rigth sub tree} & left and right subtree are also BST*/
bool bst_check(binarytreenode<int>* root){
    if (root == NULL)
    return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (leftMax < root->data) && (root->data <= rightMin) && (bst_check(root->left)) && (bst_check(root->right));

    return output;
} // Complexity - O(n*heighttree) i.e O(nlogn) or O(n*n) -- same as diameter problem
/*Reason for poor time complexity is saemas of diameter calculation priblem - 
  Every node is visited twice for the bst_check - 
  1st time for maximum() calculation
  2nd time for bst_check() recurssion
  3rd time for minimum() calculation*/

/*Solving the above problem- 
  Calculating the maximum , minimum , isbst same time and returning them at a time*/
class bstoutput{
    public:
    bool isbst;
    int minimum;
    int maximum;
};
// We have two retunr 3 things from the function - 
bstoutput bst_check_2(binarytreenode<int>* root){

    // base case
    if (root==NULL){
        bstoutput op;
        op.isbst = true;
        op.minimum = INT8_MAX;
        op.maximum = INT8_MIN;
        return op;
    }

    //Recursion Hypothesis 
    bstoutput left_tree_op = bst_check_2(root->left);
    bstoutput right_tree_op = bst_check_2(root->right);
    int minimum = min(root->data, min(left_tree_op.minimum , right_tree_op.minimum));
    int maximun = max(root->data , max(left_tree_op.maximum , right_tree_op.maximum));
    
    bool result = (root->data  > minimum) && (root->data <= maximun) && (left_tree_op.isbst) && (right_tree_op.isbst) ; 

    bstoutput op;
    op.isbst = result;
    op.maximum = maximun;
    op.minimum = minimum;

    return op;
}

// Using constraints passing method checking is a tree BST --
bool bst_check_3(binarytreenode<int>* root, int min_val=INT8_MIN, int max_val=INT8_MAX){
    if (root==NULL)
    return true;

    if (root->data < min_val || root->data >max_val){
        return false;
    }

    bool leftOk = bst_check_3(root->left , min_val , root->data-1);
    bool rightOk = bst_check_3(root->right , root->data, max_val );

    return (leftOk && rightOk);



    // int data = root->data; left (root->left , min_value ,max_val = root.data )


}






//Searching element is BST
binarytreenode<int>* search_bst(binarytreenode<int>* root, int data){

    if (root==NULL or root->data==data){
        return root;
    }

    if (root->data < data){
        search_bst(root->right, data);
    }
    else{
        search_bst(root->left, data);
    }
}





// Fnto get a unqiue tree from pre-order and in-order traversal - {REVIEW}
binarytreenode<int>* build_tree_helper(int* ino, int* preo, int ins,int ine,int pres,int pree){

//base case - 
if (ins > ine)
return NULL; 

int data = preo[pres];

int rootidx = -1;
for ( int i=ins; i <=ine; i++)
{
    if (ino[i]==data)
    {
        rootidx = i;
        break;
    }

}


int lins = ins;
int line = rootidx-1;
int lpres = 1+pres;
// using -> line - lins = lpree - lpres
int lpree = line -lins + lpres;
int rins = rootidx+1;
int rine = ine;
int rpres = lpree+1;
int rpree = pree;
binarytreenode<int>* root = new binarytreenode<int>(data);
root->left  = build_tree_helper(ino,preo,lins, line, lpres, pree);
root->right = build_tree_helper(ino,preo,rins, rine, rpres, rpree); 
return root ;
}
binarytreenode<int>* build_tree(int* ino , int* preo, int size){
    return build_tree_helper( ino , preo, 0,size-1,0,size-1);
}




// Print element in given range of BST
void print_range(binarytreenode<int>* root, int k1, int k2){
    if (root==NULL)
        return;
    
    if ( k1 < root->data )  
        print_range(root->left, k1, k2);  
      
    /* if root's data lies in range,  
    then prints root's data */
    if ( k1 <= root->data && k2 >= root->data )  
        cout<<root->data<<" ";  
      
    /* If root->data is smaller than k2, 
        then only we can get o/p keys  
        in right subtree */
    if ( k2 > root->data )  
        print_range(root->right, k1, k2);  
}




// To convert sorted array into BST
binarytreenode<int>* arrayBST(int arr[] , int startIndx, int endIndx){
    
    //base case
    if (startIndx > endIndx)
    return NULL;

    int mid_idx = (endIndx + startIndx)/2;
    binarytreenode<int>* root = new binarytreenode<int>(arr[mid_idx]);

    root->left = arrayBST(arr , startIndx, mid_idx-1 );
    root->right = arrayBST(arr, mid_idx+1 , endIndx);

    return root;
}





// ""Conevrting BST into SLL"""
void BSTtoSLL(binarytreenode<int>* root, binarytreenode<int>** head){
if (root==NULL)
return;

static binarytreenode<int>* tail = NULL;

BSTtoSLL(root->left , head);

if (head==NULL){
    *head = root;
    tail  = root;
}
else
{                                             
    tail->right = root;
    tail = root;
}                                       

BSTtoSLL(root->right, head);

}

 



// Converting BST to DLL
void BSTtoDLL(binarytreenode<int>* root , binarytreenode<int>** head){
    if(root==NULL)
    return;

    static binarytreenode<int>* prev = NULL; // static variables have only single copy of var. for entire recursion call
    // This statement will be called once only during first function call, other calls will share same copy.

    BSTtoDLL(root->left , head);

    if (prev==NULL){
        *head = root;
    }
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root; // updating prev

    BSTtoDLL(root->right, head);
}




//Root to node path in binary tree--
//Element has to searched at root, left tree and rifht sub tree else return nULL
vector<int>* rootToPath(binarytreenode<int>* root, int target){
    
    //base case
    if (root==NULL)
        return NULL;
    
    //First search for element at the root, if found retunr the vector
    if (root->data==target){
        vector<int>* n = new vector<int>();
        n->push_back(root->data);
        return n;
    }

    //1st search for element in left sub tree - if got add to vector and return, if NOT found then go to right
    vector<int>* leftTree = rootToPath(root->left, target);
    if (leftTree!=NULL){
        leftTree->push_back(root->data);
        return leftTree;
    }

    // search for element in right - if got add to vector else return null element NOT found.
    vector<int>* rightTree = rootToPath(root->right, target);
    if (rightTree!=NULL){
        rightTree->push_back(root->data);
        return rightTree;
    }
    else{
        return NULL;
    }

}




int main(){
    // Binary tree - 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
    // Binary dearch tree - 40 20 60 10 30 50 70 5 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    //  int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // binarytreenode<int>* root = arrayBST(arr,0,9);
    // binarytreenode<int>* root = build_tree(ino ,preo,9);
    binarytreenode<int>* root = take_input_levelwise();
    cout<<endl<<"------LEVEL order traversal-------";
    print_levelorder(root);
    // cout<<endl<<"------Postorder traversal-------";
    // print_postorder(root);
    // cout<<endl<<"------Preorder traversal-------";
    // print_preorder(root);
   
    cout<<endl<<"------Inorder traversal-------";
    print_inorder(root);
    cout<<endl<<"Height tree : "<<heigth_tree(root);
    cout<<endl<<"Diameter tree : "<<diameter_tree(root);
    cout<<endl<<"Minimum element in tree : "<<minimum(root);
    cout<<endl<<"Maximum element in tree : "<<maximum(root);
    cout<<endl<<"Entered tree is BST : "<<bst_check(root);
    // vector<int>* nodepath = rootToPath(root, 9);
    // cout<<"\n"<<" Root to Node - 9 : ";
    // for (int i = 0; i < nodepath->size(); i++)
    // {
    //     cout<<nodepath->at(i)<<" ";
    // }
    cout<<"\n"<<"BST to SLL -- ";
    binarytreenode<int>* head = NULL;
    BSTtoSLL(root, &head);
    binarytreenode<int>* temp = head;
    while (temp!=NULL){
        cout<<temp->data;
        temp=temp->right;
    }
    delete root;
    return 0;

}