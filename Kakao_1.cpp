#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

stack<int> boardStack[30];
stack<int> result;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    for (int i = board.size()-1; i >= 0; i--){
        for (int j = 0; j < board[i].size(); i++){
            boardStack[j].push(board[i][j]);
        }
    }
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < boardStack[i].size(); j++){
            boardStack[i].pop();
        }
    }
    for (int i = 0; i < moves.size(); i++){
        if(boardStack[moves[i]-1].empty()){

        }
        else{
            if(!result.empty() && (result.top() == boardStack[moves[i]-1].top())){
                result.pop();
                answer++;
            }
            else {
                result.push(boardStack[moves[i]-1].top());
                boardStack[moves[i]-1].pop();
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> tempBoard = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> tempList = {1,5,3,5,1,2,1,4};
    solution(tempBoard, tempList);
    return 0;
}