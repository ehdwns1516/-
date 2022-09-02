#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i = 0; i < new_id.size(); i++){
        if('A' <= new_id[i] and new_id[i] <= 'Z'){
            answer += (char)(new_id[i] + 32);
            continue;
        }
        else if(('a' <= new_id[i] and new_id[i] <= 'z') or ('0' <= new_id[i] and new_id[i] <= '9') or new_id[i] == '-' or new_id[i] == '_'){
            answer += new_id[i];
        }
        else if(new_id[i] == '.'){
            if(answer.empty())
                continue;
            if(answer.back() == '.')
                continue;
            
            answer += new_id[i];
        }
    }
    
    if(answer.size() > 15)
        answer = answer.substr(0, 15);
    
    while(!answer.empty() and answer.back() == '.'){
        answer.pop_back();
    }
    
    if(answer.empty())
        answer = "a";
    
    while(answer.size() < 3){
        char temp = answer.back();
        answer.push_back(temp);
    }
    
    return answer;
}
