#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = 0;
    long long q1_sum = 0;
    long long q2_sum = 0;
    int q1_index = 0;
    int q2_index = 0;
    int size = queue1.size();
    
    for(int i : queue1){
        q1_sum += i;
    }
    
    for(int i : queue2){
        q2_sum += i;
    }
    
    while(q1_sum != q2_sum and answer <= size * 3){
        if(q1_sum < q2_sum){
            q2_sum -= queue2[q2_index];
            q1_sum += queue2[q2_index];
            queue1.push_back(queue2[q2_index]);
            q2_index++;
        }
        else{
            q1_sum -= queue1[q1_index];
            q2_sum += queue1[q1_index];
            queue2.push_back(queue1[q1_index]);
            q1_index++;
        }
        answer++;
        
    }
    
    if(answer > size * 3)
        return -1;
    
    return answer;
}
