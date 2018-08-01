#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cctype>
#include<stack>
using namespace std;
class Element
{
public:
    int type;
    int count;
    string base;
    Element(string str):type(1), base(str){}
    Element(int cnt):type(2), count(cnt){}
    Element(int type, string str):type(type), base(str){}
    string repr()
    {
        if(type == 1)
        return base;
        else if(type == 2)
        return to_string(count);
        else if(type == 3)
        return "[";
        else if(type == 4)
        return "]";
    }
};
class Solution 
{
public:
    inline string multiString(string s, int count)
    {
        string temp;
        for(int i = 0; i < count;i++)
        {
            temp += s;
        }
        return temp;
    }
    string genString(string s)
    {
        auto res = s.find("[");
        int count = stoi(s.substr(0,res));
        string base = s.substr(res+1, (s.size()-(res+1)-1) );
        return multiString(base, count);
    }
    vector<Element> genTokens(string s)
    {
        vector<Element> elements;
        size_t cur=0;
        size_t next=cur+1;
        while( cur < s.size())
        {
            if( isdigit(s[cur]) )
            {   
                while(next < s.size() and  isdigit(s[next]) )
                {
                    next++;
                }
                int number = stoi(s.substr(cur, next-cur));
                elements.push_back(Element(number));
                cur=next;
                next=cur+1;
                continue;
            }
            else if(s[cur] == '[')
            {
                elements.push_back(Element(3, "["));
                cur++;
                next=cur+1;
                continue;
            }
            else if(s[cur] == ']')
            {
                elements.push_back(Element(4, "]"));
                cur++;
                next=cur+1;
                continue;
            }
            else if(isalpha(s[cur]))
            {
                while(next < s.size() and  isalpha(s[next]))
                {
                    next++;
                }                            
                elements.push_back(Element(s.substr(cur, next-cur)));
                cur=next;
                next=cur+1;
                continue;
            }
        }
        return elements;
    }
    string decodeString(string s) 
    {   
        stringstream ss;
        stack<Element> mystack;
        for(auto e: genTokens(s))
        {
            cout<<e.repr()<<endl;
            
            
            if(e.type == 1 )
            {
                if(mystack.empty())
                {
                    ss<<e.base;
                }
                else
                {
                    //handle case "3[a]2[b4[F]c]"
                    //when c come in , we need to judge type of top 
                    if(mystack.top().type == 1)
                    {
                        mystack.top().base += e.base;
                    }
                    else
                        mystack.push(e);
                }

            }
            else
                mystack.push(e);
            if(e.type == 4)
            {
                mystack.pop();
                string to_multi = mystack.top().base;
                mystack.pop();
                mystack.pop();
                int count = mystack.top().count;
                mystack.pop();
                string temp = multiString(to_multi, count);
                if( mystack.empty())
                {
                    ss<<temp;
                }
                else
                {
                    //handle case "2[2[b]]" vs  "2[xx2[b]]"
                    //when 2[b] become bb and  come in 
                    //we need to judge type of top 
                    if(mystack.top().type == 1)
                    {
                        mystack.top().base += temp;
                    }
                    else
                        mystack.push(temp);
                    
                }
            }
            
        }
        return ss.str();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    //string str = "2[abc]3[cd]ef";
    string str = "3[a]2[b4[F]c]";//"2[2[b]]";//2[abc]3[cd]ef";
    cout<<s.decodeString(str)<<endl;
    return 0;
}
