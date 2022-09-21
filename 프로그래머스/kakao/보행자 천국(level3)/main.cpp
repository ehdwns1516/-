#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<int>> cases(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i < cases.size(); i++){
        if(city_map[0][i - 1] == 1)
            break;
        cases[1][i] = 1;
    }
    
    for(int i = 1; i < cases.size(); i++){
        if(city_map[i - 1][0] == 1)
            break;
        cases[i][1] = 1;
    }
    
    for(int i = 2; i < cases.size(); i++){
        for(int j = 2; j < cases[i].size(); j++){
            int x = i - 1;
            int y = j - 1;
            
            if(city_map[x][y] == 1)
                cases[i][j] = 0;
            else{
                while(x > 0 and city_map[x - 1][j - 1] == 2){
                    x--;
                }
                while(y > 0 and city_map[i - 1][y - 1] == 2){
                    y--;
                }
                cases[i][j] = (cases[x][j] + cases[i][y]) % MOD;
            }
        }
    }
    answer = cases[m][n];
    
    return answer;
}