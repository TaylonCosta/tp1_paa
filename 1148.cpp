#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>


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

int main(){
    while(1) {
        int n=0, m=0;
        cin >> n >> m;
        if (n==0 && m==0)
            break;
        int u=0, v=0, w=0, k=0, x=0, y=0;
        vector<vector<pair<int,int>>> adj_list(n);

        for(int i=0; i<m; ++i){
            cin >> u >> v >> w;
            u--; v--;
            add_edge(adj_list, u, v, w);
        }

        cin >> k;
        for(int i=0; i<k; ++i){
            vector<int> dist(n);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;
            fill(dist.begin(), dist.end(), 999999);
            cin >> x >> y;
            x--;y--;

            dist[x] = 0;
            
            fila.push({0,x});

            while(!fila.empty()){
                auto [current_dist, current] = fila.top();
                fila.pop();
                if (current_dist > dist[current]) continue;
                for(auto j : adj_list[current]){
                    int cost = j.second;
                    if(check_direct_return(adj_list, current, j.first))
                        cost = 0;
                    if(dist[j.first] > dist[current] + cost){
                        dist[j.first] = dist[current] + cost;
                        fila.push({dist[j.first], j.first});
                    }

                }
            }
            if(dist[y]==999999)
                cout << "Nao e possivel entregar a carta" << endl;
            else
                cout << dist[y] << endl;
        }
        cout<<endl;
    }
    return 0;
}