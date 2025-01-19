#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

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
class UnionFindBySize {
public:
    void makeSet(const T &u);
    const T& findSet(const T &v);
    void unionSets(const T &u, const T &v);


private:
    unordered_map<T, T> parent;
    unordered_map<T, int> size;

};

template <typename T>
void UnionFindBySize<T>::makeSet(const T &u) {
    if (parent.count(u) == 0) {
        parent[u] = u;
        size[u] = 1;
    }
}

template <typename T>
const T& UnionFindBySize<T>::findSet(const T &v) {
    if (v == parent[v]) {
        return parent[v];
    }

    return parent[v] = findSet(parent[v]);
}

template <typename T>
void UnionFindBySize<T>::unionSets(const T &u, const T &v) {
    const T &uSet = findSet(u);
    const T &vSet = findSet(v);

    if (uSet == vSet) {
        return;
    }

    int &uSize = size[uSet];
    int &vSize = size[vSet];

    if (uSize < vSize) {
        parent[uSet] = vSet;
        vSize += uSize;
    } else {
        parent[vSet] = uSet;
        uSize += vSize;
    }
}

template <typename T>
vector<Edge<T>> kruskal(const vector<T> &vertices, vector<Edge<T>> edges) {
    UnionFindBySize<T> uf;
    for (const T &vertex : vertices) {
        uf.makeSet(vertex);
    }

    sort(edges.begin(), edges.end());

    vector<Edge<T>> mstEdges;
    int components = vertices.size();
    for (const Edge<T> &edge : edges) {
        const T &uSet = uf.findSet(edge.u);
        const T &vSet = uf.findSet(edge.v);

        if (uSet != vSet) {
            mstEdges.push_back(edge);
            uf.unionSets(uSet, vSet);
            components--;
        }
    }

    // Handle the error as you wish
    if (components > 1) {
        cerr << "The graph is not connected!\n";
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
    vector<Edge<int>> mst = kruskal(vertices, edges);

    for (const Edge<int> &edge : mst) {
        cout << edge.u << '-' << edge.v << ' ' << edge.weight << '\n';
    }

    return 0;
}