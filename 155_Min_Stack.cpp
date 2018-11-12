#include<vector>
#include <algorithm>
using namespace std;
class MinStack 
{
private:
    vector<int> data;
public:
    MinStack()
    {
            
    }
    
    void push(int x) 
    {
        data.push_back(x);
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
        return *min_element(data.begin(), data.end());
    }
};
