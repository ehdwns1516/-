#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2, 0);
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> BFS;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] == 0)
                visited[i][j] = true;
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                int color = picture[i][j];
                int count = 0;
                BFS.push({i, j});
                while(!BFS.empty()){
                    int x = BFS.front().first;
                    int y = BFS.front().second;
                    BFS.pop();
                    visited[x][y] = true;
                    count++;
                    for(int k = 0; k < 4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        
                        if(nx < 0 or ny < 0 or nx >= m or ny >= n)
                            continue;
                        if(visited[nx][ny])
                            continue;
                        if(color != picture[nx][ny])
                            continue;
                        
                        visited[nx][ny] = true;
                        BFS.push({nx, ny});
                    }
                }
                answer[0]++;
                if(count > answer[1])
                    answer[1] = count;
            }
                
        }
    }
    return answer;
}
