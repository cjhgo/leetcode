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
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {        
        if( matrix.size() < 1) return false;
        int i = 0, j = matrix[0].size() -1;
        while( i < matrix.size() && j >= 0)
        {
            if(matrix[i][j] == target)
            return true;
            else if( matrix[i][j] > target)
            j--;
            else if( matrix[i][j] < target)
            i++;
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
