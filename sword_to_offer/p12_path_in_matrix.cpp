
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
  bool find_from_at(int pos, int row, int col)
  {
    if(str[pos]=='\0') return true;

    if( visited[row*cols+col] == true) return false;

    if((row < rows && col < cols) && matrix[row*cols+col] == str[pos])
    {
      visited[row*cols+col] = true;
      return find_from_at(pos+1, row, col+1) ||
              find_from_at(pos+1, row, col-1) ||
              find_from_at(pos+1, row+1, col) ||
              find_from_at(pos+1, row-1, col);
    }else return false;
  }
  bool hasPath(char* matrix, int rows, int cols, char* str)
  {
    this->matrix = matrix;
    this->str = str;
    this->rows = rows;
    this->cols = cols;
    this->visited = new bool[this->rows*this->cols]{0};

    for(int i = 0; i < rows; i++)
    for(int j = 0; j < cols; j++)
    {
      if(find_from_at(0, i,j))return true;
      else
      this->visited = new bool[this->rows*this->cols]{0};
    }
    return false;
  }

private:
  char* matrix,*str;  
  int rows,cols;
  bool *visited;


};
int main(int argc, char const *argv[])
{
  char matrix[3][4]={
    'a','b','t','g',
    'c','f','c','s',
    'j','d','e','h'
  };
  Solution sol;
  cout<<matrix[2][3]<<endl;
  cout<<sol.hasPath((char*)matrix,3,4,"gscfdj")<<endl;
  cout<<sol.hasPath((char*)matrix,3,4,"bfce")<<endl;
  return 0;
}