#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string(n, ' '));
    
    for(int j = 0; j < arr1.size(); j++){
        int num = arr1[j];
        for(int i = n - 1; i > -1; i--){
            if(num % 2)
                answer[j][i] = '#';
            num = num / 2;
        }
    }
    
    for(int j = 0; j < arr2.size(); j++){
        int num = arr2[j];
        for(int i = n - 1; i > -1; i--){
            if(num % 2)
                answer[j][i] = '#';
            num = num / 2;
        }
    }
    
    return answer;
}
