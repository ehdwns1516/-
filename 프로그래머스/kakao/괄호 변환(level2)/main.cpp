#include <string>
#include <vector>

using namespace std;

string splitBracket(string v){
    if(v.empty())
        return "";
    
    int split_count = 1;
    
    if(v[0] == '('){
        string u = "(";
        int count = 1;
        
        for(int i = 1; i < v.size(); i++){
            if(count == 0)
                break;
            if(v[i] == '(')
                count++;
            else if(v[i] == ')')
                count--;
            u += v[i];
            split_count++;
        }
        return u + splitBracket(v.substr(split_count, v.size() - split_count));
    }
    else{
        string u = "";
        int count = -1;
        
        for(int i = 1; i < v.size(); i++){
            if(count == 0)
                break;
            if(v[i] == '('){
                count++;
                u += ')';
            }
                
            else if(v[i] == ')'){
                count--;
                u += '(';
            }
            split_count++;
        }
        u.pop_back();
        
        return '(' + splitBracket(v.substr(split_count, v.size() - split_count)) + ')' + u;
    }
    return "";
}

string solution(string p) {
    string answer = "";
    answer = splitBracket(p);
    return answer;
}
