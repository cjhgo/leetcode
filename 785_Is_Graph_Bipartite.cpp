#include"struct_define.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
class Solution 
{
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        typedef enum{ WHITE,GRAY,BLACK } COLOR;
        typedef enum{ RED,BLUE,GREEN } PARTITE;
        vector<COLOR> visited;
        vector<PARTITE> partite;
        for(size_t i = 0; i < graph.size();i++)
        {

            std::queue<int> myqueue;
            visited.clear();partite.clear();
            visited.resize(graph.size(), WHITE);
            partite.resize(graph.size(), GREEN);
            visited[i]=GRAY;
            partite[i]=RED;
            myqueue.push(i);
            while(not myqueue.empty())
            {
                int top = myqueue.front();
                for(auto neighbor: graph[top])
                {
                    if(partite[neighbor]==partite[top])
                            return false;
                    
                    else if(visited[neighbor]==WHITE)
                    {
                        visited[neighbor]=GRAY;
                        partite[neighbor]=PARTITE(1-partite[top]);
                        myqueue.push(neighbor);
                    }
                }
                visited[top]=BLACK;
                myqueue.pop();
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph={
    {},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}
    };
    Solution sol;
    std::cout<<sol.isBipartite(graph);
    return 0;
}