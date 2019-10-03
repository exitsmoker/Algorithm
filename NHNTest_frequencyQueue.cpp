#include<queue> 
#include<cstdio>
#include<cstring>
#include<map>

using namespace std; 
  
map<int, int> freqMap; 
map<int, queue<int> > setMap; 

int maxfreq = 0; 
  
void push(int x) 
{
    //TODO 
    int freq = freqMap[x] + 1; 
  
    freqMap[x]= freq; 
  
    if (freq > maxfreq) 
        maxfreq = freq; 
  
    setMap[freq].push(x); 
} 
  
int pop() 
{ 
  
    int top = setMap[maxfreq].front(); 
    setMap[maxfreq].pop(); 
  
    freqMap[top]--; 
  
    if (setMap[maxfreq].size() == 0) 
        maxfreq--; 
    return top; 
} 
  
int main() 
{ 
    int n, m;
    char b[100];

    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%s", b);
        if(!strcmp(b,"enqueue")){
            scanf("%d", &m);
            push(m);
        }
        else {
            printf("%d ", pop());
        }
    }
    printf("\n");
    return 0; 
} 
  