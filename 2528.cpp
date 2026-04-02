#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void add_edge(vector<vector<int>>& adj_list, int u, int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void displayAdjList(vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": "; 
        for (int j : adj[i]) {
            cout << j << " "; 
        }
        cout << endl; 
    }
}

int main(){
    int n=0, m=0;
    while(cin >> n >> m) {
        int u=0, v=0, c=0, r=0, e=0;
        vector<vector<int>> adj_list(n);
        queue<int> fila;
        vector<int> dist(n, 0);
        vector<bool> visited(n);

        fill(visited.begin(), visited.end(), false);

        for(int i=0; i<m; ++i){
            cin >> u >> v;
            u--; v--;
            add_edge(adj_list, u, v);
        }

        cin >> c >> r >> e;
        c--,r--;e--;
        visited[e] = true;

        fila.push(c);
        visited[c]=true;

        while (1){
            for (int i : adj_list[fila.front()]){
                if (!visited[i]){
                    fila.push(i);
                    dist[i] = dist[fila.front()] + 1;
                    visited[i] = true;
                    if(i == r){
                        cout << dist[i] << endl;
                        goto flag_exit;
                    }
                }
            }
            fila.pop();
        }
        flag_exit:;
    }
    return 0;
}