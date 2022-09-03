#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string result = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'z'){
            result += "0";
            i += 3;
        }
        else if(s[i] == 'o'){
            result += "1";
            i += 2;
        }
        else if(s[i] == 't'){
            if(s[i + 1] == 'w'){
                result += "2";
                i += 2;
            }
            else{
                result += "3";
                i += 4;
            }
            
        }
        else if(s[i] == 'f'){
            if(s[i + 1] == 'o'){
                result += "4";
                i += 3;
            }
            else{
                result += "5";
                i += 3;
            }
        }
        else if(s[i] == 's'){
            if(s[i + 1] == 'i'){
                result += "6";
                i += 2;
            }
            else{
                result += "7";
                i += 4;
            }
            
        }
        else if(s[i] == 'e'){
            result += "8";
            i += 4;
        }
        else if(s[i] == 'n'){
            result += "9";
            i += 3;
        }
        else{
            result += s[i];
        }
    }
    answer = stoi(result);
    return answer;
}
