#include <string>
#include <vector>

using namespace std;

int rotate(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2){
    int MIN = matrix[x1][y1];
    int temp = matrix[x1][y1];
    
    for(int i = x1; i < x2; i++){
        matrix[i][y1] = matrix[i + 1][y1];
        if(MIN > matrix[i][y1])
            MIN = matrix[i][y1];
    }
    
    for(int i = y1; i < y2; i++){
        matrix[x2][i] = matrix[x2][i + 1];
        if(MIN > matrix[x2][i])
            MIN = matrix[x2][i];
    }
    
    for(int i = x2; i > x1; i--){
        matrix[i][y2] = matrix[i - 1][y2];
        if(MIN > matrix[i][y2])
            MIN = matrix[i][y2];
    }
    
    for(int i = y2; i > y1; i--){
        matrix[x1][i] = matrix[x1][i - 1];
        if(MIN > matrix[x1][i])
            MIN = matrix[x1][i];
    }
    
    matrix[x1][y1 + 1] = temp;
    return MIN;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));
    
    int count = 1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = count++;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        int result = rotate(matrix, queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1);
        
        
        answer.push_back(result);
    }
    
    return answer;
}