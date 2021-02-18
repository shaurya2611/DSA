using namespace std;
template<typename T>

class binarytreenode
{

public:

    //Public Variables
    T data;
    binarytreenode* right=NULL;
    binarytreenode* left=NULL;

    //Constructor
    binarytreenode(T data){
        this->data = data;
    }

    //Destructor
    ~binarytreenode(){
        delete left;
        delete right;
    }

};


