#include <cstdio>
#include <vector>

using namespace std;


long long x1, y1, x2, y2;
long long a1, b1, a2, b2;
const int NMAX = 100 * 1000;

long long points[NMAX][4]; 

int N;

int main(){
    
    scanf("%d\n", &N);
    int total = 0;

    scanf("%d %d %d %d\n",  &points[0][0], &points[0][1], &points[0][2], &points[0][3]);
    total += 1;

    for (int i = 1; i < N; ++i){
        scanf("%d %d %d %d\n",  &points[i][0], &points[i][1], &points[i][2], &points[i][3]);
    }

    for (int i = 1; i < N; ++i){
        
    }
}