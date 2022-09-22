#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 2100000000;
    vector<int> new_weak(weak.size() * 2, 0);
    
    for(int i = 0; i < weak.size(); i++){
        new_weak[i] = weak[i];
        new_weak[i + weak.size()] = weak[i] + n;
    }
    
    sort(dist.begin(), dist.end());
    
    do{
        for(int i = 0; i < weak.size(); i++){
            int start = new_weak[i];
            int end = new_weak[i + weak.size() - 1];
            
            for(int j = 0; j < dist.size(); j++){
                if(answer < j)
                    break;
                start += dist[j];
                if(start >= end){
                    if(answer > j + 1)
                        answer = j + 1;
                    break;
                }
                int next = upper_bound(new_weak.begin(), new_weak.end(), start) - new_weak.begin();
                start = new_weak[next];
            }
            
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 2100000000)
        return -1;
    
    return answer;
}
