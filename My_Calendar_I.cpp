#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
struct MyInterval
{
    int start;
    int end;
    MyInterval* next;
    MyInterval():start(0),end(0),next(nullptr)
    {};
    MyInterval(int b ,int e):start(b),end(e),next(nullptr)
    {};
};
class MyCalendar {
public:
    MyCalendar()
    {
        ptr = nullptr;
    };
    void print_interval()
    {
        MyInterval* temp  = ptr;
        cout<<"current interval b"<<endl;
        while(temp != NULL)
        {
            cout<<temp->start<<"#"<<temp->end<<endl;
            temp = temp->next;
        }
        cout<<"current interval e"<<endl;
    };
    /*
       for (auto p:v) {
            if (p.first <= s && p.second > s) return false;
            if (s <= p.first && e > p.first) return false;
        }
        v.push_back({s,e});
    */
    bool book(int start, int end) 
    {
        MyInterval * cur = ptr;
        while(cur != NULL)
        {
            if( start < cur->end and end > cur->start)
                return false;
            else
                cur = cur->next;
        }

        if( ptr == nullptr )
        {
            MyInterval* temp = new MyInterval(start ,end);
            ptr = temp;
        }
        else
        {
            MyInterval* temp = new MyInterval(start ,end);
            temp->next = ptr->next;
            ptr->next = temp;
        }                    
        return true;
    }
private:
    MyInterval* ptr; 
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 [37,50],[33,50],[4,17],[35,48],[8,25]
 */


int main(int argc, char const *argv[])
{
    MyCalendar obj =  MyCalendar();
cout<< obj.book(47,50)<<endl;
cout<< obj.book(33,41)<<endl;
cout<< obj.book(25,32)<<endl;
cout<< obj.book(19,25)<<endl;
cout<< obj.book(3,8)<<endl;
cout<< obj.book(8,13)<<endl;
cout<< obj.book(18,27)<<endl;
	return 0;
}