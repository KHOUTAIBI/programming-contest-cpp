#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_NODES = 25000;
int N;
vector<pair<int, int>> inputs[MAX_NODES];
vector<pair<int, pair<int, int>>> edges;
int repr[MAX_NODES];

void readGraph(){

    scanf("%d\n", &N); 
    for (int i = 0; i < N; ++i){
        int x, y;
        scanf("%d %d\n", &x, &y);
        inputs[i].push_back({x, y});
    }

    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){  
            int dx = inputs[j][0].first - inputs[i][0].first;
            int dy = inputs[j][0].second - inputs[i][0].second;
            int w = dx * dx + dy * dy;
            edges.push_back({w, {i, j}});
        }
    }
}

int find(int x) {
    if(repr[x] < 0) return x;
    return repr[x] = find(repr[x]); 
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(repr[a] > repr[b]) swap(a, b);
    repr[a] += repr[b];
    repr[b] = a;
    return true;
}

int main(){

    readGraph();

    fill(repr, repr + MAX_NODES, -1);  
    sort(edges.begin(), edges.end());
    int weight_mst = 0;
    vector<pair<int, pair<int, int>>> coords; 
    
    for(auto [w, p] : edges) {
        if(unite(p.first, p.second)) {
            weight_mst = max(weight_mst, w);
        }
    }

    printf("%d\n", weight_mst);
}
