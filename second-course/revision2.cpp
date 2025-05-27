#include <map>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

int main(){
    int N;
    scanf("%d\n", &N);

    map<string, int> memory;
    int K = 1;
    char c[N + 1];
    scanf("%s", c);

    string noun(c);
   
    while(N - K >= 0){
        
        bool duplicate = false;
        for (int i = 0; i <= N-K; ++i){
            string sub = noun.substr(i, K);

            if (memory[sub]){
                duplicate = true;
            }
            ++memory[sub];
        }


        if (!duplicate) break;
        memory.clear();
        K++;

    }


    printf("%d\n", K);
}