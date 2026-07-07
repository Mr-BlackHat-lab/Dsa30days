#include "UndirectedGraph.h"
#include <iostream>
#include <queue>
#include <unordered_set>

Graph::Graph() {};
Graph::~Graph() {};

void Graph::addVertex(int v) {
	adjList[v];
}
void Graph::addEdge(int v1, int v2) {
	adjList[v1].push_back(v2);
	adjList[v2].push_back(v1);
}
void Graph::printGraph() const {
    for (const auto& pair : adjList)
    {
        std::cout << pair.first << " -> ";
        for (int neighbor : pair.second)
        {
            std::cout << neighbor << " ";
        }
        std::cout << '\n';
    }
}
void Graph::bfs(int start)
{
    std::queue<int> q;
    std::unordered_set<int> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        std::cout << current << " ";

        for (int neighbor : adjList[current])
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    std::cout << '\n';
}