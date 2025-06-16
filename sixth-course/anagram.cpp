#include <unordered_map>
#include <cstdio>

using namespace std;

int S, T;
const int T_MAX{3 * 1000 * 1000 + 1}, S_MAX{3001};
char input[S_MAX], sentence[T_MAX];

int main(){
    
    unordered_map<char, int> map_input;
    unordered_map<char, int> map_sentence;
    int res = 0;

    scanf("%d %d\n", &S, &T);

    scanf("%s",input);
    scanf("%s",sentence);

    for (int i = 0; i < S; ++i){
        ++map_input[input[i]];
        ++map_sentence[sentence[i]];
    }

    if (map_sentence == map_input) ++res;

    

    for (int i = S; i < T; ++i){

            char in = sentence[i];
            char out = sentence[i - S];

            --map_sentence[out];
            if (map_sentence[out] == 0){
                map_sentence.erase(out);
            }

            map_sentence[in]++;

            if (map_sentence == map_input) res ++;

    }

    printf("%d\n", res);
}