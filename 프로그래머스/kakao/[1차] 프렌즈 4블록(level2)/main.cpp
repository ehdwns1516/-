#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool is_break(int start_x, int start_y, vector<string> &blocks){
    unordered_set<char> check;
    for(int i = start_x; i < start_x + 2; i++){
        for(int j = start_y; j < start_y + 2; j++){
            check.insert(blocks[i][j]);
        }
    }
    if(check.size() == 1)
        return true;
    return false;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true){
        bool flag = true;
        vector<vector<bool>> broken_block(m, vector<bool>(n, false));
        
        for(int i = 0; i < board.size() - 1; i++){
            for(int j = 0; j < board[i].size() - 1; j++){
                if(board[i][j] == '-')
                    continue;
                if(is_break(i, j, board)){
                    flag = false;
                    for(int k = i; k < i + 2; k++){
                        for(int l = j; l < j + 2; l++){
                            broken_block[k][l] = true;
                        }
                    }
                }
            }
        }
        
        if(flag)
            break;
        
        vector<string> new_board(board.size(), string(board[0].size(), '-'));
        
        for(int i = 0; i < broken_block[0].size(); i++){
            int col_index = broken_block.size() - 1;
            for(int j = broken_block.size() - 1; j > -1 ; j--){
                if(!broken_block[j][i]){
                    new_board[col_index][i] = board[j][i];
                    col_index--;
                }
                else{
                    answer++;
                }
            }
        }
        board = new_board;
    }
    
    return answer;
}
