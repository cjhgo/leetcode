#include"struct_define.h"
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<map>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
class Solution 
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int> res;

        for(size_t i = 0; i < graph.size(); i++)
        {
            if( not find_cycle_bydfs(i, graph) )
            res.push_back(i);
        }
        return res;
    }
    bool find_cycle_bydfs(int source, vector<vector<int>>& graph)
    {
        size_t len=graph.size();
        vector<int> visited(len, 0);
        return dfs(source, visited, graph);
    }
    bool dfs(int source, vector<int>& visited, vector<vector<int>>& graph)
    {        
        if( visited[source] == 0 )
        {
            cout<<source<<"\t";
            visited[source]=1;
        }
        for(auto e : graph[source])
        {
            if( visited[e] == 1 )
            {
                cout<<"find cycle! while processing "<<source<<"->"<<e<<endl;
                return true;
            }
            if( visited[e] == 0)
            {
                if( dfs(e, visited, graph))
                return true;
            }
        }
        visited[source]=2;
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int> > graph = {
        {{1,2},{2,3},{5},{0},{5},{},{}}
    };    
    auto res = sol.eventualSafeNodes(graph);
    cout<<endl<<endl;
    for(auto e :  res)
    {
        cout<<e<<"\t";
    }
    return 0;
}