#include <cstdio>
#include <string>

using namespace std;

int main(){

    int N;
    char c[100];
    
    scanf("%d\n", &N);

    while(scanf("%s\n", c) > 0){
        string temp(c);

        if (temp.size() > 10){
            printf("%c%d%c\n", temp[0], temp.size() - 2, temp[temp.size() - 1]);
        }

        else{
            printf("%s\n", temp.c_str());
        }
    }
}