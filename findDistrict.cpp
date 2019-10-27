#include <cstdio>
#include <algorithm>

int n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int m[25][25];
int che[25][25];
int ans[25*25] = {0};

using namespace std;

void dfs(int i, int j, int cnt){
    che[i][j] = cnt;
    for(int k=0; k<4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            //printf("Test1\n");
            if(che[nx][ny] == 0 && m[nx][ny] == 1){
                //printf("Test2\n");
                dfs(nx, ny, cnt);
            }
        }
    }
}
int main(){
    //     7
    // 0110100
    // 0110101
    // 1110101
    // 0000111
    // 0100000
    // 0111110
    // 0111000
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &m[i][j]);
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j] == 1 && che[i][j] == 0){
                dfs(i, j, ++cnt);
            }
        }
    }

    printf("%d\n", cnt);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
//            printf("%d", che[i][j]);
            //printf("%d", m[i][j]);
            if(che[i][j] != 0){
                ans[che[i][j]]++;
            }            
        }
 //       printf("\n");
    }

    sort(ans+1, ans+cnt+1);
    for(int i=1; i<cnt+1; i++){
        printf("%d\n",ans[i]);
    }
}