#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> order_count;
    unordered_map<int, vector<pair<int, string>>> course_spare;
    
    for(string o : orders){
        sort(o.begin(), o.end());
        for(int i : course){
            if(o.size() < i)
                break;
            
            vector<bool> combi(o.size(), false);
            for(int j = 0; j < i; j++){
                combi[j] = true;
            }
            sort(combi.begin(), combi.end());
            do{
                string menus = "";
                for(int j = 0; j < o.size(); j++){
                    if(combi[j]){
                        menus += o[j];
                    }
                }
                order_count[menus]++;
                
            }while(next_permutation(combi.begin(), combi.end()));
        }
        
    }
    
    for(auto iter = order_count.begin(); iter != order_count.end(); iter++){
        if(iter->second > 1){
            course_spare[(iter->first).size()].push_back({iter->second, iter->first});
        }
            
    }
    for(int c : course){
        if(course_spare[c].empty())
            continue;
        sort(course_spare[c].begin(), course_spare[c].end());
        int max_count = course_spare[c].back().first;
        
        while(max_count == course_spare[c].back().first){
            answer.push_back(course_spare[c].back().second);
            course_spare[c].pop_back();
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
