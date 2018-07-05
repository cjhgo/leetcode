#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class NestedInteger {
    int e_int;
    vector<NestedInteger> e_vec;    
    bool is_int;
public:
    NestedInteger():e_int(0),e_vec(NULL),is_int(false)
    {};
    NestedInteger(int argu_int)
    {
        e_int = argu_int;
        is_int = true;
    };
    NestedInteger(vector<NestedInteger> argu_vec)
    {
        e_vec = argu_vec;
        is_int = false;
    };
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return is_int;
    };

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return e_int;
    };

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const
    {
        return e_vec;
    };
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        cur = 0;
        for(auto e: nestedList)
        {
            vector<int> temp  = get(e);
            vec.insert(vec.end(), temp.begin(), temp.end());
        }
            
    }
    vector<int> get(NestedInteger e)
    {
        vector<int> x;
        if(e.isInteger())
        {
            x.push_back(e.getInteger());
        }
        else
        {
            for(auto ee: e.getList())
            {
                vector<int> temp = get(ee);
                x.insert(x.end(), temp.begin(), temp.end());
            }
        }
        return x;

    }

    int next() {
        return vec[cur++];
    }

    bool hasNext() {
        return cur < vec.size();
    }
private:
    vector<int> vec;
    size_t  cur;
};
int main(int argc, char* argv[])
{
    NestedInteger a(4);
    NestedInteger b(6);
    vector<NestedInteger> c={b};
    NestedInteger d(c);
    vector<NestedInteger> e = {a, d};
    NestedInteger f(1);
    vector<NestedInteger> nestedList = {f, e};

    NestedIterator i(nestedList);
    while (i.hasNext()) 
        cout << i.next();
}