#include <iostream>
#include <string>

using namespace std;
string number[30] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "quarter",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "twenty one",
    "twenty two",
    "twenty three",
    "twenty four",
    "twenty five",
    "twenty six",
    "twenty seven",
    "twenty eight",
    "twenty nine",
    "half",
};

void output(string hour, string minute)
{
    int h = stoi(hour);

    if(minute == "00")
    {
        cout << number[h-1] << " o' clock";
    }
    else
    {
        int m = stoi(minute);


        if(m <= 30)
        {   
            if(m == 1)
                cout << number[m-1] << " minute past " << number[h-1];
            else if(m!=15 && m != 30)
                cout << number[m-1] << " minutes past " << number[h-1];
            else if (m == 30)
                cout << number[m-1] << " past " << number[h-1];
            else if (m == 15)
                cout << number[m-1] << " past " << number[h-1];
        }

        else
        {
            m = 60 - m;
            if(m != 15 && m != 30)
                cout << number[m-1] << " minutes to " << number[h];
            else if(m == 30)
                cout << number[m-1] << " to " << number[h];
            else if(m == 15)
                cout << number[m-1] << " to " << number[h];
        }   
            
    }
}

int main()
{
    string hour, minute;
    cin >> hour >> minute;

    output(hour, minute);

    return 0;
}

