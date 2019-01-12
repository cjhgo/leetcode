#include"struct_define.h"
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
    int minFallingPathSum(vector<vector<int>>& A) 
    {
        
        int res = INT32_MAX;
        size_t len = A.size();
        if( len == 1 ) return A[0][0];
        for(int i = len-2; i >=0; i--)
        {
            
            for(size_t j = 0; j < len; j++)
            {
                // A[i,j]
                int min_ij = A[i+1][j];
                if( j == 0)
                {
                    if( A[i+1][j+1] < min_ij )
                    min_ij = A[i+1][j+1];
                }
                else if( j == len-1 )
                {
                    if( A[i+1][j-1] < min_ij )
                    min_ij = A[i+1][j-1];
                }
                else//0 < j < len-1
                {
                    if( A[i+1][j-1] < min_ij )
                    min_ij = A[i+1][j-1];
                    if( A[i+1][j+1] < min_ij )
                    min_ij = A[i+1][j+1];
                }
                A[i][j] += min_ij;
            }
        }
        for(size_t i = 0; i < len; i++)
        {
            if( A[0][i] < res)
                res = A[0][i];
        }
        return res;        
    }
};
int main(int argc, char const *argv[])
{
    vector< vector<int> > A ={
        // {1,2,3},
        // {4,5,6},
        // {7,8,9}
        {51,24},
        {-50,82}
    };
    Solution sol;
    cout<<sol.minFallingPathSum(A);
    return 0;
}