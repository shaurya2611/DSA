#include"binarytreenode.h"
# include<iostream>
using namespace std;

/*In BST all the operation Insert, delete and search are of - Complexity = O(height of tree) i.e. O(n)
  * BST are effectie only if the tree is balanced
  * for balanced tree -->  ( |heigth left subtree - height right sub tree| <= 1 )
  * Heigth of balanced BST = logn
  * For a balanced BST complexity  = O(logn) 
  * AVL trees are balanced BST
*/


class BST{

    private:
     binarytreenode<int>* root; // private variable

    public:
    BST(){
        root=NULL;
    }

    ~BST(){
        delete root;
    }

    // Searcing node in BST - 
    private:
    bool searchData(int data, binarytreenode<int>* node){

        if (node==NULL)
        return false;

        if (node->data==data){
            return true;
        }
        else if (node->data > data)
        {
            return searchData(data, node->left);
        }
        else if (node->data < data)
        {
            return searchData(data, node->right);
        } 
    }
    public:
    bool searchData(int data){
        return searchData(data, root);
    } //Complexity - O(heigth tree)



    //Inserting nide in BST - (same as searching)
    private:
    binarytreenode<int>* insertNode(int data, binarytreenode<int>* node){
        if (node==NULL){
            binarytreenode<int>* newNode = new binarytreenode<int>(data);
            return newNode;
        }

        if (data < node->data){ // if found below root -> join them with root's letfn
            node->left = insertNode(data, node->left);
            return node;
        }
        else if (data >= node->data)// if found below root -> join them with root's right
        {
            node->right = insertNode(data, node->right);
            return node;
        }

    }
    public:
    void insertNode(int data){
        this->root = insertNode(data, root);
    }//Complexity - O(heigth tree)



    //Deleting node in BST - 
    private:
    binarytreenode<int>* deleteData(int data, binarytreenode<int>* node){
        if (node==NULL){
            return NULL;
        }

        if (data < node->data){
            node->left = deleteData(data, node->left);
            return node;
        }
        else if (data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        //Node we want ot delete is the root node itself, with no nodes at its left and right - 
        else if(node->data==data  and  node->left==NULL and node->right==NULL){
            delete node;
            return NULL;
        }
        //If subtree exist on on side of Root node and nUL other side -
        else if (node->data==data and node->left==NULL)
        {
            binarytreenode<int>* temp = node->right;
            node = NULL;
            delete node;
            return temp;
        }
        else if (node->data==data and node->right==NULL)
        {
            binarytreenode<int>* temp = node->left;
            node=NULL;
            delete node;
            return temp;
        }
        
        //  (node->data==data and node->left!=NULL and node->right!=NULL)
        /* for this case find replacement - 
           either find maximun from left sub tree and replace that wit root node
           or find minimum from right sub tree and repalce woth root node     
       */
       else
       {
           //to find the minimum from from rigth sub tree in BST - 
           binarytreenode<int>* temp = node->right;
           while (temp->left!=NULL)
           {
               temp = temp->left;
           }
           int rightMin = temp->data;
           node->data = rightMin;
           //now delete the replaced min from rigth sub tree
           node->right = deleteData(rightMin, node->right);
           return node;
           
       }
       
    
        
        
        
        


    }
    public:
    void deleteData(int data){
        deleteData(data, root);
    }//Complexity - O(heigth tree)
};