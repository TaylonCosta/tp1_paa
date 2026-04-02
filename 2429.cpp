#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>


using namespace std;


void add_edge(vector<vector<int>>& adj_list, int u, int v){
    adj_list[u].push_back(v);
}

void dfs(vector<vector<int>>& adj_list, vector<bool> &visited, int u){
    visited[u] = true;
    for(int i : adj_list[u]){
        if(!visited[i]){
            dfs(adj_list, visited, i);
        }
    }
}

bool check_all_visited(vector<bool> &visited){
    for(int i=0; i<visited.size(); ++i){
        if(!visited[i])
            return false;
    }
    return true;
}

int main() {
    int T=0, cont=0;
    int n=0, u=0, v=0;
    bool connected = false;
    cin >> n;
    vector<bool> visited(n);
    vector<vector<int>> adj_list(n), reverse_adj(n);

    for(int i=0; i<n; ++i){
        visited[i]=false;
        cin >> u >> v;
        u--;v--;
        add_edge(adj_list, u, v);
        add_edge(reverse_adj, v, u);
    }

    dfs(adj_list, visited, 0);

    connected = check_all_visited(visited);

    if (!connected)
        cout << "N" <<endl;
    else{
        fill(visited.begin(), visited.end(), false);
        dfs(reverse_adj, visited, 0);
        connected = check_all_visited(visited);
        if (!connected)
            cout << "N" <<endl;
        else 
            cout << "S" <<endl;
    }

    return 0;
}