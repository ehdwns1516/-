// kruskal으로 MST 만든 것
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int MIN = 210000000;
int top_number = 0;
vector<int> check;
unordered_map<int, vector<pair<int, int>>> course;
unordered_set<int> is_summit;
unordered_set<int> is_gate;

int getParent(int node){
    if(check[node]==node) return node;
    return getParent(check[node]);
}

void unionParent(int node1, int node2){
    node1 = getParent(node1);
    node2 = getParent(node2);
    if(node1 < node2) check[node2] = node1;
    else check[node1] = node2;
}

bool isCycle(int node1, int node2){
    node1 = getParent(node1);
    node2 = getParent(node2);
    if(node1 == node2) return true;
    else return false;
}

void getMinCourse(int cur, int before, int dest, int max_cost){
    if(cur == dest){
        if(max_cost < MIN){
            MIN = max_cost;
            top_number = dest;
        }
        else if(max_cost == MIN){
            if(top_number > dest)
                top_number = dest;
        }
    }
    for(pair<int, int> p : course[cur]){
        auto[next, cost] = p;
        if(next == before)
            continue;
        if(cost > MIN)
            continue;
        if(is_gate.find(next) != is_gate.end())
            continue;
        if(next != dest and is_summit.find(next) != is_summit.end())
            continue;
        
        if(max_cost < cost)
            getMinCourse(next, cur, dest, cost);
        else
            getMinCourse(next, cur, dest, max_cost);
    }
}

bool comp(vector<int> p1, vector<int> p2){
    return p1[2] < p2[2];
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    sort(paths.begin(), paths.end(), comp);
    sort(gates.begin(), gates.end());
    sort(summits.begin(), summits.end());
    
    for(int i = 0; i < n + 1; i++){
        check.push_back(i);
    }
    
    for(int g : gates){
        is_gate.insert(g);
    }
    
    for(int s : summits){
        is_summit.insert(s);
    }
    
    for(auto p : paths){
        if(!isCycle(p[0], p[1])){
            course[p[0]].push_back({p[1], p[2]});
            course[p[1]].push_back({p[0], p[2]});
            unionParent(p[0], p[1]);
            // cout << p[0] << ':' << p[1] << endl;
        }
    }
    
    for(int g : gates){
        for(int s : summits){
            getMinCourse(g, 0, s, 0);
        }
    }
    
    answer.push_back(top_number);
    answer.push_back(MIN);
    
    return answer;
}

// prim으로 MST 만든 것
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <iostream>

using namespace std;

unordered_map<int, vector<pair<int, int>>> MST;
unordered_map<int, vector<pair<int, int>>> edges;
unordered_set<int> visited;
unordered_set<int> is_gate;
unordered_set<int> is_summit;

int min_cost = 210000000;
int min_summit = 0;

void findCourse(int before, int curr, int cost){
    if(is_summit.find(curr) != is_summit.end()){
        if(min_cost > cost){
            min_cost = cost;
            min_summit = curr;
        }
        else if(min_cost == cost){
            if(min_summit > curr)
                min_summit = curr;
        }
        return;
    }
    
    for(int i = 0; i < MST[curr].size(); i++){
        auto [next_cost, next] = MST[curr][i];
        if(next == before)
            continue;
        if(is_gate.find(next) != is_gate.end())
            continue;
        if(cost < next_cost)
            findCourse(curr, next, next_cost);
        else
            findCourse(curr, next, cost);
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    for(auto p : paths){
        edges[p[0]].push_back({p[2], p[1]});
        edges[p[1]].push_back({p[2], p[0]});
    }
    
    for(int g : gates){
        is_gate.insert(g);
    }
    
    for(int s : summits){
        is_summit.insert(s);
    }
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> PQ;

    for(int i = 0; i < edges[1].size(); i++){
        int curr = 1;
        auto [cost, next] = edges[1][i];
        PQ.push({cost, 1, next});
    }
    visited.insert(1);
    
    while(!PQ.empty()){
        auto [c, before, curr] = PQ.top();
        PQ.pop();
        if(visited.find(curr) != visited.end())
            continue;
        visited.insert(curr);
        MST[curr].push_back({c, before});
        MST[before].push_back({c, curr});
        
        for(int i = 0; i < edges[curr].size(); i++){
            auto [cost, next] = edges[curr][i];
            if(visited.find(next) == visited.end()){
                PQ.push({cost, curr, next});
            }
        }
    }
        
    for(auto iter = is_gate.begin(); iter != is_gate.end(); iter++){
        findCourse(0, *iter, 0);
    }
    
    answer.push_back(min_summit);
    answer.push_back(min_cost);
    
    return answer;
}
