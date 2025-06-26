#include <cstdio>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;
typedef complex<long long> pt;
int N, P; 
long long x, y;
pt c;

int main() {

    scanf("%d\n", &N);

    long long total_area = 0;

    while(N--){

        scanf("%d\n", &P);
        
        long long current_area = 0;

        scanf("%lld %lld\n", &x, &y);
        pt a{x, y}; 
        scanf("%lld %lld\n", &x, &y);
        pt b{x, y};

        while(--P >= 2){
            scanf("%lld %lld\n", &x, &y);
            c = pt{x, y};
            current_area += imag((b - a) * conj(b - c));
            b = c;
        }

        total_area += abs(current_area);

    }

    printf("%lld\n", total_area/2);  

}
