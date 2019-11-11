#include <stdio.h>

using namespace std;

int main(){
    long a = 1;
    a = (a << 32) - 1;
    printf("%ld\n", a);

    return 0;
}