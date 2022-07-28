/*
 https://www.acmicpc.net/problem/9251
 LCS
 LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
 
 예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    
    for(int i = 1; i < s1.size() + 1; i++){
        for(int j = 1; j < s2.size() + 1; j++){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
        }
    }
    
    cout << dp[s1.size()][s2.size()];
    
}
