#include <cstdio>
using namespace std;

const int MAX = 1001;  
int diff[MAX][MAX];   
int N, K;

int main() {

    scanf("%d %d\n", &N, &K);

    for (int i = 0; i < N; ++i) {

        int x1, y1, x2, y2;
        scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);

        diff[x1][y1] += 1;
        diff[x2][y1] -= 1;
        diff[x1][y2] -= 1;
        diff[x2][y2] += 1;
        
    }


    for (int x = 0; x < MAX; ++x) {
        for (int y = 1; y < MAX; ++y) {
            diff[x][y] += diff[x][y - 1];
        }
    }

    for (int y = 0; y < MAX; ++y) {
        for (int x = 1; x < MAX; ++x) {
            diff[x][y] += diff[x - 1][y];
        }
    }


    int result = 0;
    for (int x = 0; x < MAX; ++x) {
        for (int y = 0; y < MAX; ++y) {
            if (diff[x][y] == K)
                result++;
        }
    }

    printf("%d\n", result);
    
}
