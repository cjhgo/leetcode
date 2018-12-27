#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
struct UndirectedGraphNode 
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
}; 