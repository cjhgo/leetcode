#include<vector>
using namespace std;
class MinStack 
{
private:
    vector<int> data;
    int min;
public:
    /** initialize your data structure here. */
    MinStack()
    :min(2147483647)
    {
            
    }
    
    void push(int x) 
    {
        data.push_back(x);
        if( x < min)
        min = x;
    }
    
    void pop() 
    {
        data.pop_back();
    }
    
    int top() 
    {
        return data[data.size()-1];
    }
    
    int getMin() 
    {
        return min;
    }
};

