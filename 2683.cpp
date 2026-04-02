#include <iostream>
#include <algorithm>

using namespace std;


struct Node{
    int index;
    Node *prox;
};

struct Edge{
    Node* saida;
    Node* dest;
    int peso;
};

void make_set(Node &node){
    node.prox=&node;
}

bool find_set(Node *node_a, Node *node_b){
    Node *aux_a = node_a, *aux_b = node_b;


    while(aux_a != aux_a->prox){
        aux_a = aux_a->prox;
    }

    while(aux_b != aux_b->prox){
        aux_b = aux_b->prox;
    }

    if (aux_a == aux_b)
        return 1;
    else
        return 0;
}


void make_union(Node *node_a, Node *node_b){

    while(node_a->prox != node_a){
        node_a = node_a->prox;
    };

    while(node_b->prox != node_b){
        node_b = node_b->prox;
    };

    node_b->prox = node_a;
}


bool compare( Edge a, Edge b){
    if(a.peso < b.peso)
        return 1;
    else
        return 0;
}

int main(){

        int m=0, n=0, x=0, y=0, z=0, menor_dist=0, maior_dist=0;
        cin >> n;

        Edge edge[n];
        Node* node = new Node[n];

        for(int i=0; i<n; ++i){
            node[i].index = i;
            make_set(node[i]);
        }

        for(int i=0; i<n; ++i){
            cin >> x >> y >> z;
            x--;y--;
            edge[i].saida = &node[x];
            edge[i].dest = &node[y];
            edge[i].peso = z;
        }

        sort(edge, edge+n, compare);

        for(int i=0; i<n; ++i){
            if(!find_set(edge[i].saida, edge[i].dest)){
                make_union(edge[i].saida, edge[i].dest);
                menor_dist+=edge[i].peso;
            }
        }

        for(int i=0; i<n; ++i){
            node[i].index = i;
            make_set(node[i]);
        }

        for(int i=n-1; i>0; --i){
            if(!find_set(edge[i].saida, edge[i].dest)){
                make_union(edge[i].saida, edge[i].dest);
                maior_dist+=edge[i].peso;
            }
        }      

        cout<< maior_dist << endl;
        cout<< menor_dist << endl;

    return 0;
}