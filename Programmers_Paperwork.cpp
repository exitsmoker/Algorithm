#include <cstdio>
#include <string>
#include <iostream>

using namespace std;
string go(int n, int d){
    if (n == 1 && d == 1){
        return "a";
    }
    else if (n == 1 && d == -1){
        return "b";
    }
    return go(n-1, 1) + "a" + go(n-1, -1);
}
int main(){
    cout << go(3,1);
//    printf("%s\n", go(3, 1));
    return 0;
}