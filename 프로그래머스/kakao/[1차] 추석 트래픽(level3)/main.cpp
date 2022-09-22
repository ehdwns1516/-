#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> log_timeline;
    int start = 210000000;
    int end = 0;
    for(string l : lines){
        int end_time = stoi(l.substr(11, 2)) * 60 * 60 * 1000 
        + stoi(l.substr(14, 2)) * 60 * 1000 
        + stoi(l.substr(17, 2)) * 1000 
        + stoi(l.substr(20, 3));
    
        string process_time = "";
        for(int i = 24; i < l.size() - 1; i++){
            if(l[i] == '.')
                continue;
            process_time += l[i];
        }
        while(process_time.size() < 4){
            process_time.push_back('0');
        }
        if(start > end_time - stoi(process_time) + 1)
            start = end_time - stoi(process_time) + 1;
        if(end < end_time)
            end = end_time;
        log_timeline.push_back({end_time - stoi(process_time) + 1, end_time});
    }
    
    sort(log_timeline.begin(), log_timeline.end());
    vector<int> process_start(end - start + 1001, 0);
    vector<int> process_end(end - start + 1, 0);
    
    for(auto p : log_timeline){
        process_start[p.first - start]++;
        process_end[p.second - start]++;
    }
    
    for(int i = 0; i < 1000; i++){
        if(process_start[i])
            answer += process_start[i];
    }
    int current = answer;
    
    for(int i = 0; i < process_start.size() - 1000; i++){
        if(process_end[i]){
            current -= process_end[i];
        }
        
        if(process_start[i + 1000]){
            current += process_start[i + 1000];
            if(current > answer){
                answer = current;
            }
        }
    }
    
    return answer;
}