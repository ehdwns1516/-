#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int vertex;
    int y;
    int x;
    node* left = NULL;
    node* right = NULL;
};

bool comp(node a, node b){
    if(a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

void addNode(node* parent, node* child){
    if(parent->x < child->x){
        if(parent->right == NULL){
            parent->right = child;
            return;
        }
        addNode(parent->right, child);
    }
    else{
        if(parent->left == NULL){
            parent->left = child;
            return;
        }
        addNode(parent->left, child);
    }
}

void PreOrder(node* Node, vector<int> &result){
    if(Node == NULL)
        return;
    result.push_back(Node->vertex);
    PreOrder(Node->left, result);
    PreOrder(Node->right, result);
}

void PostOrder(node* Node, vector<int> &result){
    if(Node == NULL)
        return;
    PostOrder(Node->left, result);
    PostOrder(Node->right, result);
    result.push_back(Node->vertex);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<node> nodes;
    
    for(int i = 0; i < nodeinfo.size(); i++){
        node *temp = new node();
        temp->vertex = i + 1;
        temp->x = nodeinfo[i][0];
        temp->y = nodeinfo[i][1];
        nodes.push_back(*temp);
    }
    
    sort(nodes.begin(), nodes.end(), comp);
    
    for(int i = 1; i < nodes.size(); i++){
        addNode(&nodes[0], &nodes[i]);
    }
    
    vector<int> result;
    PreOrder(&nodes[0], result);
    answer.push_back(result);
    result.clear();
    PostOrder(&nodes[0], result);
    answer.push_back(result);
    
    return answer;
}
