#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

int main() {

	std::vector<std::pair<int, int>> edges{ {1,2}, {1,4}, {2,3}, {2,4}, {3,4} };

	std::unordered_map<int, std::unordered_set<int>> graph;

	// If the graph is directed
	for (const auto& elem : edges) {
		graph[elem.first].insert(elem.second);
	}

	std::cout << graph.size();
	// If the graph is undirected
	//for (const auto& elem : edges) {
	//	graph[elem.first].insert(elem.second);
	//	graph[elem.second].insert(elem.first);
	//}


	void dfs(std::unordered_map<int, std::unordered_set<int>>& graph, std::vector<bool>& visited, int state) {
		visited[state] = true;

		for (auto neighbour = graph[state].begin(); neighbour != graph[state].begin(); neighbour++) {
			if (!visited[*neighbour]) {
				dfs(graph, visited, *neighbour);
			}
		}
	}

	void bfs(vector<vector<int>>& graph, int start)
	{
		queue<int> q;

		vector<bool> visited(graph.size(), false);


		visited[start] = true;
		q.push(start);
		int counter = 0; // LevelCounter
		while (!q.empty()) {

			int levelSize = q.size(); // Number of nodes at a certain level
			while (levelSize) {

				int curr = q.front();
				q.pop();
				cout << curr << " ";
				levelSize--;

				for (int elem : graph[curr]) {
					if (!visited[elem]) {
						visited[elem] = true;
						q.push(elem);
					}
				}

			}
			counter++;
		}
	}

	// Topological sort

	void dfs(int node, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::stack<int>& sorted) {
		visited[node] = true;

		for (int neighbor : graph[node]) {
			if (!visited[neighbor]) {
				dfs(neighbor, graph, visited, sorted);
			}
		}

		sorted.push(node);
	}

	void topologicalSort(const std::vector<std::vector<int>>& graph) {

		std::vector<bool> visited(graph.size(), false);
		std::stack<int> sorted;

		// Topological sort every connected component
		for (int i = 0; i < vertices; ++i) {
			if (!visited[i]) {
				dfs(i, graph, visited, sorted);
			}
		}

		std::cout << "Topological Order: ";
		while (!topoStack.empty()) {
			std::cout << topoStack.top() << " ";
			topoStack.pop();
		}
		std::cout << std::endl;
	}
}