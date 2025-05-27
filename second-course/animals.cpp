#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){
    
    int N;
    char c[21];
    map<string, int> animals;


    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i){
        scanf("%s\n", c);
        string _name(c);    
        ++animals[_name];
    }

    for (auto &[key, value] : animals){
        if (value > N - value){
            printf("%s\n", key.c_str());
            return 0;
        }
    }

    printf("NONE\n");
}