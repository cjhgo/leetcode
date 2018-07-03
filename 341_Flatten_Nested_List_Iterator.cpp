
class NestedInteger {
    int e_int;
    vector<int> e_vec;    
public:

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        
    }

    int next() {
        
    }

    bool hasNext() {
        
    }
};
int main(int argc, char* argv[])
{

    NestedIterator i(nestedList);
    while (i.hasNext()) 
        cout << i.next();
}