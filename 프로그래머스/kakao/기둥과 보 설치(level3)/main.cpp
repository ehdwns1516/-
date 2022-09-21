#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_possible(vector<vector<int>> &build){
    for(int i = 0; i < build.size(); i++){
        for(int j = 0; j < build[i].size(); j++){
            if(!build[i][j])
                continue;
            if(build[i][j] == 1){// 보
                if(build[i][j + 1] >= 2)
                    continue;
                if(j == 0)
                    return false;
                if((build[i][j - 1] == 1 and build[i][j + 1] == 1) or (build[i][j - 1] == 3 and build[i][j + 1] == 1))
                    continue;
            }
            else{ // 기둥
                if(i == 1)
                    continue;
                if(build[i - 1][j] >= 1)
                    continue;
                if(j == 0)
                    return false;
                if(build[i - 1][j - 1] == 1 or build[i - 1][j - 1] == 3)
                    continue;
            }
            return false;
        }
    }
    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<int>> build(n + 1, vector<int>(n + 1, 0));
    
    for(auto frame : build_frame){
        int x = frame[1];
        int y = frame[0];
        int type = frame[2];
        int command = frame[3];
        if(command){// 추가
            if(type){// 보
                build[x][y] += 1;
                if(!is_possible(build))
                    build[x][y] -= 1;
            }
            else{// 기둥
                build[x + 1][y] += 2;
                if(!is_possible(build))
                    build[x + 1][y] -= 2;
            }
        }
        else{// 삭제
            if(type){// 보
                build[x][y] -= 1;
                if(!is_possible(build))
                    build[x][y] += 1;
            }
            else{// 기둥
                build[x + 1][y] -= 2;
                if(!is_possible(build))
                    build[x + 1][y] += 2;
            }
        }
    }
    
    for(int i = 0; i < build.size(); i++){
        for(int j = 0; j < build[i].size(); j++){
            if(build[i][j] == 1){
                answer.push_back({j, i, 1});
            }
            else if(build[i][j] == 2){
                answer.push_back({j, i - 1, 0});
            }
            else if(build[i][j] == 3){
                answer.push_back({j, i, 1});
                answer.push_back({j, i - 1, 0});
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}