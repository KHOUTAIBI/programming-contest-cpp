#include <set>
#include <vector>
#include <cstdio>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const int NB_NODES_MAX = 1000000;
const long long INF = 1e18;

int max_flow = 0;
int cost_max_flow_edge = 0;
int nbEdges, nbNodes;

pair<int, int> pair_max;
vector<pair<int, int>> nxt[NB_NODES_MAX];
vector<int> flows[NB_NODES_MAX];

int dist_from_start[NB_NODES_MAX];
int dist_from_v[NB_NODES_MAX];


void readGraph() {

    scanf("%d %d", &nbNodes, &nbEdges);
    
    for (int i = 0; i < nbEdges; i++) {
        int pipe1, pipe2, cost, flow;

        scanf("%d %d %d %d\n", &pipe1, &pipe2, &cost, &flow);
        
        // Update max flow edge
        if (flow >= max_flow) {
            max_flow = flow;
            pair_max = {pipe1, pipe2};
            cost_max_flow_edge = cost;
        }
        
        nxt[pipe1].emplace_back(pipe2, cost, flow);
        nxt[pipe2].emplace_back(pipe1, cost, flow); 
    }
}

void dijkstra(int start_node, int dist[]) {

    fill(dist, dist + nbNodes + 1, INF);
    set<pair<int, int>> p_queue;

    dist[start_node] = 0;
    p_queue.insert({0, start_node});

    while (!p_queue.empty()) {

        auto [node_dist, node] = *p_queue.begin();
        p_queue.erase(p_queue.begin());

        for (auto [to, cost, flow] : nxt[node]) {

            if (node_dist + cost < dist[to]) {

                p_queue.erase({dist[to], to});
                dist[to] = node_dist + cost;
                p_queue.insert({dist[to], to});
            
            }
        }
    }
}

int main() {

    readGraph();
    
    int start = 1;
    int end_node = nbNodes;

    int u = pair_max.first;
    int v = pair_max.second;

    dijkstra(start, dist_from_start);
    dijkstra(v, dist_from_v); 

    int total_dist = dist_from_start[u] + cost_max_flow_edge + dist_from_v[end_node];
    
    printf("%d\n", dist_from_start[u]);
    
    long double solution = 1e6 * (total_dist / max_flow);

    printf("%Ld\n", solution);
    
}
