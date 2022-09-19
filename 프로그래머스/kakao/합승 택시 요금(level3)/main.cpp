#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int INF = 210000000;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    
    for(int i = 0; i < fares.size(); i++){
        cost[fares[i][0] - 1][fares[i][1] - 1] = fares[i][2];
        cost[fares[i][1] - 1][fares[i][0] - 1] = fares[i][2];
    }
    
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++)
                if (cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
    
    if(cost[s - 1][a - 1] + cost[a - 1][b - 1] < cost[s - 1][b - 1] + cost[b - 1][a - 1])
        answer = cost[s - 1][a - 1] + cost[a - 1][b - 1];
    else
        answer = cost[s - 1][b - 1] + cost[b - 1][a - 1];
    
    if(answer > cost[s - 1][a - 1] + cost[s - 1][b - 1])
        answer = cost[s - 1][a - 1] + cost[s - 1][b - 1];
    
    for(int i = 0; i < n; i++){
        if(cost[s - 1][i] + cost[i][a - 1] + cost[i][b - 1] < answer)
            answer = cost[s - 1][i] + cost[i][a - 1] + cost[i][b - 1];
    }
    
    
    return answer;
}