#include <vector>

using namespace std;

class Solution 
{
public:
    bool Find(int target, vector<vector<int> > array) 
    {
      int m = array.size(), n = array[0].size(), row = 0, column = n-1;      
      while (row < m && column >= 0)
      {
        if( target == array[row][column])
        return true;
        else if( target < array[row][column])
          column--;
        else if( target > array[row][column])
          row++;
      }
      
      return false;
    }
};


int main(int argc, char const *argv[])
{
  
  return 0;
}
