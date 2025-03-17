#include <bits/stdc++.h>

using namespace std;

int N;
struct Time
{
    Time(const string &hour, const string &minute, const string &second) 
        : hour(hour), minute(minute), second(second), time(hour + minute + second)
        {
            
        }
    bool operator == (const Time &other) const
    {
        return hour == other.hour && minute == other.minute && second == other.second;
    }
    bool operator < (const Time &other) const 
    {
        for(int i = 0; i < time.size(); i ++)
        {
            if(time[i] < other.time[i]) return true;
            else if(time[i] > other.time[i]) return false;
        }
    }
    string hour;
    string minute;
    string second;
    string time;
};
struct TimeSlot
{
    TimeSlot(const Time &begin, const Time &end) : begin(begin), end(end){}\
    bool operator < (const TimeSlot &other) const 
    {
        return begin < other.begin;
    }
    Time begin, end;
};
set<TimeSlot> myset;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i ++)
    {
        string begin,_,end;
        cin >> begin;
        cin >> _;
        cin >> end;
        myset.insert(TimeSlot(Time(begin.substr(0,2), begin.substr(3,2), begin.substr(6,2)),
                             Time(end.substr(0,2), end.substr(3,2), end.substr(6,2))));
    }

    Time endTime("00", "00", "00");
    
    for(auto timeslot : myset)
    {
        Time &begin = timeslot.begin;
        Time &end = timeslot.end;
        if(!(endTime == begin))
        {
            cout << endTime.hour << ":" << endTime.minute << ":" << endTime.second << " - ";
            cout << begin.hour << ":" << begin.minute << ":" << begin.second << endl;
        }
        endTime = end;
    }
    if(!(endTime == Time("23", "59", "59")))
    {
        cout << endTime.hour << ":" << endTime.minute << ":" << endTime.second << " - ";
        cout << 23 << ":" << 59 << ":" << 59 << endl;
    }
    return 0;
}


