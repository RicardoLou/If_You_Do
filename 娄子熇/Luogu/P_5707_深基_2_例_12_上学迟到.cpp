#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int minute = 10;
    minute += a / b;
    if (a % b) minute ++;
    int hour = 0, min = 0;
    if (minute >= 480) {
        hour = 24 + 8 - minute / 60;
        if (minute % 60 != 0)
            hour --;
        if (hour == 24)
            hour = 0;
        min = 60 - minute % 60;
        if (min == 60)
            min = 0;
    }
    else {
        hour = (480 - minute) / 60;
        min = (480 - minute) % 60;
    }
    printf("%02d:%02d", hour, min);

    return 0;
}