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
