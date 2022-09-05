#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(pair<double, int> &a, pair<double, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> clear_stage(N + 2, 0);
    unordered_map<int, int> processing_stage;
    vector<pair<double, int>> fail_result;
    for(int i : stages){
        clear_stage[i]++;
        processing_stage[i]++;
    }
    
    for(int i = clear_stage.size() - 2; i > -1; i--){
        clear_stage[i] += clear_stage[i + 1];
    }
    
    for(int i = 1; i < N + 1; i++){
        if((double)clear_stage[i] == 0){
            fail_result.push_back({0, i});
            continue;
        }
        fail_result.push_back({(double)processing_stage[i] / (double)clear_stage[i], i});
    }
    
    sort(fail_result.begin(), fail_result.end(), comp);
    for(pair<double, int> p : fail_result){
        answer.push_back(p.second);
    }
    return answer;
}
