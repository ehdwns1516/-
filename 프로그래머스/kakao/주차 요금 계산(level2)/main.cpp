#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, int> parking_time;
    map<string, int> total_time;
    unordered_set<string> parking_car;
    
    for(string s : records){
        int time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        string car_number = s.substr(6, 4);
        string command = s.substr(11);
        if(command == "IN"){
            parking_car.insert(car_number);
            parking_time[car_number] = time;
        }
        else if(command == "OUT"){
            parking_car.erase(car_number);
            total_time[car_number] += (time - parking_time[car_number]);
        }
    }
    
    for(auto iter = parking_car.begin(); iter != parking_car.end(); iter++){
        int time = 60 * 24 - 1 - parking_time[*iter];
        total_time[*iter] += time;
    }
    
    for(auto iter = total_time.begin(); iter != total_time.end(); iter++){
        if(iter->second - fees[0] <= 0)
            answer.push_back(fees[1]);
        else{
            if((iter->second - fees[0]) % fees[2])
                answer.push_back(fees[1] + (iter->second - fees[0]) / fees[2] * fees[3] + fees[3]);
            else
                answer.push_back(fees[1] + (iter->second - fees[0]) / fees[2] * fees[3]);
        }
    }
    
    return answer;
}