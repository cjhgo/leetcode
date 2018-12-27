#include"struct_define.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
class Solution {
    map<int, vector<int> > node_to_neighbors;
    map<int, UndirectedGraphNode*> node_to_nodeptr;
public:
    void show_edge_list()
    {
        for(auto e : node_to_neighbors)
        {   
            cout<<"edge "<<e.first<<" -> \n";
            for(auto ee : e.second)
            {
                cout<<"\t"<<ee<<endl;
            }
            cout<<endl;
        }        
        cout<<endl<<endl;             
    }
    void get_edge_list(UndirectedGraphNode *node)
    {
        if( node == nullptr) return;
        int key = node->label;
        if( node_to_neighbors.find(key) == node_to_neighbors.end())
        {
            vector<int> temp;
            for(auto e : node->neighbors)
            {
                temp.push_back(e->label);
            }
            node_to_neighbors[key]=temp;
            for(auto e : node->neighbors)
            {
                get_edge_list(e);
            }
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if( node == nullptr)
        return nullptr;
        get_edge_list(node);
        for(auto e :node_to_neighbors)
        {
            UndirectedGraphNode* node = new UndirectedGraphNode(e.first);
            node_to_nodeptr[e.first] = node;
        }

        for(auto e : node_to_neighbors)
        {            
            for(auto ee : e.second)
            {
                node_to_nodeptr[e.first]->neighbors.push_back(node_to_nodeptr[ee]);
            }
        }              
        return node_to_nodeptr[node->label];
    }
};
int main(int argc, char const *argv[])
{
    UndirectedGraphNode n5(5);
    UndirectedGraphNode n1(1);
    UndirectedGraphNode n2(2);
    UndirectedGraphNode n3(3);
    UndirectedGraphNode n4(4);
    n4.neighbors={&n5};
    n2.neighbors={&n4};
    n3.neighbors={&n4};
    n1.neighbors={&n2, &n3};

    Solution sol;
    UndirectedGraphNode* nn = sol.cloneGraph(&n1);
    sol.show_edge_list();

    Solution sol2;
    sol2.get_edge_list(nn);
    sol2.show_edge_list();
    return 0;
}