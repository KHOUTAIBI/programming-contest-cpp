#include <cstdio>
#include <unordered_map>

using namespace std;

const int SMAX{3000 + 1}, TMAX{3 * 1000 * 1000 +1};
int S, T;
char input[SMAX], sentence[TMAX];


int main(){

    scanf("%d %d\n", &S, &T);

    scanf("%s", input);
    scanf("%s", sentence);

    unordered_map<char, int>  map_i;
    unordered_map<char, int> map_s;
    int result = 0;

    for (int i = 0; i < S; ++i){
        ++map_i[input[i]];
        ++map_s[sentence[i]];
    }

    if (map_i == map_s) result++;

    for (int i = S; i < T; ++i){
        char in = sentence[i];
        char out = sentence[i - S];

        --map_s[out];
        if (map_s[out] == 0) map_s.erase(out);

        ++map_s[in];

        if (map_s == map_i) result++;
    }


    printf("%d\n", result);
}