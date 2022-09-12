#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string converted_num = "";
    vector<string> splitted_numbers;
    while(n){
        char temp = '0';
        temp += (n % k);
        n /= k;
        converted_num.push_back(temp);
    }
    reverse(converted_num.begin(), converted_num.end());
    
    string number = "";
    for(int i = 0; i < converted_num.size(); i++){
        if(converted_num[i] == '0'){
            if(number.empty())
                continue;
            splitted_numbers.push_back(number);
            number = "";
            continue;
        }
        number.push_back(converted_num[i]);
    }
    if(!number.empty())
        splitted_numbers.push_back(number);
    
    for(int i = 0; i < splitted_numbers.size(); i++){
        long long num = stoll(splitted_numbers[i]);
        bool is_prime = true;
        
        if(num == 1)
            continue;
        else if (num == 2){
            answer++;
            continue;
        }
        for(int j = 2; j < sqrt(num) + 1; j++){
            if(num % j == 0){
                is_prime = false;
                break;
            }
        }
        if(!is_prime)
            continue;
        answer++;
    }
    
    return answer;
}
