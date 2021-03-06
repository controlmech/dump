#include "stdafx.h"
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <limits>
#include <algorithm>

struct node {
	std::vector<char> connectedNodes;
	int distance = std::numeric_limits<int>::max(); // Default
	char prevNode = 'Z'; // Default
	bool visited = false; // Default
};

void outputMap(std::map<char, node> & nodes) {
	std::map<char, node>::iterator it;
	for (it = nodes.begin(); it != nodes.end(); ++it) {
		printf("Key : %c\nValues : ", it->first);
		for (char c : it->second.connectedNodes) printf("%c ", c);
		printf("\n");
	}
}

void outputPaths(std::map<char, node> & nodes, char startNode) {
	printf("Starting from : %c\n", startNode);
	std::map<char, node>::iterator it;
	char curNode;
	std::string path;

	for (it = nodes.begin(); it != nodes.end(); ++it) {
		curNode = it->first;
		// Retrieve data from node structure
		do {
			path.insert(0, 1, curNode);
			curNode = nodes.at(curNode).prevNode;
		} while (curNode != 'Z');

		printf("Go to %c : %s, distance : %i\n", it->first, path.c_str(), it->second.distance);
		path = "";
	}
}

void createNodes(std::map<char, node> & nodes, char a, char b) {
	if (nodes.find(a) == nodes.end()) {
		node curNode;
		curNode.connectedNodes.push_back(b);
		nodes.insert(std::pair <char, node>(a, curNode));
	}
	else {
		nodes.at(a).connectedNodes.push_back(b);
	}
	if (nodes.find(b) == nodes.end()) {
		node curNode;
		curNode.connectedNodes.push_back(a);
		nodes.insert(std::pair <char, node>(b, curNode));
	}
	else {
		nodes.at(b).connectedNodes.push_back(a);
	}
}

char findNextNode(std::map<char, node> & nodes, char curNode) {
	char shortest = 'Z';
	int val = std::numeric_limits<int>::max();

	std::map<char, node>::iterator it;
	for (it = nodes.begin(); it != nodes.end(); ++it) {
		// Next node is the one with the shortest distance and unvisited
		if ((it->second.distance <= val) && !(it->second.visited)) {
			val = it->second.distance;
			shortest = it->first;
		}
	}
	return shortest;
}

bool allVisited(std::map<char, node> & nodes) {
	std::map<char, node>::iterator it;
	for (it = nodes.begin(); it != nodes.end(); ++it) {
		if (it->second.visited) continue;
		else return false;
	}
	return true;
}

void shortestPath(std::map<char, node> & nodes, char curNode) {
	while (!(allVisited(nodes))) {
		for (char c : nodes.at(curNode).connectedNodes) {
			if (!(nodes.at(c).visited)) {
				// Find new shortest distance to adjacent node
				int newDist = nodes.at(curNode).distance + 1;
				if (newDist < nodes.at(c).distance) {
					nodes.at(c).distance = newDist;
					nodes.at(c).prevNode = curNode; // Set previous node to the one being searched from
				}
			}
		}
		nodes.at(curNode).visited = true;
		curNode = findNextNode(nodes, curNode); // Set new current node to the closest adjacent node
	}
}

int main()
{
	int N;
	char startNode, a, b;
	std::map<char, node> nodes;
	std::cin >> N;

	for (; N-- > 0;) {
		std::cin >> a;
		std::cin >> b;
		createNodes(nodes, a, b);
	}

	std::cin >> startNode;
	nodes.at(startNode).distance = 0;

	shortestPath(nodes, startNode);
	outputPaths(nodes, startNode);
    return 0;
}