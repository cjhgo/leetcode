#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> real_answer;  
        vector<string> answer;        
        vector<size_t> distance;
        size_t i = 0;
        for(auto v : list1)
        {
            auto res = find(list2.begin(), list2.end(), v);

            if( res != list2.end())
            {
                size_t index = std::distance(list2.begin(), res);
                // cout<<*res<<"#"<<index+i<<endl;
                distance.push_back(i + index);
                answer.push_back(*res);
            }    
            i++;    
        }
        size_t min = *min_element(distance.begin(), distance.end());
        for(size_t j = 0; j < distance.size();j++)
        {
            if(distance[j] == min)
            {
                real_answer.push_back(answer[j]);
            }
        }

        return real_answer;
    }
};

int main(int argc, char const *argv[])
{




	vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    //{"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"KFC","Shogun","Burger King"};
    //{"KFC","Burger King","Tapioca Express","Shogun"};
	Solution s;

    for(auto v : s.findRestaurant(list1, list2))
    {
        cout<<"#"<<v<<endl;
    }        
	return 0;
}