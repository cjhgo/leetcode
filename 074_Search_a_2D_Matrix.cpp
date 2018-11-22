#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    return nullptr;
}(); 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        for(auto row : matrix)
        {
            if(  row.size() > 0 and row[row.size()-1] < target)
            continue;
            if( binary_search(row.begin(), row.end(), target) )
            return true;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22}
    };
    cout<<sol.searchMatrix(matrix, 4);
    cout<<sol.searchMatrix(matrix, 99);
    return 0;
}
