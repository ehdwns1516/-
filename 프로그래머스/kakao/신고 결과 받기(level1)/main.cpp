#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_set<string> report_set(report.begin(), report.end());
    unordered_map<string, vector<string>> reported;
    unordered_map<string, int> emailed;
    
    for(string s : report_set){
        string from = "";
        string to = "";
        bool flag = false;
        for(char c : s){
            if(c == ' '){
                flag = true;
                continue;
            }
            if(flag)
                to += c;
            else
                from += c;
        }
        reported[to].push_back(from);
    }
    for(string s : id_list){
        if(reported[s].size() >= k){
            for(string emailed_id : reported[s]){
                emailed[emailed_id]++;
            }
        }
    }
    
    for(string s : id_list){
        answer.push_back(emailed[s]);
    }
    
    return answer;
}
