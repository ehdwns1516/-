#include <string>
#include <vector>
#include <list>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer;
    vector<int> deleted;
        
    for(string s : cmd){
        char command = s[0];
        
        if(command == 'D'){
            int number = stoi(s.substr(2, s.size() - 2));
            k += number;
                        
        }
        else if(command == 'U'){
            int number = stoi(s.substr(2, s.size() - 2));
            k -= number;
        }
        else if(command == 'C'){
            deleted.push_back(k);
            n--;
            if(k == n)
                k--;
        }
        else if(command == 'Z'){
            n++;
            if(deleted.back() <= k)
                k++;
            deleted.pop_back();
        }
    }
    
    list<char> answer_list(n, 'O');
    
    auto current = answer_list.begin();
    int before = 0;
    
    while(!deleted.empty()){
        int number = deleted.back();
        deleted.pop_back();
        if(before < number){
            for(int i = 0; i < number - before; i++){
                current++;
            }
        }
        else{
            for(int i = 0; i < before - number; i++){
                current--;
            }
        }
        before = number++;
        answer_list.insert(current, 'X');
        current--;
    }
    answer = string(answer_list.begin(), answer_list.end());
    
    return answer;
}
