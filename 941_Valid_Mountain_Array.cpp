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
class Solution {
public:
    bool validMountainArray(vector<int>& A) 
    {
        if(A.size() < 3 || A[1] <= A[0]) return false;
        size_t i = 1;
        for(; i < A.size(); i++)
        {
            if( A[i-1] < A[i])continue;
            else if( A[i-1] == A[i]) return false;
            else break;
        }
        if(i == A.size()) return false;
        for(; i <A.size(); i++)
        {
            if( A[i-1] > A[i]  )continue;
            else return false;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    return 0;
}