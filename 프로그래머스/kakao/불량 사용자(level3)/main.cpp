#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

unordered_map<string, unordered_set<string>> match_id;
set<vector<string>> result;

void combination(unordered_set<string> &ban_list, vector<string> &banned_id, vector<string> ban, int depth){
    if(depth == 0){
        sort(ban.begin(), ban.end());
        result.insert(ban);
        return;
    }
        
    for(auto iter = match_id[banned_id[depth - 1]].begin(); iter != match_id[banned_id[depth - 1]].end(); iter++){
        if(ban_list.find(*iter) != ban_list.end()){
            ban_list.erase(*iter);
            ban.push_back(*iter);
            combination(ban_list, banned_id, ban, depth - 1);
            ban_list.insert(*iter);
            ban.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    unordered_set<string> ban_list;
    
    for(string s : banned_id){
        vector<int> blur_index;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*')
                blur_index.push_back(i);
        }
        for(string id : user_id){
            string temp_id = id;
            if(temp_id.size() != s.size())
                continue;
            for(int i : blur_index){
                temp_id[i] = '*';
            }
            if(temp_id == s){
                match_id[s].insert(id);
                ban_list.insert(id);
            }
        }
    }
    
    combination(ban_list, banned_id, vector<string>(),banned_id.size());
    
    return result.size();
}