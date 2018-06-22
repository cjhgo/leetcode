#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
struct MyInterval
{
    size_t start;
    size_t end;
    MyInterval* next;
    MyInterval():start(0),end(pow(10,9))
    {};
    MyInterval(size_t b ,size_t e):start(b),end(e)
    {};
};
class MyCalendar {
public:
    MyCalendar()
    {
        ptr = new MyInterval();
        ptr->next = NULL;
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
    bool book(int start, int end) 
    {
        cout<<"book "<<start<<"#"<<end<<endl;
        MyInterval* cur = ptr;
        end = end-1;
        while(cur != NULL)
        {
            if( start < cur->start )
            {
                break;
            }
            else if (start == cur->start)
            {
                if( end < cur->end)
                {
                    cur->start = end+1;
                    print_interval();
                    return true;
                }
                else if( end == cur->end)
                {
                    MyInterval* ttt = cur->next;
                    if( ttt != NULL)
                    {
                        cur->start = ttt->start;
                        cur->end = ttt->end;
                        cur->next = ttt->next;
                        delete ttt;
                    }
                    else
                        cur = NULL;
                    print_interval();
                    return true;
                }
                else if( end > cur->end)
                {
                    break;
                }
            }
            else if ( start > cur->start )
            {
                if(start < cur->end)
                {
                    if(end < cur->end)
                    {                    
                        size_t new_start = end+1;
                        size_t new_end = cur->end;
                        MyInterval* temp = new MyInterval(new_start, new_end);
                        temp->next = cur->next;
                        cur->next = temp;                    
                        cur->end=start-1;
                        print_interval();
                        return true;
                    }
                    else if(end == cur->end )
                    {
                        cur->end=start-1;
                        print_interval();
                        return true;
                    }
                    else if(end > cur->end)
                    {                    
                        break;
                    }
                }
                else if( start == cur->end)
                {
                    break;
                }
                else if( start > cur->end)
                {
                    cur=cur->next;
                    continue;
                }
            }
        }
        return false;
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
cout<< obj.book(20,29)<<endl;
cout<< obj.book(13,22)<<endl;
cout<< obj.book(44,50)<<endl;
cout<< obj.book(1,7)<<endl;
cout<< obj.book(2,10)<<endl;
cout<< obj.book(14,20)<<endl;
cout<< obj.book(19,25)<<endl;
cout<< obj.book(36,42)<<endl;
cout<< obj.book(45,50)<<endl;
cout<< obj.book(47,50)<<endl;
cout<< obj.book(39,45)<<endl;
cout<< obj.book(44,50)<<endl;
cout<< obj.book(16,25)<<endl;
cout<< obj.book(45,50)<<endl;
cout<< obj.book(45,50)<<endl;
cout<< obj.book(12,20)<<endl;
cout<< obj.book(21,29)<<endl;
cout<< obj.book(11,20)<<endl;
cout<< obj.book(12,17)<<endl;
cout<< obj.book(34,40)<<endl;
cout<< obj.book(10,18)<<endl;
cout<< obj.book(38,44)<<endl;
cout<< obj.book(23,32)<<endl;
cout<< obj.book(38,44)<<endl;
cout<< obj.book(15,20)<<endl;
cout<< obj.book(27,33)<<endl;
cout<< obj.book(34,42)<<endl;
cout<< obj.book(44,50)<<endl;
cout<< obj.book(35,40)<<endl;
cout<< obj.book(24,31)<<endl;
	return 0;
}