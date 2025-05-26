#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){

    map<string, int> names;
    char c[100 * 100];
    int total{0};
    int Y, M, D;

    while(scanf("%d-%d-%d", &Y, &M, &D) > 0){
        
        scanf("%[^\n]", c);
        string _name(c);

        if (names[_name] == 0){
            total+=1;
            ++names[_name];
        }
        
    }

    printf("%d", total);

}