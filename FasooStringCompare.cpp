#include<iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int n = s.size();
    int j = 0;
    int x = 0;
    int y = 0;
    while(j < n){
        for(int i=j; i < n; i++){
            switch (s[i])
            {
            case 'R':
                x++;
                break;
            case 'L':
                x--;
                break;
            case 'D':
                y--;
                break;
            case 'U':
                y++;
                break;
            }
            if (x==0 && y==0){
                answer++;
            }
        }
        j++;
    }
    return answer;
}