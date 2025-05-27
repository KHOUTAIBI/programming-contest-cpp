#include <cstdio>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

const long long MAX_NODES = 1000 * 1000;
const long long INF = 1e8;

int nbEdges, nbNodes;
vector<tuple<long long, long long, long long>> nxt[MAX_NODES];
long double dist[MAX_NODES];

void readGraph(){


    for (int i =0; i < nbEdges; ++i){

        int pipe1, pipe2, cost, flow;
        scanf("%d %d %d %d\n", &pipe1, &pipe2, &cost, &flow);
        nxt[pipe1].push_back({pipe2, cost, flow});
        nxt[pipe2].push_back({pipe1, cost, flow});
    }

}

void dijkstra(int start_node, long double dist[]){

    fill(dist, dist + nbNodes, 0);
    dist[start_node] = INF;

    map<int, long long> min_flow_in_path;
    map<int, long double> cost_to_node;
    
    set<pair<long double, int>> queue;
    queue.insert({dist[start_node], start_node});

    min_flow_in_path[start_node] = INF;
    cost_to_node[start_node] = 0;

    while(!queue.empty()){
        
        auto [current_ratio, current_node] = *queue.begin();
        queue.erase(queue.begin());

        for (auto [node, cost, flow] : nxt[current_node]){

            long long min_flow = min(flow, min_flow_in_path[current_node]);
            
            long double total_cost = cost_to_node[current_node] + cost;
            long double new_ratio = min_flow / total_cost;

            if (new_ratio > dist[node]){
                
                dist[node] = new_ratio;
                min_flow_in_path[node] = min_flow;
                cost_to_node[node] = total_cost;
                queue.insert({new_ratio, node});

            }
        }
    }

}

int main(){
    
    scanf("%d %d\n", &nbNodes, &nbEdges);
    readGraph();

    dijkstra(1, dist);
    printf("%.0Lf\n", floor(1e6 * dist[nbNodes]));
}