/*
 https://www.acmicpc.net/problem/1463
 1로 만들기
 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

 X가 3으로 나누어 떨어지면, 3으로 나눈다.
 X가 2로 나누어 떨어지면, 2로 나눈다.
 1을 뺀다.
 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int> dp;
    dp.push_back(0);
    dp.push_back(0);
    for(int i = 2; i < N + 1; i++){
        if(!(i % 3) and !(i % 2)){
            dp.push_back(min({dp[i / 3] + 1, dp[i / 2] + 1, dp[i - 1] + 1}));
        }
        else if(!(i % 3)){
            dp.push_back(min({dp[i / 3] + 1, dp[i - 1] + 1}));
        }
        else if(!(i % 2)){
            dp.push_back(min({dp[i / 2] + 1, dp[i - 1] + 1}));
        }
        else{
            dp.push_back(dp[i - 1] + 1);
        }
    }
    cout << dp.back();
}

