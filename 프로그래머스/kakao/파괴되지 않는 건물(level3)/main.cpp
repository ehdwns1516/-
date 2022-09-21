#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> command_result(board.size() + 1, vector<int>(board[0].size() + 1, 0));
    
    for(int i = 0; i < skill.size(); i++){
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        
        if(type == 1){
            command_result[r1][c1] -= degree;
            command_result[r2 + 1][c2 + 1] -= degree;
            command_result[r1][c2 + 1] += degree;
            command_result[r2 + 1][c1] += degree;
        }
        else{
            command_result[r1][c1] += degree;
            command_result[r2 + 1][c2 + 1] += degree;
            command_result[r1][c2 + 1] -= degree;
            command_result[r2 + 1][c1] -= degree;
        }
    }
    
    
    for(int i = 0; i < command_result.size(); i++){
        for(int j = 1; j < command_result[i].size(); j++){
            command_result[i][j] += command_result[i][j - 1];
        }
    }
    
    for(int i = 1; i < command_result.size(); i++){
        for(int j = 0; j < command_result[i].size(); j++){
            command_result[i][j] += command_result[i - 1][j];
        }
    }
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            board[i][j] += command_result[i][j];
            if(board[i][j] > 0)
                answer++;
        }
    }
    
    return answer;
}
