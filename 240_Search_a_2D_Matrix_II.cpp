#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
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
            bool it = binary_search(row.begin(), row.end(), target);
            if( it )return true;
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
