#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int window = s.size() / 2; window > 0; window--){
        string result = "";
        int cur_index = 0;
        int count = 1;
        while(cur_index + window < s.size()){
            string cur_word = s.substr(cur_index, window);
            string next_word = s.substr(cur_index + window, window);
            if(cur_word == next_word){
                count++;
                cur_index += window;
                continue;
            }
            else{
                if(count > 1)
                    result += to_string(count);
                result += cur_word;
                count = 1;
                cur_index += window;
            }
        }
        if(count > 1){
            result += to_string(count);
            result += s.substr(cur_index, window);
        }
        else
            result += s.substr(cur_index, s.size() - cur_index);
        if(answer > result.size())
            answer = result.size();
    }
    
    
    return answer;
}
