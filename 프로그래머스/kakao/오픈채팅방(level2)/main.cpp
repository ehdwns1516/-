#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> message;
    unordered_map<string, string> result_nickname;
    for(string s : record){
        int count = 0;
        string command = "";
        string uid = "";
        string nickname = "";
        for(char c : s){
            if(c == ' '){
                count++;
                continue;
            }
            else{
                if(count == 0){
                    command += c;
                }
                else if(count == 1){
                    uid += c;
                }
                else{
                    nickname += c;
                }
            }
        }
        if(command == "Enter"){
            message.push_back({command, uid});
            result_nickname[uid] = nickname;
        }
        else if(command == "Leave"){
            message.push_back({command, uid});
        }
        if(command == "Change"){
            result_nickname[uid] = nickname;
        }
    }
    for(pair<string, string> p : message){
        if(p.first == "Enter"){
            answer.push_back(result_nickname[p.second] + "님이 들어왔습니다.");
        }
        else{
            answer.push_back(result_nickname[p.second] + "님이 나갔습니다.");
        }
    }
    return answer;
}
