#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

void dijkstra (std::unordered_map<int, std::set<std::pair<int, int>>>& graph,
    int* dest, int* parents, int numberVertices, int start) {

    for (int i = 0; i < numberVertices; i++) dest[i] = INT_MAX;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>pq;
    
    dest[start] = 0;
    parents[start] = -1;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int currentVertex = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();
        for (auto i = graph[currentVertex].begin(); i != graph[currentVertex].end(); i++) {
            int nextVertex = i->first;
            int nextWeight = i->second;
            if (dest[nextVertex] > currentWeight + nextWeight) {
                dest[nextVertex] = currentWeight + nextWeight;
                parents[nextVertex] = currentVertex;
                pq.push({ currentWeight + nextWeight, nextVertex });
            }
        }
    }
}

void getPath(int* parents, int destination) {
    int tmp = destination;
    std::stack<int> s;
    while (tmp != -1) {
        s.push(tmp);
        tmp = parents[tmp];
    }
    while (!s.empty() ){
        std::cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    std::unordered_map <int, std::set<std::pair<int, int>>> graph;
    graph[0].insert({ 2, 3 }); 
    graph[2].insert({ 0, 3 }); 

    graph[0].insert({ 5, 2 }); 
    graph[5].insert({ 0, 2 }); 

    graph[2].insert({ 4, 1 }); 
    graph[4].insert({ 2, 1 }); 

    graph[2].insert({ 3, 4 }); 
    graph[3].insert({ 2, 4 }); 

    graph[1].insert({ 3, 1 }); 
    graph[3].insert({ 1, 1 }); 

    graph[1].insert({ 4, 2 }); 
    graph[4].insert({ 1, 2 }); 

    graph[1].insert({ 6, 2 }); 
    graph[6].insert({ 1, 2 }); 

    graph[5].insert({ 4, 3 }); 
    graph[4].insert({ 5, 3 }); 

    graph[4].insert({ 6, 6 }); 
    graph[6].insert({ 4, 6 }); 

    graph[6].insert({ 5, 12 });
    graph[5].insert({ 6, 12 });


    int distance[7] = {};
    int parents[7] = {};
    dijkstra(graph, distance, parents, 7, 0);

    getPath(parents, 6);

    return 0;
}