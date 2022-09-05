#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int comp(vector<int> &a, vector<int> &b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> sets;
    unordered_set<int> tuples;
    
    string num = "";
    bool is_outer_comma = true;
    vector<int> temp_set;
    
    for(int i = 1; i < s.size() - 1; i++){
        if(s[i] == '{'){
            temp_set.clear();
            is_outer_comma = false;
            
        }
        else if(s[i] == '}'){
            is_outer_comma = true;
            temp_set.push_back(stoi(num));
            num = "";
            sets.push_back(temp_set);
        }
        else if(s[i] == ','){
            
            if(is_outer_comma)
                continue;
            temp_set.push_back(stoi(num));
            num = "";
        }
        else if(s[i] == ' '){
            continue;
        }
        else{
            num.push_back(s[i]);
        }
    }
    
    sort(sets.begin(), sets.end(), comp);
    
    for(int i = 0; i < sets.size(); i++){
        for(int j = 0; j < sets[i].size(); j++){
            if(tuples.find(sets[i][j]) == tuples.end()){
                tuples.insert(sets[i][j]);
                answer.push_back(sets[i][j]);
            }
        }
    }
    
    return answer;
}
