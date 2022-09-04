#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> str1_sets;
    unordered_map<string, int> str2_sets;
    unordered_set<string> total_set;
    
    string word = "";
    for(int i = 0; i < str1.size(); i++){
        if('a' <= str1[i] and str1[i] <= 'z'){
            str1[i] += ('A' - 'a');
            word.push_back(str1[i]);
        }
        else if('A' <= str1[i] and str1[i] <= 'Z'){
            word.push_back(str1[i]);
        }
        else{
            word.clear();
            continue;
        }
        if(word.size() == 2){
            str1_sets[word]++;
            total_set.insert(word);
            word.clear();
            word.push_back(str1[i]);
        }
    }
    
    word.clear();
    for(int i = 0; i < str2.size(); i++){
        if('a' <= str2[i] and str2[i] <= 'z'){
            str2[i] += ('A' - 'a');
            word.push_back(str2[i]);
        }
        else if('A' <= str2[i] and str2[i] <= 'Z'){
            word.push_back(str2[i]);
        }
        else{
            word.clear();
            continue;
        }
        if(word.size() == 2){
            str2_sets[word]++;
            total_set.insert(word);
            word.clear();
            word.push_back(str2[i]);
        }
    }
    
    double intersection_count = 0;
    double union_count = 0;
    for(auto iter = total_set.begin(); iter != total_set.end(); iter++){
        string word = *iter;
        if(str1_sets[word] < str2_sets[word]){
            intersection_count += str1_sets[word];
            union_count += str2_sets[word];
        }
        else{
            intersection_count += str2_sets[word];
            union_count += str1_sets[word];
        }
    }
    if(!intersection_count){
        if(union_count)
            return 0;
        return 65536;
    }
    answer = 65536 * intersection_count / union_count;
    
    return answer;
}