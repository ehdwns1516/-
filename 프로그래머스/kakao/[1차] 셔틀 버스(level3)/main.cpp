#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(), timetable.end());
    int cur_time = 9 * 60;
    int cur_order = 0;
    int result = 0;
    
    while(n){
        int count = m;
        while(count and cur_order < timetable.size()){
            int time = stoi(timetable[cur_order].substr(0, 2)) * 60 + stoi(timetable[cur_order].substr(3, 2));
            if(time <= cur_time)
                cur_order++;
            else
                break;
            count--;
        }
        if(n == 1){
            if(count)
                result = cur_time;
            else
                result = stoi(timetable[cur_order - 1].substr(0, 2)) * 60 + stoi(timetable[cur_order - 1].substr(3, 2)) - 1;
        }
        cur_time += t;
        n--;
    }
    
    int hour = result / 60;
    int minute = result % 60;
    if(hour < 10){
        answer += "0";
    }
    answer += to_string(hour) + ":";
    
    if(minute < 10){
        answer += "0";
    }
    answer += to_string(minute);
    
    return answer;
}