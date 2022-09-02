#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    
    do{
        unordered_map<char, int> friends_idx;
        for(int i = 0; i < friends.size(); i++){
            friends_idx[friends[i]] = i;
        }
        bool flag = true;
        for(string s : data){
            if(s[3] == '='){
                if(abs(friends_idx[s[0]] - friends_idx[s[2]]) - 1 != s[4] - '0'){
                    flag = false;
                    break;
                }
            }
            else if(s[3] == '>'){
                if(abs(friends_idx[s[0]] - friends_idx[s[2]]) - 1 <= s[4] - '0'){
                    flag = false;
                    break;
                }
            }
            else if(s[3] == '<'){
                if(abs(friends_idx[s[0]] - friends_idx[s[2]]) - 1 >= s[4] - '0'){
                    flag = false;
                    break;
                }
            }
            
        }
        if(flag)
            answer++;
    }while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}
