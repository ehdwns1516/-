#include <iostream>
#include <vector>
using namespace std;

int max(int &a, int &b){
    if(a > b)
        return a;
    return b;
}

int solution(vector<int> sticker)
{
    int answer = 0;
    vector<int> dp1(sticker.size(), 0);
    vector<int> dp2(sticker.size() - 1, 0);
    
    if(sticker.size() == 1)
        return sticker.back();
    
    dp1[1] = sticker[1];
    dp2[0] = sticker[0];
    dp2[1] = dp2[0];
    
    for(int i = 2; i < sticker.size(); i++){
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }
    for(int i = 2; i < sticker.size() - 1; i++){
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }
    
    answer = max(dp1.back(), dp2.back());
    
    return answer;
}
