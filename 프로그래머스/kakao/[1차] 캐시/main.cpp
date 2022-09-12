#include <string>
#include <vector>
#include <unordered_set>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_set<string> caching;
    list<string> cache;
    
    for(string s : cities){
        string city = "";
        for(int i = 0; i < s.size(); i++){
            city.push_back(toupper(s[i]));
        }
        if(caching.find(city) != caching.end()){
            for(auto iter = cache.begin(); iter != cache.end(); iter++){
                if(*iter == city){
                    cache.erase(iter);
                    break;
                }
            }
            cache.push_back(city);
            answer++;
        }
        else{
            answer += 5;
            if(cacheSize == 0)
                continue;
            if(cache.size() == cacheSize){
                caching.erase(cache.front());
                cache.erase(cache.begin());
            }
            cache.push_back(city);
            caching.insert(city);
            
        }
    }
    
    return answer;
}
