#include <cstdio>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

const int NMAX = 100 + 1, TMAX = 1000 * 1000 + 1;
const long long INF = 1e14;
int N,T;
long long values[NMAX][NMAX][3]; 
int grass[NMAX][NMAX];
set<tuple<long long, int, int, int>> q;

void readGraph(){
    int x;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            scanf("%d ", &x);
            grass[i][j] = x;
        }
    }
}


void move(int x, int y, int mode, long long w){

    if (x < 0 || y < 0 || x >= N || y >= N) return;
    
    if (mode == 3){
        mode = 0;
        w += grass[x][y];
    }

    w += T;

    if (values[x][y][mode] > w){
        values[x][y][mode] = w;
        q.insert({w, x, y, mode});
    }
}

int main(){
    
    scanf("%d %d\n", &N, &T);
    fill(values[0][0], values[NMAX][0], INF);
    values[0][0][0] = 0;
    q.insert({0, 0, 0, 0});
    readGraph();
    
    long long result = INF;

    while(!q.empty()){
        
        auto [w, x, y, mode] = *q.begin();
        q.erase(q.begin());

        if (x == N-1 && y == N-1) result = min(result, w);

        if (values[x][y][mode] == w){
            move(x - 1, y, mode + 1, w);
            move(x + 1, y, mode + 1, w);
            move(x, y - 1, mode + 1, w);
            move(x, y + 1, mode + 1, w);
        }
    }

    printf("%lld\n", result);
}