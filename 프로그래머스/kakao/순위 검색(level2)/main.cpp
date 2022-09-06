#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findPosition(int n, vector<int> &v){
    int start = 0;
    int end = v.size() - 1;
    while(start <= end){
        int middle = (start + end) / 2;
        if(n > v[middle]){
            start = middle + 1;
        }
        else{
            end = middle - 1;
        }
    }
    return start;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, vector<int>>>>> score;
    
    for(string s : info){
        vector<string> infos;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                infos.push_back(temp);
                temp = "";
                continue;
            }
            temp.push_back(s[i]);
        }
        score[infos[0]][infos[1]][infos[2]][infos[3]].push_back(stoi(temp));
        score[infos[0]][infos[1]][infos[2]]["-"].push_back(stoi(temp));
        score[infos[0]][infos[1]]["-"][infos[3]].push_back(stoi(temp));
        score[infos[0]][infos[1]]["-"]["-"].push_back(stoi(temp));
        score[infos[0]]["-"][infos[2]][infos[3]].push_back(stoi(temp));
        score[infos[0]]["-"][infos[2]]["-"].push_back(stoi(temp));
        score[infos[0]]["-"]["-"][infos[3]].push_back(stoi(temp));
        score[infos[0]]["-"]["-"]["-"].push_back(stoi(temp));
        
        score["-"][infos[1]][infos[2]][infos[3]].push_back(stoi(temp));
        score["-"][infos[1]][infos[2]]["-"].push_back(stoi(temp));
        score["-"][infos[1]]["-"][infos[3]].push_back(stoi(temp));
        score["-"][infos[1]]["-"]["-"].push_back(stoi(temp));
        score["-"]["-"][infos[2]][infos[3]].push_back(stoi(temp));
        score["-"]["-"][infos[2]]["-"].push_back(stoi(temp));
        score["-"]["-"]["-"][infos[3]].push_back(stoi(temp));
        score["-"]["-"]["-"]["-"].push_back(stoi(temp));
    }
    
    for(auto iter1 = score.begin(); iter1 != score.end(); iter1++){
        for(auto iter2 = iter1->second.begin(); iter2 != iter1->second.end(); iter2++){
            for(auto iter3 = iter2->second.begin(); iter3 != iter2->second.end(); iter3++){
                for(auto iter4 = iter3->second.begin(); iter4 != iter3->second.end(); iter4++){
                    sort(iter4->second.begin(), iter4->second.end());
                }
            }
        }
    }
    
    for(string s : query){
        vector<string> queries;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                queries.push_back(temp);
                temp = "";
                if(queries.size() == 4)
                    continue;
                i += 4;
                continue;
            }
            temp.push_back(s[i]);
        }
        int result = findPosition(stoi(temp), score[queries[0]][queries[1]][queries[2]][queries[3]]);
        answer.push_back(score[queries[0]][queries[1]][queries[2]][queries[3]].size() - result);
    }
    
    return answer;
}
