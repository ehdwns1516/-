#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> result;
    string str_num = "";
    int num = 0;
    int index = 0;
    
    for(char c : dartResult){
        if(c == 'S'){
            num = stoi(str_num);
            result.push_back(num);
            num = 0;
            str_num = "";
            index++;
        }
        else if(c == 'D'){
            num = stoi(str_num) * stoi(str_num);
            result.push_back(num);
            num = 0;
            str_num = "";
            index++;
        }
        else if(c == 'T'){
            num = stoi(str_num) * stoi(str_num) * stoi(str_num);
            result.push_back(num);
            num = 0;
            str_num = "";
            index++;
        }
        else if(c == '*'){
            if(index == 1){
                result[index - 1] *= 2;
            }
            else{
                result[index - 1] *= 2;
                result[index - 2] *= 2;
            }
                
        }
        else if(c == '#'){
            result[index - 1] *= -1;
        }
        else{
            str_num.push_back(c);
        }
    }
    for(int i : result){
        answer += i;
    }
    return answer;
}
