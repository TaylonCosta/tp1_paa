#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int reverse(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return reversed;
}

int main(){
    int t=0;
    cin >> t;
    for(int i=0; i<t; ++i){
        int a=0, b=0;
        queue<int> fila;
        unordered_map<int,int> dist;

        cin >> a >> b;
        fila.push(a);
        if ((a<=9 && b<=9) || (a==b)){
            dist[a]=b-a;
        }
        else{
            dist[a] = 0;
            while(1){
                if(fila.front()==b)
                    goto exit_flag;
                int aux_r = fila.front()+1;
                int aux_l = reverse(fila.front());
                if(aux_l != fila.front() && !dist.count(aux_l)){
                    fila.push(aux_l);
                    dist[aux_l] =  dist[fila.front()]+1;
                }
                if(!dist.count(aux_r)){
                    fila.push(aux_r);
                    dist[aux_r] = dist[fila.front()]+1;
                }
                fila.pop();
            }
        }
        exit_flag:
        cout << dist[fila.front()]<<endl;
    }

    return 0;
}