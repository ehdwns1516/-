#include <string>
#include <vector>
#include <tuple>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int MAX_play_time = 0;
    
    for(string s : musicinfos){
        int play_time = (stoi(s.substr(6, 2)) * 60 + stoi(s.substr(9, 2))) - (stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2))) + 1;
        string title = "";
        string sounds = "";
        int index = 12;
        
        while(s[index] != ','){
            title.push_back(s[index++]);
        }
        
        index++;
        while(s[index] != ',' and index < s.size()){
            sounds.push_back(s[index++]);
        }
        
        int count = 0;
        index = 0;
        string temp_sounds = "";
        while(count != play_time){
            temp_sounds.push_back(sounds[(index++ % sounds.size())]);
            if(sounds[(index % sounds.size())] == '#')
                temp_sounds.push_back(sounds[(index++ % sounds.size())]);
            count++;
        }
        sounds = temp_sounds;
        
        bool flag = false;
        for(int i = 0; i < (int)sounds.size() - (int)m.size(); i++){
            if(sounds.substr(i, m.size()) == m and sounds[i + m.size()] != '#'){
                flag = true;
                break;
            }
        }
        if(flag and MAX_play_time < play_time){
            answer = title;
            MAX_play_time = play_time;
        }
    }
    
    return answer;
}
