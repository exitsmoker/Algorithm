#include<iostream>
#include<string>
using namespace std;

int solution(string s)
{
    
    int answer = 0;
    int n = s.size();
    int j=2;
    while(j <= n){
        for(int i=0; i<= n-j; i++){
            int x = 0;
            int y = 0;
            for(int z=0; z < z+j; z++){
                switch (s[z])
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
            }
            if (x==0 && y==0){
                answer++;
            }
        }
        j += 2;
    }
    return answer;
}