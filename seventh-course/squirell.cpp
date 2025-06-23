#include <complex>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
const int NMAX{1001}, MAX_X_Y{1000 * 1000 + 1};
typedef pair<int, int> p;
vector<p> coords;
const int INF = 1e9;
int N;

int main(){
    scanf("%d\n", &N);
    int x, y;
    for (int i = 0; i < N; ++i){
        scanf("%d %d\n", &x, &y);
        coords.push_back({x, y});
    }

    sort(coords.begin(), coords.end());
    int mean = INF;
    int dist = 0;
    int x1, y1;

    for (int i = 0; i < N; ++i){
        
        for (int j = 0; j < N; ++j){
            dist += abs(coords[j].first - coords[i].first) + abs(coords[j].second - coords[i].second); 
        }

        if (dist < mean){
            mean = dist;
            x1 = coords[i].first;
            y1 = coords[i].second;
        }

        dist = 0;
    }

    printf("%d %d\n", x1 , y1);

}