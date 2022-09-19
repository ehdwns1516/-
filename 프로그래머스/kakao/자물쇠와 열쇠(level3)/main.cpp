#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> board){
    vector<vector<int>> temp(board.size(), vector<int>(board[0].size(), 0));
        
    for(int i = 0; i < board.size() ; i++){
        for(int j = 0; j < board[i].size(); j++){
             temp[i][j] = board[board[i].size() - j -1][i];
        }
    }
    return temp;
}

bool check(vector<vector<int>> board, vector<vector<int>> key, int x, int y){
    for(int i = 0; i < key.size(); i++){
        for(int j = 0; j < key[0].size(); j++){
            board[i + x][j + y] += key[i][j];
        }
    }
    
    for(int i = 0; i < board.size() / 3; i++){
        for(int j = 0; j < board[0].size() / 3; j++){
            if(board[board.size() / 3 + i][board[0].size() / 3 + j] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<int>> board(lock.size() * 3, vector<int>(lock[0].size() * 3, 0));
    
    for(int i = 0; i < lock.size(); i++){
        for(int j = 0; j < lock[0].size(); j++){
            board[lock.size() + i][lock.size() + j] = lock[i][j];
        }
    }
    
    
    for(int i = 0; i < 4; i++){
        key = rotate(key);
        for(int i = 0; i < lock.size() * 2; i++){
            for(int j = 0; j < lock[0].size() * 2; j++){
                if(check(board, key, i, j))
                    return true;
            }    
        }
    }
    
    return false;

}