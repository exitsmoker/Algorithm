//
//  main.cpp
//  ConnectedComponent
//
//  Created by jaylee on 27/09/2019.
//  Copyright © 2019 jaylee. All rights reserved.
//

#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> a[1001];
int check[1001];
int numberOfComponent = 0;

void bfs(int start){
    queue<int> q;
    check[start] = numberOfComponent;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i < a[node].size(); i++){
            int next = a[node][i];
            if ( check[next] == 0 ){
                check[next] = numberOfComponent;
                q.push(next);
            }
        }
    }
}
int main() {
    int m, n;
    scanf("%d %d", &n, &m);
    for(int i=0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for(int i=0; i < n; i++){
        sort(a[i].begin(), a[i].end());
    }
    
    memset(check, 0, sizeof(check));
    
    for(int i=0; i < n; i++){

        if(!a[i].empty() && check[i] == 0){
            numberOfComponent++;
            bfs(i);
        }
    }
    
    printf("%d\n", numberOfComponent);
    return 0;
}
