#include <cstdio>
#include <set>

using namespace std;

const int Tm = 101;
int out[Tm], N;

int main () {
  
    scanf("%d",&N);
    
    for(int i = 0 ; i+1 < N ; i++) {
      int a,b;
      scanf("%d %d\n",&a,&b);
      out[a]++;
    }

    int nb_out=0, res=-1; // count the number of nodes who don't have outgoing edges
    // and find one if it exists
    for(int i = 1 ; i <= N ; i++)
        if(out[i]==0) {
          res=i;
          nb_out++;
        }
    
    if(nb_out>1) res=-1;
  
    printf("%d\n",res);
    return 0;
}
