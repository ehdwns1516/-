/*
 https://www.acmicpc.net/problem/11054
 가장 긴 바이토닉 부분 수열
 
 수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

 예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

 수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int answer = 1;
    vector<int> increase(N, 1);
    vector<int> decrease(N, 1);
    vector<int> arr(N);
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    
    for(int i = 1; i < N; i++){
        for(int j = i - 1; j > -1; j--){
            if(arr[i] > arr[j]){
                increase[i] = max({increase[j] + 1, increase[i]});
            }
        }
    
    }
    
    for(int i = N - 2; i > -1; i--){
        for(int j = i + 1; j < N; j++){
            if(arr[i] > arr[j]){
                decrease[i] = max({decrease[j] + 1, decrease[i]});
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        if(answer < increase[i] + decrease[i] - 1){
            answer = increase[i] + decrease[i] - 1;
        }
    }
    cout << answer;
}
