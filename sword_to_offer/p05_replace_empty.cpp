#include <cstdlib>
#include <cstdio>

class Solution 
{
public:
	void replaceSpace(char *str,int length) 
  {
    int empty_cnt = 0;
    for(int i = 0; i < length; i++)
    {
      if( str[i] == ' ')
      empty_cnt++;
    }
    int new_len = length+empty_cnt*2;
    for(int j = new_len; j >= 0; j--)
    {
      int index_in_str = j-2*empty_cnt;

      if(str[index_in_str] == ' ')
      {
        str[j]='0';
        str[--j]='2';
        str[--j]='%';
        empty_cnt--;
      }
      else 
        str[j] =str[index_in_str];
    }
  }
};

int main(int argc, char const *argv[])
{
  char *str=(char*)malloc(100*sizeof(char));
  str[0]='W';
  str[1]='e';
  str[2]=' ';
  str[3]='a';
  str[4]='r';
  str[5]='e';
  str[6]=' ';
  str[7]='h';
  str[8]='a';
  str[9]='p';
  str[10]='p';
  str[11]='y';
  
  Solution s;
  s.replaceSpace(str,11);
  printf("%s", str);
  delete str;//[100];
  return 0;
}
