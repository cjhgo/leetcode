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
private:
  vector<vector<char>> board;  
  void find_feasible(vector<vector<char>>& table ,int row, int col, bool chars[])
  {
    for(int i = 0; i < 9; i++)
    {      
      if(isdigit(table[row][i])) chars[table[row][i]-'0'-1]=true;
      if(isdigit(table[i][col])) chars[table[i][col]-'0'-1]=true;
    }
    for(int i = 0; i < 3; i++)
    {
      int row_ = 3*(row/3)+i;
      for(int j = 0; j < 3; j++)
      {
        int col_ = 3*(col/3) + j;
        if( isdigit(table[row_][col_])) chars[table[row_][col_]-'0'-1]=true;
      }
    }
  }
public:
  bool helper(vector<vector<char>>& table)
  {
    for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
    {
      if(table[i][j] == '.')
      {
        bool chars[9]{false};
        find_feasible(table, i, j, chars);
        vector<char> tmp;
        for(int i = 0; i < 9; i++)
        {
          if( chars[i] == false)
          {
            tmp.push_back('0'+i+1);
          }
        }
        if(tmp.size() < 1) return false;
        for(auto c : tmp)
        {
          table[i][j] = c;
          if(helper(table)) return true;
          else table[i][j] = '.';
        }
        return false;        
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>>& board) 
  {    
    cout<<helper(board)<<endl;
  }
};
int main(int argc, char const *argv[])
{
  vector<vector<char>> board{
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  Solution sol;
  sol.solveSudoku(board);
  for(auto e : board)
  {
    for(auto ee: e)
    {
      cout<<ee<<"\t";
    }
    cout<<endl;
  }

  return 0;
}