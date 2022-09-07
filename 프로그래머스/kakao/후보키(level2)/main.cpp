#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int att_size = relation[0].size();
    unordered_map<int, list<unordered_set<int>>> keys;
    
    for(int i = 1; i < att_size + 1; i++){
        vector<bool> check(att_size, false);
        for(int j = 0; j < i; j++){
            check[j] = true;
        }
        sort(check.begin(), check.end());
        
        do{
            unordered_set<int> temp;
            for(int j = 0; j < check.size(); j++){
                if(check[j])
                    temp.insert(j);
            }
            keys[i].push_back(temp);
            answer++;
        }while(next_permutation(check.begin(), check.end()));
    }
        
    for(int i = 1; i < att_size + 1; i++){
        auto iter1 = keys[i].begin();
        while(iter1 != keys[i].end()){
            unordered_set<string> items;
            for(int j = 0; j < relation.size(); j++){
                string temp = "";
                for(auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++){
                    temp += relation[j][*iter2];
                }
                items.insert(temp);
            }
            if(items.size() == relation.size()){
                for(int j = i + 1; j < att_size + 1; j++){
                    auto iter3 = keys[j].begin();
                    while(iter3 != keys[j].end()){
                        bool flag = true;
                        for(auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++){
                            if((*iter3).find(*iter2) == (*iter3).end()){
                                flag = false;
                                break;
                            }
                        }
                        if(flag){
                            iter3 = keys[j].erase(iter3);
                            answer--;
                        }
                        else{
                            iter3++;
                        }
                    }
                }
                iter1++;
            }
            else{
                iter1 = keys[i].erase(iter1);
                answer--;
            }
        }
    }
    
    return answer;
}
