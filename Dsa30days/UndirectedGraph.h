#pragma once

#include <unordered_map>
#include <vector>

class Graph
{
public:
	Graph();
	~Graph();

	void addVertex(int v);
	void addEdge(int v1, int v2);

	void printGraph() const;
	void bfs(int v);
private:
	std::unordered_map<int, std::vector<int>> adjList;
};
