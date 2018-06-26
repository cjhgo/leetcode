#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {

        stringstream ss;
        int unit = num%10;
        int ten = num%100-unit;
        int hundred = num%1000-ten-unit;
        int thousand = num%10000 - hundred-ten-unit;
        string thousand_s,hundred_s,ten_s,unit_s;
        thousand_s=string(thousand/1000, 'M');
        if(hundred == 900)
            hundred_s="CM";
        else if(hundred == 400)            
            hundred_s="CD";
        else
            hundred_s = string(hundred/500, 'D') + string( (hundred-500 >= 0 ? hundred-500 : hundred )/100,'C');

        if(ten == 90)
            ten_s="XC";
        else if(ten == 40)
            ten_s="XL";
        else
            ten_s = string(ten/50, 'L') + string( (ten-50 >= 0 ? ten-50 : ten) /10,'X');

        if(unit == 9)
            unit_s="IX";
        else if(unit == 4)
            unit_s="IV";
        else
            unit_s = string(unit/5, 'V') + string( (unit-5 >= 0 ? unit -5 : unit),'I');


        cout<<thousand<<"#"<<hundred<<"#"<<ten<<"#"<<unit;
        cout<<thousand_s<<"#"<<hundred_s<<"#"<<ten_s<<"#"<<unit_s;
        ss<<thousand_s<<hundred_s<<ten_s<<unit_s;

        return ss.str();
    }
};

int main(int argc, const char* argv[])
{
    Solution s;
    cout<<s.intToRoman(58);
}