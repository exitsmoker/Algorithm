#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
    public:
        vector<int>* g;
        int* check;
        int nodeSize;

        Graph(int n) {
            g = new vector<int>[n];
            check = new int[n];
            nodeSize = n;
        }
    
        void add_edge(int u, int v) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            queue<int> q;
            check[start-1] = -1;
            q.push(start);
            int number = 6;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int i=0; i < g[node].size(); i++){
                    int nextNode = g[node][i];
                    if(check[nextNode] == 0){
                        check[nextNode] = number;
                        q.push(nextNode);
                    }
                }
                number += 6;
            }

            vector<int> distances;
            for (int i=0; i<nodeSize; i++){
                if(check[i] > 0 && i != start){
                    distances.push_back(i);
                }
                else if(check[i] == 0 && i != start){
                    distances.push_back(-1);
                }
            }

            return distances;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

