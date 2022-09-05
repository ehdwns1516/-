/*
 https://programmers.co.kr/learn/courses/30/lessons/42840
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

입출력 예
answers    return
[1,2,3,4,5]    [1]
[1,3,2,4,2]    [1,2,3]

입출력 예 설명
입출력 예 #1

수포자 1은 모든 문제를 맞혔습니다.
수포자 2는 모든 문제를 틀렸습니다.
수포자 3은 모든 문제를 틀렸습니다.
따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

입출력 예 #2

모든 사람이 2문제씩을 맞췄습니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int supo1[5] = {1, 2, 3, 4, 5};
    int supo2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int supo3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == supo1[i % 5])
            count1++;
        if(answers[i] == supo2[i % 8])
            count2++;
        if(answers[i] == supo3[i % 10])
            count3++;
    }
    
    vector<int> temp;
    temp.push_back(count1);
    temp.push_back(count2);
    temp.push_back(count3);
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    
    if(count1 == temp[0])
        answer.push_back(1);
    if(count2 == temp[0])
        answer.push_back(2);
    if(count3 == temp[0])
        answer.push_back(3);
    
    return answer;
}
