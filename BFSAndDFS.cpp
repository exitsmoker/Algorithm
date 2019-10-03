//
//  main.cpp
//  BFSAndDFS
//
//  Created by jaylee on 23/09/2019.
//  Copyright © 2019 jaylee. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node){
    check[node] = true;
    printf("%d ", node);
    for (int i = 0; i < a[node].size(); i++){
        int tem = a[node][i];
        if (check[tem] == false){
            dfs(tem);
        }
    }
}

void bfs(int start){
    queue<int> q;
    memset(check, false, sizeof(check));
    check[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        printf("%d ", node);
        
        for (int i = 0; i < a[node].size(); i++){
            int temp = a[node][i];
            if (check[temp] == false){
                check[temp] = true;
                q.push(temp);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    for (int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=0; i<n; i++){
        sort(a[i].begin(), a[i].end());
    }
    dfs(start);
    puts("");
    bfs(start);
    puts("");
    return 0;
}
