#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void add_edge(vector<vector<pair<int,int>>>& adj_list, int u, int v, int w){
    adj_list[u].push_back({v,w});
}

bool check_direct_return(vector<vector<pair<int,int>>>& adj_list, int u, int v){
    for(auto j : adj_list[v]){
        if(j.first==u)
            return 1;
    }
    return 0;
}

void displayAdjList(vector<vector<pair<int,int>>>& adj_list) {
    for (int i = 0; i < adj_list.size(); i++) {
        cout << i << ": "; 
        for (auto &j : adj_list[i]) {
            cout << "dest: " << j.first << " w: " << j.second << "\t"; 
        }
        cout << endl; 
    }
}

int main(){
    
    while(1) {
        int n=0, m=0;
        cin >> n >> m;
        if (n==0 && m==0)
            break;
        int u=0, v=0, w=0, k=0, x=0, y=0;
        vector<vector<pair<int,int>>> adj_list(n);
        // vector<int> visited(n);
        // vector<int> time(n);


        for(int i=0; i<m; ++i){
            cin >> u >> v >> w;
            u--; v--;
            add_edge(adj_list, u, v, w);
        }

        cin >> k;

        for(int i=0; i<k; ++i){
            vector<int> visited(n);
            vector<int> dist(n);
            priority_queue<int, vector<int>, greater<int>> fila;
            fill(dist.begin(), dist.end(), 999999);
            fill(visited.begin(), visited.end(), false);
            cin >> x >> y;
            x--;y--;
            visited[x]=true;
            dist[x] = 0;
            
            fila.push(x);

            while(!fila.empty()){    
                for(auto j : adj_list[fila.top()]){
                    if(check_direct_return(adj_list, fila.top(), j.first))
                        dist[j.first]= dist[fila.top()] + 0;
                    if(dist[j.first] > dist[fila.top()] + j.second)
                        dist[j.first] = dist[fila.top()] + j.second;
                    if(!visited[j.first]){
                        visited[j.first] = true;
                        fila.push(j.first);
                    }
                    if(j.first == y){
                        cout << dist[j.first] << endl;
                        goto flag_exit;
                    }
                }
                fila.pop();
            }
            cout << "Nao e possivel entregar a carta" << endl;
            flag_exit:;
        }
        cout<<endl;
    }
    return 0;
}