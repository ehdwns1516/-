#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool comp(tuple<int, string, int> a, tuple<int, string, int> b){
    if(get<1>(a) == get<1>(b))
        return get<0>(a) < get<0>(b);
    
    return get<1>(a) < get<1>(b);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<int, string, int>> result;
    int index = 0;
    for(string s : files){
        string HEAD = "";
        string NUMBER = "";
        for(int i = 0; i < s.size(); i++){
            if('0' <= s[i] and s[i] <= '9'){
                while('0' <= s[i] and s[i] <= '9' and i < s.size() and NUMBER.size() < 6){
                    NUMBER.push_back(s[i]);
                    i++;
                }
                result.push_back({stoi(NUMBER), HEAD, index++});
                break;
            }
            HEAD.push_back(toupper(s[i]));
        }
    }
    
    stable_sort(result.begin(), result.end(), comp);
    
    for(int i = 0; i < result.size(); i++){
        answer.push_back(files[get<2>(result[i])]);
    }
    
    return answer;
}