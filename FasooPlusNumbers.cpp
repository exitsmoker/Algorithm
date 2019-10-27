#include<vector>
using namespace std;

vector<int> solution(vector<int> numbers, vector<int> start, vector<int> finish)
{
    int n = numbers.size();
    int a[n];

    for (int i = 0; i<n; i++){
        if (i==0){
            a[i] = numbers[i];
        }
        else {
            a[i] = a[i-1] + numbers[i];
        }
    }

    int m = start.size();

    vector<int> answer;
    for (int i=0; i<m; i++){
        int tempInt = a[finish[i]] - a[start[i]-1];
        answer.push_back(tempInt);
    }
    

    return answer;
}