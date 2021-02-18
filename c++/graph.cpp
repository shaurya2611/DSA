/*
    ------------------------------------------------------ GRAPHS ------------------------------------------------------------

A graph is a data structure that consists of the following two components:
    * A finite set of vertices also called as nodes.
    * A finite set of ordered pair of the form (u, v) called as edge. 

* Tree is a special kind of graph which is acyclic and connected graph.
  tree is a graph with minimum no of edges to form a connected graph i.e. (n-1) edges
* Path - Collection of edges to reach from one point to another
* Degree - No of edges passing in or out from the node/vertex
* Connected Graph - If for every two vertices there is path(direct or indirect) between them
* Complete Graph - Every vertex has a connection with every other vertex

The following two are the most commonly used representations of a graph.
    1. Adjacency Matrix - 
        Space complexiyt   O(n^2)
        Additing new edge  O(1)
        Checking edge -    O(1)
        Removing edge -    O(1)
        Adding new node -  O(n^2)  (copy from old matrix to new then add)
        Finding neighbours i.e. directly connected nodes - O(n) see entire row.

  
    2. Adjacency List - (or By using map in case of string vertices)
        Space complexity  O(vertex + edges)
        Adding new edge - O(1)  (added at starting of head)
        Checking edge -   O(n) ...(worst case)
        Removing edge -   O(n)
        Adding new node - O(1) ...(dynamically size can be increased)

There are other representations also like, Incidence Matrix and Incidence List. The choice of graph representation 
is situation-specific. It totally depends on the type of operations to be performed and ease of use

Dense Graph -> Edges approx equal to Vertex Square  (ADJACENCY MATRIX rep. used)
Sparse Graph -> Edges approx equals Vertex  (ADJACENCY LIST rep. used)


TYPES OF GRAPH TRAVERSAL --
* Breath First Search (BFS) - Iterartive way
    Same as level order traversal in tree using QUEUE
    Start from source - > then go to neighbours
* Dept First Seacrh(DFS) - Recursive

*/



# include <iostream>
# include <stdlib.h>
using namespace std;
# include <vector>
# include<list> //same as pyton lists=.
#include<unordered_map>

class AdjListGraph // Biderectional Graph implementation using the linked list(list of list concept)
{
    int v; //no of vertices in graph by user.
    list<int> *l; //pointer to array of list

    public :
        AdjListGraph(int v){ // constructor to take no of nodes from user
            this->v = v;
            l = new list<int>[v]; // arrays of list of size = no of nodes
        }

        void addEdge(int fromNode, int toNode){
            l[fromNode].push_back(toNode);
            l[toNode].push_back(fromNode);
        }

        void printGraph(){
            for (int i = 0; i < v  ; i++)
            {
                cout<<"Vertix : "<<i<<" connecting edges -> ";
                list<int>::iterator it;
                it = l[i].begin();
                while (it!=l[i].end())
                {
                    cout<<*it<<" ";
                    it++;
                }  
                cout<<endl;
            }   
        }
};



class GraphHashMap // Usingh HASH MAP to implement graph - when vertices are string - along with weigth
// key(vertices) : value(list of pairs) , pair{node as string, weight or distance}
{
   private:
    unordered_map<string,list<pair<string,int>>> m; 
  
    public :

    void addEdge(string from, string to, int distance, bool bidir ){
        m[from].push_back(make_pair(to,distance));
        if(bidir) // if bidir is passed as true only then 
            m[to].push_back(make_pair(from,distance));
    }

    void BFSlevelOrder(){
        
    }



    void printGraph(){
        unordered_map<string,list<pair<string,int>>>::iterator mapItr;
        mapItr = m.begin();
        while (mapItr!=m.end())
        {
            cout<<"Vertix : "<<mapItr->first<<" connecting edges -> "; // extracting key i.e. string- from
            list<pair<string,int>>::iterator listItr;
            listItr = mapItr->second.begin(); // beging of list of each key
            while (listItr!=mapItr->second.end())
            {   
                cout<<listItr->first<<"-"<<listItr->second<<"  ";
                listItr++;
            }
            cout<<endl;
            mapItr++;
        }
    }

};



int main(){

    GraphHashMap g;
    g.addEdge("A","B",90,true);
    g.addEdge("A","C",10,true);
    g.addEdge("A","D",50,false);
    g.addEdge("D","B",70,true);
    g.addEdge("C","D",40,true);
    g.printGraph();


    return 0;
}