/* https://www.acmicpc.net/problem/10844
 쉬운 계단 수
 45656이란 수를 보자.
 이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.
 N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    long long answer = 0;
    vector<long long> after_num_count(10, 1);
    vector<long long> before_num_count(10, 1);
    after_num_count[0] = 0;
    before_num_count[0] = 0;
    for(int i = 2; i < N + 1; i++){
        for(int j = 0; j < 10; j++){
            if(i == 2 and j == 0){
                after_num_count[0]++;
                continue;
            }
            else if(i == 2 and j == 1){
                continue;
            }
            if(j == 0){
                after_num_count[0] = before_num_count[1];
            }
            else if(j == 9){
                after_num_count[9] = before_num_count[8];
            }
            else{
                after_num_count[j] = (before_num_count[j - 1] + before_num_count[j + 1]) % 1000000000;
            }
        }
        before_num_count = after_num_count;
    }
    for(long long i : after_num_count){
        answer += i;
    }
    
    cout << answer % 1000000000;
}

