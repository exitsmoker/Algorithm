#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    vector<int> resultIds;
 
    for (int i=0; i < ids.size(); i++){
        if (ids[i] == val){
            resultIds.push_back(i);
        }
    }

    if (resultIds.size() < 2){
        return -1;
    }

    vector<int> graph[graph_nodes];
    int check[graph_nodes];
    memset(check, -1, sizeof(check));

    for (int i=0; i < graph_from.size(); i++){
        graph[graph_from[i]-1].push_back(graph_to[i]-1);
        graph[graph_to[i]-1].push_back(graph_from[i]-1);
    }

    queue<int> q;
    int currentPath = -1;
    for (auto x : resultIds){
        q.push(x);
        check[x] = 0;
    }
    
    while(!q.empty()){
        int node = q.front(); 
        q.pop();
        
        for(int i=0; i < graph[node].size(); i++){
            int nextNode = graph[node][i];
            // if (check[nextNode] == 1){
            //     currentPath = min(currentPath, check[node]);
            // }
            // else if (check[nextNode] == 0){
            //     q.push(nextNode);
            //     check[nextNode] = check[node] + 1;

            // }
            if (check[nextNode] >= 0){
                if(check[nextNode] == check[node]){
                    currentPath == -1 ? currentPath = check[nextNode] * 2 + 1 : min(currentPath*2+1, currentPath);
                }
                else if (check[nextNode] == check[node] + 1){
                    currentPath == -1 ? currentPath = check[nextNode] * 2 : min(currentPath*2, currentPath);
                }
            }
            else {
                q.push(nextNode);
                check[nextNode] = check[node] + 1;
            }
        }
    }

    return currentPath;
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);
    
    cout << ans << "\n";
//    fout << ans << "\n";

//    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
