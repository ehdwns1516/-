#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> win_cases;
vector<int> global_info;

bool comp(vector<int> a, vector<int> b){
    int i = 0;
    while(i < a.size()){
        if(a[i] == b[i]){
            i++;
            continue;
        }
        return a[i] > b[i];
    }
}

void shoot(int remain, int depth, vector<int> result){
    if(depth == 11){
        int apeach = 0;
        int lion = 0;
        
        for(int i = 0; i < 11; i++){
            if(!global_info[i] and !result[i])
                continue;
            
            if(global_info[i] < result[i])
                lion += (10 - i);
            else
                apeach += (10 - i);
        }
        
        if(lion > apeach){
            result.push_back(lion - apeach);
            reverse(result.begin(), result.end());
            win_cases.push_back(result);
        }
    }
    else{
        if(depth == 10){
            result.push_back(remain);
            shoot(0, 11, result);
            result.pop_back();
        }
        else{
            for(int i = 0; i < remain + 1; i++){
                result.push_back(i);
                shoot(remain - i, depth + 1, result);
                result.pop_back();
            }
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    global_info = info;
    shoot(n, 0, vector<int>());
    
    sort(win_cases.begin(), win_cases.end(), comp);
    
    if(!win_cases.empty()){
        answer = win_cases[0];
        reverse(answer.begin(), answer.end());
        answer.pop_back();
    }
    else{
        answer.push_back(-1);
    }
        
    return answer;
}
