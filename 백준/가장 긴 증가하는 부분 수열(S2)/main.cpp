/*
https://www.acmicpc.net/problem/11053
가장 긴 증가하는 부분 수열
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int answer = 1;
    vector<int> arr;
    vector<int> dp(N, 1);
    

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    for(int i = 1; i < N; i++){
        for(int j = i - 1; j > -1; j--){
            if(arr[i] > arr[j])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
        if(dp[i] > answer)
            answer = dp[i];
    }
    
    cout << answer;
}