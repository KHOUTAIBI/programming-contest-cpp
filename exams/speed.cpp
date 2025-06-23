#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 101;   
int distances[NMAX];   

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int x, speed;
    int total = 0, begin = 0;

    
    fill(distances, distances + NMAX, 0);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x, &speed);
        fill(distances + total, distances + total + x, -speed); 
        total += x;
    }

    
    total = 0;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &x, &speed);
        for (int j = total; j < total + x; ++j) {
            distances[j] += speed;  
        }
        total += x;
    }

    
    int max_over = 0;
    for (int i = 0; i < 100; ++i) {
        max_over = max(max_over, distances[i]);
    }

    printf("%d\n", max_over);
    
}
