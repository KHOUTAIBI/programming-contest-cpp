#include <set>
#include <vector>
#include <cstdio>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int NB_NODES_MAX = 1000000;
const long long INF = 1e18;

long long nbEdges, nbNodes;

vector<tuple<long long, long long, long long>> nxt[NB_NODES_MAX];
vector<long long> flows[NB_NODES_MAX];

long double dist_from_start[NB_NODES_MAX];


void readGraph() {

    scanf("%d %d", &nbNodes, &nbEdges);
    
    for (int i = 0; i < nbEdges; i++) {
        int pipe1, pipe2, cost, flow;

        scanf("%d %d %d %d\n", &pipe1, &pipe2, &cost, &flow);
        
        nxt[pipe1].emplace_back(pipe2, cost, flow);
        nxt[pipe2].emplace_back(pipe1, cost, flow); 
    }
}


void dijkstra(int start_node, long double dist[]) {
    
    fill(dist, dist + nbNodes, 0);
    
    set<pair<long double, int>> queue;

    dist[start_node] = INF;  

    queue.insert({dist[start_node], start_node});
    
    map<int, long long> flow_min_in_path;
    map<int, long double> total_cost_to_node;
    
    flow_min_in_path[start_node] = INF;
    total_cost_to_node[start_node] = 0;

    while (!queue.empty()) {
        
        auto [current_ratio, node] = *queue.begin();
        queue.erase(queue.begin());
        

        for (auto [to, cost, flow] : nxt[node]) {

            long long min_flow = min(flow_min_in_path[node], flow);

            long double total_cost = total_cost_to_node[node] + cost;
            
            long double new_ratio = min_flow / total_cost;

            if (new_ratio > dist[to]) {

                dist[to] = new_ratio;
                
                flow_min_in_path[to] = min_flow;
                
                total_cost_to_node[to] = total_cost;
                
                queue.insert({new_ratio, to});
            
            }
        }
    }
}

int main() {

    readGraph();
    
    int start = 1;
    int end_node = nbNodes;
    
    dijkstra(start, dist_from_start);

    printf("%0.Lf\n", floor(1e6 * dist_from_start[end_node]));
}
