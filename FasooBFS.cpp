#include<vector>
#include<queue>
#include<cstring>
#include<iostream>

using namespace std;

void dfs(int node, bool* check, vector<int>* a) {
    check[node] = true;
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (check[next] == false) {
            dfs(next, check, a);
        }
    }
}

int solution(int V, vector<vector<int>> bridge)
{
    vector<int> a[V+1];
    int m = bridge.size();

    for(int i=0; i < m; i++){
        int u, v;
        u = bridge[i][0];
        v = bridge[i][1];

        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    // for(int i=0; i < n; i++){
    //     sort(a[i].begin(), a[i].end());
    // }
    
    
    int components = 0;
    bool check[V+1];
    memset(check, false, sizeof(check));
    
    for (int i=1; i<=V; i++) {
        if (check[i] == false) {
            dfs(i, check, a);
            components += 1;
        }
    }

    //cout << components;
	// int answer = -1;
	return components -1 ;
}