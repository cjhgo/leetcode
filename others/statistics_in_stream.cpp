#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

/**
利用递推在数据流中求均值和方差
均值的递推公式:E_n=E_{n+1}+\frac{x_n-E_{n-1}}{n}
方差的递推公式:F_n=F_{n-1}+(x_n-E_{n-1})(x_n-E_n)
**/


class Accumulator
{

public:  
  Accumulator():mean(0),var(0),cnt(0){}
  void addValue(int x)
  {
    vals.push_back(x);
    cnt++;
    float old_mean = mean;
    mean = mean + (x-mean)*1.0/cnt;
    var = var + (x-old_mean)*(x-mean);    
    show_statistics();
  }
  void show_statistics()
  {
    if(cnt ==0)return;
    cout<<"result by iter :"<<mean<<"\t"<<var<<endl;
    float mean_,var_,sum;
    mean_=var_=sum=0;
    int i = 0;
    for(; i < vals.size(); i++)
    {
      sum += vals[i];
    }
    mean_ = sum*1.0/i;
    sum = 0;
    i = 0;
    for(; i < vals.size(); i++)
    {
      sum += (vals[i]-mean_)*(vals[i]-mean_);
    }
    var_=sum;
    cout<<"result by all :"<<mean_<<"\t"<<var_<<endl;
  }
  void clear()
  {
    mean=var=0;
    cnt=0;
    vals.clear();
    cout<<endl<<endl;
  }
public:
  int cnt;
  float mean,var;
  vector<int> vals;
};

int main(int argc, char const *argv[])
{
  Accumulator acu;
  acu.addValue(1);
  acu.addValue(2);
  acu.addValue(3);
  acu.addValue(4);

  acu.clear();

  acu.addValue(2);
  acu.addValue(2);
  acu.addValue(2);
  acu.addValue(2);
  acu.addValue(3);
  return 0;
}