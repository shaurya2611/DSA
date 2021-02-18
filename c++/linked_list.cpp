# include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
//constructor
Node(int data) {
    this->data = data;
    next = NULL;
}
};

// Fn to print the linked list - 
void print_list(Node*head){
    Node* temp = head;
    cout<<endl;
    while (temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL";
}

// Fn to enter nodes in linked list - 
Node* add_node(){ 
    /*
    using tail variable complexity for entring n nodes --> o(n) 
    Using the while loop complexity for entring n nodes --> 0(n^2)
    */
    int data;
    cin>>data;
    Node*head = NULL;
    Node*tail = NULL;
    while(data!=-1){
        Node * newnode =  new Node(data);//dynamic allocation
        if (head==NULL){
            head = newnode;
            tail = head; }
        else
        {
        tail->next =newnode;
        tail = tail->next;
        }
        cin>>data;
    }
    return head;
}

// Fn to insert node at given position - 
Node* insert_node(Node* head, int pos, int data){
    // base cond
    if (head==NULL)
     return head;

    // Calculation on 1st(pos=0) node rest by recursion
    if (pos==0){
        Node* newnode = new Node(data);
        newnode->next = head;
        return newnode;
    }
    // Recursion part on (2->nth node)
    Node * temp_head = insert_node(head->next , pos-1, data);
    // Since recursion worked on 2-nth node joining it with 1st node
    head->next = temp_head;
    return head;
}

// Fn to delete node recursively - 
Node * delete_node(Node*head , int pos){
    if (head==NULL){
        return head;
    }

    if (pos==0)
    {
        head = head->next;
        return head;
    }

    Node * temp_head = delete_node(head->next, pos-1);
    head->next = temp_head;
    return head;
}


// Fn to return the mid element of list without finding length of linked list -
Node* mid_element(Node* head){
    Node*slow = head;
    Node*fast = head;
    if (head!=NULL){
    while(fast!=NULL and fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; 
    }  
}


//Fn to merge two sorted linkedlist - (Itiritatively)
Node* merge_sorted_list(Node*h1 , Node*h2){
    if (h1==NULL)
    return h2;

    if (h2==NULL)
    return h1;

    Node* first_node = new Node(0);
    Node* ptr = first_node;
    while (h1!=NULL and h2!=NULL)
    {
        if (h1->data < h2->data){
            ptr->next = h1;
            h1 = h1->next;
            ptr = ptr->next;
        }
        else{
            ptr->next = h2;
            h2= h2->next;
            ptr = ptr->next;
        }
    }
    if (h1!=NULL)
        ptr->next=h1;
    if (h2!=NULL)
        ptr->next=h2;

    return first_node->next;
}


//Fn to merge two sorted array - (Recursively)
Node* mergeRecursive(Node* h1, Node* h2){
    if (h1==NULL)
        return h2;

    if(h2==NULL)
        return h1;

    //Comare the elements return the smaller one
    if (h1->data <= h2->data)
    {
        h1->next = mergeRecursive(h1->next ,h2);
        return h1;
    }
    else
    {
        h2->next = mergeRecursive(h1, h2->next);
        return h2;
    }    
}


//MERGE SORT the LINKED LIST
Node* mergeSortList(Node* h){
    if (h==NULL or h->next==NULL)
        return h;

    Node * middle = mid_element(h);
    Node * middle_next = middle->next;
    middle->next=NULL;//Making first linked list tail as NULL

    Node * first = mergeSortList(h);
    Node * second = mergeSortList(middle_next);
    Node * sorted = mergeRecursive(first,second);
    return sorted;
   
}


// Fn to REVERSE linked list - O(n) approch- 
Node* reverse_list(Node*head){

    if (head==NULL or head->next==NULL){
        return head;
    }

    Node * temp_head = reverse_list(head->next);

    Node* tail = head->next;
    tail->next = head;
    head->next = NULL;

    return temp_head;
}


int main(){

   Node *h1 = add_node();
//    Node *h2 = add_node();
   cout<<endl;
   print_list(h1);
   cout<<endl;
//    print_list(h2);
//    cout<<endl;
    Node * mid = mergeSortList(h1);
    // cout<<endl<<"Mid element : "<<mid->data;
    print_list(mid);
   return 0;
} 
/*

12
56
54
45
10
78
3
-1
*/