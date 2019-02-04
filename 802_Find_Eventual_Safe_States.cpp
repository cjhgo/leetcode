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
        
    }
    bool find_cycle_bydfs(int source, vector<vector<int>>& graph)
    {
        enum Color {WHITE, GRAY, BLACK};
        size_t len=graph.size();
        vector<Color> colors (len, WHITE);
        stack<int> mystack;
        colors[source]=GRAY;
        vector<int> visited(len, 0);
        visited[source] = 1;
        mystack.push(source);        
        while( not mystack.empty() )
        {
            if( graph[mystack.top()].size() == 0 )
            {
                cout<<mystack.top()<<std::endl;
                mystack.pop();
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    return 0;
}