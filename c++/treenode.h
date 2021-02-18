using namespace std;
# include<vector>
template <typename T> // defining an template

class treenode // as every node of tree contacins a data, and address of child nodes
{
 public:   
    T data;
    vector<treenode<T>*> children;//vec used as a node can have any number of children

   treenode(T data){ //contructor ti sotre the data while creating node
     this->data = data;
 }

};

 
