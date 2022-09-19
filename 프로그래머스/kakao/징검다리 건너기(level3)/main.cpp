#include <string>
#include <vector>

using namespace std;

bool canCross(vector<int> stones, int k, int friends){
    int count = 0;
    for(int i : stones){
        if(i < friends)
            count++;
        else
            count = 0;
        if(count == k)
            return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int left = 0;
    int right = 200000000;
    
    while(left <= right){
        int mid = (left + right) / 2;
        if(canCross(stones, k, mid)){
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    
    if(!left)
        return 0;
    
    return left - 1;
}