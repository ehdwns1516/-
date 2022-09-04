#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool checkSafe(int depth, vector<string> &place, int x, int y, int default_x, int default_y){
    for(int i = 0; i < 4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx < 0 or ny < 0 or nx > place.size() - 1 or ny > place[0].size() - 1)
            continue;
        if(nx == default_x and ny == default_y)
            continue;
        if(place[nx][ny] == 'P')
            return false;
        if(!depth and place[nx][ny] == 'O'){
            if(!checkSafe(1, place, nx, ny, x, y))
                return false;
        }
    }
    return true;
}

bool checkDistance(vector<string> &place){
    for(int i = 0; i < place.size(); i++){
        for(int j = 0; j < place[i].size(); j++){
            if(place[i][j] == 'P'){
                if(!checkSafe(0, place, i, j, -1, -1))
                    return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < places.size(); i++){
        if(checkDistance(places[i]))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}