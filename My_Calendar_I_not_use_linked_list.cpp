#include<iostream>
#include<vector>
using namespace std;
class MyCalendar {
public:
    MyCalendar()
    {
    };

    bool book(int start, int end) 
    {
        for(auto e: booked_events)
        {
            if(end > e.first and e.second > start)
            return false;
        }
        booked_events.push_back({start,end});
        return true;
    }
private:
    vector<pair<int,int> > booked_events; 
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