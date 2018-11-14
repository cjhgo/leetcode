#include<vector>
#include<stack>
#include<iostream>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
class MinStack 
{
private:
    stack<int> sdata,smin;
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        
    }
    
    void push(int x) 
    {
        sdata.push(x);
        if(not smin.empty())
        {
            if( x <= smin.top())
                smin.push(x);
        }
        else
            smin.push(x);
    }
    
    void pop() 
    {
        if( sdata.empty() || smin.empty())
            return;
        int x = sdata.top();
        sdata.pop();
        if( x == smin.top())
            smin.pop();
    
    }
    
    int top() 
    {
        return sdata.top();   
    }
    
    int getMin() 
    {
        return smin.top();
    }
};

int main() 
{
    MinStack ms;
    ms.push(1);
    ms.push(-1);
    ms.push(-1);
    cout<<ms.getMin()<<stdl;
    ms.pop();
    cout<<ms.getMin()<<stdl;
    return 0;
}
