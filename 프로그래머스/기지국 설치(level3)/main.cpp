#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int before = 1;
    for(int i : stations){
        if(before < i - w){
            answer += ((i - w - before) / (w * 2 + 1));
            if(((i - w - before) % (w * 2 + 1)))
                answer++;
        }
        before = i + w + 1;
    }
    
    if(before <= n){
        n++;
        answer += ((n - before) / (w * 2 + 1));
        if(((n - before) % (w * 2 + 1)))
            answer++;
    }
    
    return answer;
}
