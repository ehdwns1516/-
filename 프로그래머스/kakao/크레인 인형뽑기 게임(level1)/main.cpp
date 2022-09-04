#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> stack;
    for(int i : moves){
        for(int j = 0; j < board.size(); j++){
            if(board[j][i - 1]){
                if(!stack.empty() and board[j][i - 1] == stack.back()){
                    answer += 2;
                    stack.pop_back();
                }
                else{
                    stack.push_back(board[j][i - 1]);
                }
                board[j][i - 1] = 0;                
                break;
            }
        }
    }
    return answer;
}