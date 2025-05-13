#include <cstdio>
#include <map>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){

    int N, total{0}, left{0}, right{1};
    set<string> s;
    scanf("%d\n", &N);

    char list_chars[N];
    scanf("%[^\n]", list_chars);
    string colors(list_chars);

    while(true){

        if (right == N){
            printf("%d\n", right - left);
            break;
        }


        if (s.find(colors.substr(left, left + right)) != s.end()){
            s.insert(colors.substr(left, left + right)); 
            left += 1;
        }

        else{
            right += 1;
            left = 0;
            s.clear();
        }



    }
}