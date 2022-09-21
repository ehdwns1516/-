#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> graph;
vector<int> G_info;
int MAX = 0;

void dfs(map<int, bool> next, int sheep, int wolf){
    for(auto iter = next.begin(); iter != next.end(); iter++){
        if(!iter->second)
            continue;
        int vertex = iter->first;
        if(G_info[vertex]){
            if(sheep > wolf + 1){
                next[vertex] = false;
                for(int i : graph[vertex]){
                    next[i] = true;
                }
                dfs(next, sheep, wolf + 1);
                
                next[vertex] = true;
                for(int i : graph[vertex]){
                    next[i] = false;
                }
            }
        }
        else{
            next[vertex] = false;
            for(int i : graph[vertex]){
                next[i] = true;
            }
            dfs(next, sheep + 1, wolf);

            next[vertex] = true;
            for(int i : graph[vertex]){
                next[i] = false;
            }
        }
    }
    if(MAX < sheep)
        MAX = sheep;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1;
    G_info = info;
    for(auto iter : edges){
        graph[iter[0]].push_back(iter[1]);
    }
    map<int, bool> next;
    
    for(int i : graph[0]){
        next[i] = true;
    }
    
    dfs(next, 1, 0);
    return MAX;
}