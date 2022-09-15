#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> LZW;
    int count = 1;
    for(int i = 0; i < 26; i++){
        string temp = "";
        temp.push_back('A' + i);
        LZW[temp] = count++;
    }
    
    string w = "";
    for(int i = 0; i < msg.size(); i++){
        w.push_back(msg[i]);
        while(LZW[w]){
            i++;
            w.push_back(msg[i]);
        }
        LZW[w] = count++;
        w.pop_back();
        answer.push_back(LZW[w]);
        w = "";
        i--;
    }
    
    return answer;
}
