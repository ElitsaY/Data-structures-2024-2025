#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

using WEIGHT_TYPE = int;


template <typename T>
struct Edge {
    T u;
    T v;
    WEIGHT_TYPE weight;

    bool operator <(const Edge &other)
    {
        return weight < other.weight;
    }
};


template <typename T>
vector<Edge<T>> prim(const vector<T> &vertices, vector<Edge<T>> edges) {
    if (vertices.empty()) {
        return {};
    }

    unordered_map<T, vector<pair<T, WEIGHT_TYPE>>> adjList;
    for (const Edge<T> &edge : edges) {
        const T &u = edge.u;
        const T &v = edge.v;
        const WEIGHT_TYPE &weight = edge.weight;

        if (u == v) {
            continue;
        }

        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    unordered_map<T, bool> visited;
    for (const T &vertex : vertices) {
        visited[vertex] = false;
    }

    priority_queue<pair<WEIGHT_TYPE, pair<T, T>>, vector<pair<WEIGHT_TYPE, pair<T, T>>>, greater<pair<WEIGHT_TYPE, pair<T, T>>>> pq;
    const T &source = vertices[0];
    pq.push({0, {source, source}});

    vector<Edge<T>> mstEdges;
    while (!pq.empty()) {
        auto [curCost, p] = pq.top();
        auto [cur, curParent] = p;
        pq.pop();

        if (visited[cur]) {
            continue;
        }

        visited[cur] = true;
        if (cur != curParent) {
            mstEdges.push_back({curParent, cur, curCost});
        }

        for (const auto &[to, price] : adjList[cur]) {
            if (!visited[to]) {
                pq.push({price, {to, cur}});
            }
        }
    }

    return mstEdges;
}


int main(){
    vector<int> vertices = {0,1,2,3};
    vector<Edge<int>> edges = {
        {0,1,10},
        {1,3,15},
        {2,3,4},
        {2,0,6},
        {0,3,5}
    };
    vector<Edge<int>> mst = prim(vertices, edges);

    for (const Edge<int> &edge : mst) {
        cout << edge.u << '-' << edge.v << ' ' << edge.weight << '\n';
    }

    return 0;
}