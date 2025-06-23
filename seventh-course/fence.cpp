#include <cstdio>
#include <cstring>
#include <complex>

using namespace std;

const int LMAX = 101;  
char path[LMAX];
typedef complex<int> pt;
pt coords[LMAX];

int sign_cross(pt A, pt B) {
    int c =  (conj(A) * B).imag();  
    if (c < 0) return -1;
    if (c > 0) return 1;
    return 0;
}

bool isClockwise(char c[]) {

    int len = strlen(c);
    pt pos(0, 0);
    coords[0] = pos;

   
    for (int i = 0; i < len; ++i) {
        if (c[i] == 'N') pos += pt(0, 1);
        else if (c[i] == 'S') pos += pt(0, -1);
        else if (c[i] == 'E') pos += pt(1, 0);
        else if (c[i] == 'W') pos += pt(-1, 0);
        coords[i + 1] = pos;
    }

 
    int area = 0;
    for (int i = 0; i < len; ++i) {
        area += sign_cross(coords[i], coords[i + 1]);
    }

    return area < 0;  
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%s", path);
        if (isClockwise(path)) printf("CW\n");
        else printf("CCW\n");
    }

    return 0;
}
