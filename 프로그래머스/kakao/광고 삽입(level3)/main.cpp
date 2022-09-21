#include <string>
#include <vector>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int play = stoi(play_time.substr(0, 2)) * 60 * 60 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
    int adv = stoi(adv_time.substr(0, 2)) * 60 * 60 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));
    vector<long long> result(play + 1, 0);
    
    for(string s : logs){
        int start_time = stoi(s.substr(0, 2)) * 60 * 60 + stoi(s.substr(3, 2)) * 60 + stoi(s.substr(6, 2));
        int end_time = stoi(s.substr(9, 2)) * 60 * 60 + stoi(s.substr(12, 2)) * 60 + stoi(s.substr(15, 2));
        result[start_time]++;
        result[end_time]--;
    }
    
    for(int i = 1; i < result.size(); i++){
        result[i] += result[i - 1];
    }
    
    
    long long total = 0;
    for(int i = 0; i < adv; i++){
        total += result[i];    
    }
    long long max = total;    
    int insert_adv_time = 0;
    for(int i = 0; i < play - adv; i++){
        total -= result[i];
        total += result[adv + i];
        if(max < total){
            max = total;
            insert_adv_time = i + 1;
        }
    }
    
    int h = insert_adv_time / 3600;
    insert_adv_time %= 3600;
    int m = insert_adv_time / 60;
    int s = insert_adv_time % 60;
    
    if(h < 10)
        answer += "0";
    answer += (to_string(h) + ":");
    
    if(m < 10)
        answer += "0";
    answer += (to_string(m) + ":");
    
    if(s < 10)
        answer += "0";
    answer += (to_string(s));
    
    return answer;
}