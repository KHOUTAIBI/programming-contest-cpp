#include <cstdio>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){

    int N, K{1};
    set<string> s;

    scanf("%d\n", &N);

    char list_chars[N];
    map<string, int> mem;

    scanf("%[^\n]", list_chars);
    string colors(list_chars);

    size_t left{0}, right{1};
    map<string, int> mem;

    while(K <= N){
        
        bool duplicate = false;

        for (int i = 0; i <= N - K; i++) {
            
            string sub = colors.substr(i, K);
            if (mem[sub]) {
                duplicate = true;
                break;
            
            }
            mem[sub]++;
        }

        if (!duplicate) break;
        mem.clear();
        K++;

    }

    printf("%d\n", K);
}