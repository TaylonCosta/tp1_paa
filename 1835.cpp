#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

//Achar o numero de componeneted conexas

using namespace std;

struct Node
{
    int idx;
    vector<int> adj;
    bool queued = false;
};

void add_edge(vector<Node>& adj_list, int x, int y){
    adj_list[x-1].adj.push_back(y-1);
    adj_list[y-1].adj.push_back(x-1);
}

int check_enqueue(vector<Node>& adj_list){
    for(int i=0; i<adj_list.size(); ++i){
        if(!adj_list[i].queued)
            return i;
    }
    return -1;
}

int main() {
    int T=0, cont=0;
    int n=0, m=0, x=0, y=0;
    queue<int> fila;
    vector<Node> adj_list;

    cin >> T;
    while (T)
    {   
        cont++;
        int comp_conex=0;
        cin >> n >> m;
        for(int i=1; i<=n; ++i){
            Node node;
            node.idx = i;
            adj_list.push_back(node);
        }
        for(int j=0;j<m; ++j){
            cin >> x >> y;                
            add_edge(adj_list, x, y);
        }
        while(1){
            int aux = check_enqueue(adj_list);
            if(aux != -1){
                comp_conex++;
                fila.push(aux);
                adj_list[aux].queued = true;
                while (!fila.empty()){
                    int current = fila.front();
                    fila.pop();
                    for (int i = 0; i < adj_list[current].adj.size(); ++i) {
                        int prox = adj_list[current].adj[i];
                        if (!adj_list[prox].queued) {
                            fila.push(prox);
                            adj_list[prox].queued = true;
                        }
                    }
                }
            }
            else
                break;
        }

        if (comp_conex <= 1)
            cout << "Caso #" << cont << ": a promessa foi cumprida" << endl;
        else
            cout << "Caso #" << cont << ": ainda falta(m) " << comp_conex-1 << " estrada(s)" << endl;
        T--;
        adj_list.clear();
    }
    
    return 0;
}