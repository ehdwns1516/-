#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<vector<int>>> cost(board.size(), vector<vector<int>>(board[0].size(), vector<int>(2, 210000000)));
    queue<tuple<int, int, int, int>> BFS;
    cost[0][0][0] = 0;
    cost[0][0][1] = 0;
    BFS.push({0, 0, 0, 0});
    BFS.push({0, 0, 1, 0});
    
    while(!BFS.empty()){
        auto [x, y, direc, cur_cost] = BFS.front();
        BFS.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 or ny < 0 or nx > board.size() - 1 or ny > board.size() - 1)
                continue;
            if(board[nx][ny])
                continue;
            
            if((i + 1) % 2 == direc){
                if(cur_cost + 100 <= cost[nx][ny][(i + 1) % 2]){
                    cost[nx][ny][(i + 1) % 2] = cur_cost + 100;
                    BFS.push({nx, ny, (i + 1) % 2, cur_cost + 100});
                }
            }
            else{
                if(cur_cost + 600 <= cost[nx][ny][(i + 1) % 2]){
                    cost[nx][ny][(i + 1) % 2] = cur_cost + 600;
                    BFS.push({nx, ny, (i + 1) % 2, cur_cost + 600});
                }
            }
        }
    }
    
    answer = cost[board.size() - 1][board[0].size() - 1][0];
    if(answer > cost[board.size() - 1][board[0].size() - 1][1])
    answer = cost[board.size() - 1][board[0].size() - 1][1];
    
    
    return answer;
}