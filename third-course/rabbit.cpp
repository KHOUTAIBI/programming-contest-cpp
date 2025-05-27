#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int MAX_NODES = 1000 * 1000;
char grid[1000][1000];
int C, R;
int i_R, j_R, i_D, j_D;

vector<int> graph[MAX_NODES];

int readGraph(){

    scanf("%d %d\n", &C, &R);
    char c;

    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j){

            scanf("%c", &c);

            if (c == 'R') {
                i_R = i;
                j_R = j;
            }
            if (c == 'D') {
                i_D = i;
                j_D = j;
            }

            grid[i][j] = c;
        }
        scanf("\n"); 
    }

    for (int i = 0; i < R; ++i){

        for (int j = 0; j < C; ++j){
            
            if (grid[i][j] == '#') continue;

            int u = i * C + j;

            if (i > 0 && grid[i-1][j] != '#')
                graph[u].push_back((i-1)*C + j);
            
            if (i < R-1 && grid[i+1][j] != '#')
                graph[u].push_back((i+1)*C + j);
            
            if (j > 0 && grid[i][j-1] != '#')
                graph[u].push_back(i*C + (j-1));
            
            if (j < C-1 && grid[i][j+1] != '#')
                graph[u].push_back(i*C + (j+1));
        
        }
    }

    return 0;
}


int seen[MAX_NODES] ;

string bfs(int i, int j, int C) {
    
    int start = C * i + j;
    int end = C * i_D + j_D;

    vector<int> parent(MAX_NODES, -1);
    vector<int> todo = {start} ;
    seen[start] = true;
    
    for(size_t id = 0 ; id < todo.size() ; id++){
    
        if (todo[id] == end){
            break;
        }

        for(auto v : graph[todo[id]])

            if(!seen[v]){
                seen[v] = true;
                parent[v] = todo[id];
                todo.push_back(v);
            }
    }
    
    string result = "";
    for (int at = end; parent[at] != -1; at = parent[at]){
        
        int from = parent[at];
        int diff = at - from;

        if (diff == 1) result += 'R';
        else if (diff == -1) result += 'L';
        else if (diff == C) result += 'D';
        else if (diff == -C) result += 'U';
    }
    
    reverse(result.begin(), result.end());
    return result;
}


int main(){
    
    readGraph();

    string result = bfs(i_R, j_R, C);
    
    printf("%s\n", result.c_str());

}