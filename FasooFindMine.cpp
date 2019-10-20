#include <vector>
#include <queue>

using namespace std;

bool checkMine(vector<vector<int>> mine, vector<int> P){
    for (int i=0; i<mine.size(); i++){
        if(mine[i][0] == P[0] && mine[i][1] == P[1]){
            return true;
        }
    }
    return false;
}
int solution(int N, vector<vector<int> > mine, vector<int> P)
{
	int answer = 0;

    bool checkMap[N][N];
    memset(checkMap, false, sizeof(checkMap));
    
    queue<vector<int>> Q;
    Q.push(P);
    vector<int> tempP;
    while(!Q.empty()){
        queue<vector<int>> tempQ;
        int tempInt = 0;
        bool check = true;
        
        vector<int> popedP = Q.front();
        Q.pop();

        tempP = {P[0]+1, P[1]};
        if (tempP[0] < N){
            if(checkMine(mine, tempP)){
                check = false;
            }
            else {
                tempQ.push(tempP);
                tempInt ++;
            }
        }
        tempP = {P[0]+1, P[1]+1};
        if (tempP[0] < N && tempP[1] < N){
            if(checkMine(mine, tempP)){
                check = false;
            }
            else {
                tempQ.push(tempP);
                tempInt ++;
            }
        }
        tempP = {P[0], P[1]+1};
        if (tempP[1] < N){
            if(checkMine(mine, tempP)){
                check = false;
            }
            else {
                tempQ.push(tempP);
                tempInt ++;
            }
        }
        tempP = {P[0]-1, P[1]+1};
        if (tempP[0] >= 0 && tempP[1] < N){
            if(checkMine(mine, tempP)){
                check = false;
            }
            else {
                tempQ.push(tempP);
                tempInt ++;
            }
        }
        tempP = {P[0]-1, P[1]};
        if (tempP[0] >= 0){
            if(checkMine(mine, tempP)){
                check = false;
            }
            else {
                tempQ.push(tempP);
                tempInt ++;
            }
        }
        tempP = {P[0]-1, P[1]-1};
        if (tempP[0] >=0 && tempP[1] >=0 ){
            if(checkMine(mine, tempP)){
                check = false;
            }
            else {
                tempQ.push(tempP);
                tempInt ++;
            }
        }
        tempP = {P[0], P[1]-1};
        if (tempP[1] >= 0){
            if(checkMine(mine, tempP)){
                check = false;
            }
            else {
                tempQ.push(tempP);
                tempInt ++;
            }
        }
        tempP = {P[0]+1, P[1]-1};
        if (tempP[0] < N && tempP[1] >=0){
            if(checkMine(mine, tempP)){
                check = false;
            }
            else {
                tempQ.push(tempP);
                tempInt ++;
            }
        }

        if (check){
            answer += tempInt;
            while(!tempQ.empty()){
                Q.push(tempQ.front());
                tempQ.pop();
            }
        }
    }
	return answer;
}

