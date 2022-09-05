#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numbers;
    vector<char> operators;
    vector<char> priority_oper;
    priority_oper.push_back('+');
    priority_oper.push_back('-');
    priority_oper.push_back('*');
    sort(priority_oper.begin(), priority_oper.end());
    
    string num = "";
    for(char c : expression){
        if('0' <= c and c <= '9'){
            num.push_back(c);
        }
        else{
            numbers.push_back(stoi(num));
            num = "";
            operators.push_back(c);
        }
    }
    numbers.push_back(stoi(num));
    
    do{
        vector<long long> num_stack = numbers;
        vector<char> oper_stack = operators;
        vector<long long> n_stack;
        vector<char> o_stack;
        
        for(char o : priority_oper){
            n_stack.push_back(num_stack[0]);
            int index = 0;
            while(num_stack.size() > index){
                if(oper_stack[index] == o){
                    long long calc_num;
                    if(o == '-'){
                        calc_num = n_stack.back() - num_stack[index + 1];
                    }
                    else if(o == '+'){
                        calc_num = n_stack.back() + num_stack[index + 1];
                    }
                    else{
                        calc_num = n_stack.back() * num_stack[index + 1];
                    }
                    n_stack.pop_back();
                    n_stack.push_back(calc_num);
                }
                else{
                    n_stack.push_back(num_stack[index + 1]);
                    o_stack.push_back(oper_stack[index]);
                }
                index++;
            }
            num_stack = n_stack;
            oper_stack = o_stack;
            if(num_stack.size() == 1)
                break;
            n_stack.clear();
            o_stack.clear();
        }
        if(abs(num_stack[0]) > answer){
            answer = abs(num_stack[0]);
        }
    }while(next_permutation(priority_oper.begin(), priority_oper.end()));
    
    return answer;
}
