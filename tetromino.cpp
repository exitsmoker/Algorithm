// 5 5
// 1 2 3 4 5
// 5 4 3 2 1
// 2 3 4 5 6
// 6 5 4 3 2
// 1 2 1 2 1
#include <cstdio>
#include <algorithm>

int m, n;
int tempSum=0;
int inputMap[500][500];

using namespace std;

int main(){
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            scanf("%d", &inputMap[i][j]);
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if ((i+3)>=0 && (i+3)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i+1][j]+inputMap[i+2][j]+inputMap[i+3][j]));
            }
            if ((j+3)>=0 && (j+3)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i][j+1]+inputMap[i][j+2]+inputMap[i][j+3]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i][j+1]+inputMap[i+1][j]+inputMap[i+1][j+1]));
            }
            if ((j+2)>=0 && (j+2)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i][j+1]+inputMap[i+1][j+2]+inputMap[i][j+2]));
            }
            if ((j+2)>=0 && (j+2)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i+1][j]+inputMap[i+1][j+1]+inputMap[i+1][j+2]+inputMap[i][j+2]));
            }
            if ((j+2)>=0 && (j+2)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i+1][j]+inputMap[i][j+1]+inputMap[i][j+2]));
            }
            if ((j+2)>=0 && (j+2)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i+1][j]+inputMap[i+1][j+1]+inputMap[i+1][j+2]));
            }
            if ((j+2)>=0 && (j+2)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i][j+1]+inputMap[i+1][j+1]+inputMap[i+1][j+2]));
            }
            if ((j+2)>=0 && (j+2)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i+1][j]+inputMap[i][j+1]+inputMap[i+1][j+1]+inputMap[i][j+2]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+2)>=0 && (i+2)<n){
                tempSum = max(tempSum, (inputMap[i][j+1]+inputMap[i+1][j]+inputMap[i+1][j+1]+inputMap[i+2][j]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+2)>=0 && (i+2)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i+1][j]+inputMap[i+1][j+1]+inputMap[i+2][j+1]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+2)>=0 && (i+2)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i+1][j]+inputMap[i+1][j+1]+inputMap[i+2][j]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+2)>=0 && (i+2)<n){
                tempSum = max(tempSum, (inputMap[i+1][j]+inputMap[i+1][j]+inputMap[i+1][j+1]+inputMap[i+2][j+1]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+2)>=0 && (i+2)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i+1][j]+inputMap[i+2][j]+inputMap[i][j+1]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+2)>=0 && (i+2)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i+1][j]+inputMap[i+2][j]+inputMap[i+2][j+1]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+2)>=0 && (i+2)<n){
                tempSum = max(tempSum, (inputMap[i][j]+inputMap[i][j+1]+inputMap[i+1][j+1]+inputMap[i+2][j+1]));
            }
            if ((j+1)>=0 && (j+1)<n && (i+2)>=0 && (i+2)<n){
                tempSum = max(tempSum, (inputMap[i+2][j]+inputMap[i][j+1]+inputMap[i+1][j+1]+inputMap[i+2][j+1]));
            }
            if ((j+2)>=0 && (j+2)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i][j+1]+inputMap[i+1][j]+inputMap[i+1][j+1]+inputMap[i+1][j+2]));
            }
            if ((j+2)>=0 && (j+2)<n && (i+1)>=0 && (i+1)<n){
                tempSum = max(tempSum, (inputMap[i][j+1]+inputMap[i][j]+inputMap[i][j+2]+inputMap[i+1][j+1]));
            }
        }
    }

    printf("%d\n", tempSum);

    return 0;
}