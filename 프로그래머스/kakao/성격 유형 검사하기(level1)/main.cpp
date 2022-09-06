#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> score;
    
    for(int i = 0; i < choices.size(); i++){
        if(choices[i] == 4)
            continue;
        else if(choices[i] > 4){
            score[survey[i][1]] += (choices[i] - 4);
        }
        else{
            score[survey[i][0]] += (4 - choices[i]);
        }
    }
        
    if(score['R'] >= score['T']){
        answer.push_back('R');
    }
    else{
        answer.push_back('T');
    }
    
    if(score['C'] >= score['F']){
        answer.push_back('C');
    }
    else{
        answer.push_back('F');
    }
    
    if(score['J'] >= score['M']){
        answer.push_back('J');
    }
    else{
        answer.push_back('M');
    }
    
    if(score['A'] >= score['N']){
        answer.push_back('A');
    }
    else{
        answer.push_back('N');
    }
    
    return answer;
}
