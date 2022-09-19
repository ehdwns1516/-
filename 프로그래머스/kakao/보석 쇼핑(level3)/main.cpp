#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2, 0);
    unordered_map<string, int> gem_count;
    unordered_set<string> gem_kind(gems.begin(), gems.end());
    int gem_kind_count = gem_kind.size();
    int cur_gem_kind_count = 0;
    
    int min = gems.size();
    int start = 0;
    
    for(int i = 0; i < gems.size(); i++){
        if(gem_count[gems[i]]){
            gem_count[gems[i]]++;
            continue;
        }
        else{
            cur_gem_kind_count++;
            gem_count[gems[i]]++;
            if(cur_gem_kind_count == gem_kind_count){
                while(gem_count[gems[start]]){
                    gem_count[gems[start]]--;
                    if(!gem_count[gems[start]]){
                        cur_gem_kind_count--;
                        break;                        
                    }
                    start++;
                }
                start++;
                if(i - start < min){
                    min = i - start;
                    answer = {start, i + 1};                
                }
            }
            
        }
    }
    
    return answer;
}