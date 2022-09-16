#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string total_nums = "";
    
    int cur_decimal = 0;
    while(total_nums.size() < (t - 1) * m + p){
        string temp_num = "";
        int temp_decimal = cur_decimal;
        do{
            if(temp_decimal % n > 9)
                temp_num.push_back('A' + (temp_decimal % n - 10));
            else
                temp_num.push_back('0' + (temp_decimal % n));
            temp_decimal /= n;
        }while(temp_decimal);
        reverse(temp_num.begin(), temp_num.end());
        total_nums += temp_num;
        cur_decimal++;
    }
    
    for(int i = p - 1; i < (t - 1) * m + p; i += m){
        answer.push_back(total_nums[i]);
    }
    
    return answer;
}