#ifndef GRAPH_h
#define GRAPH_h
#include <iostream>
#include "Exception.h"
#include <queue>

using namespace std;


class Node {
public:
	int data;
	Node* next = nullptr;
	Node(int d) { data = d; };
};

class Graph {
private:
	Node** list;
	int size;
	bool* dfsVisited;
public:
	//NewGraph();
	Graph(int size);
	~Graph();
	void AddEdge(int root, int dest);
	void RemoveEdge(int root, int del);
	bool HasEdge(int root, int dest);
	Node* OutEdges(int root);
	Node* InEdges(int root);
	void PrintGraph();
	void BFS(int search);
	void DFS(int search);
};

Graph::Graph(int s) {
	size = s;
	list = new Node * [size];
	for (int i = 0; i < size; i++) {
		list[i] = nullptr;
	}
	dfsVisited = new bool[size];
	for (int i = 0; i < size; i++) {
		dfsVisited[i] = false;
	}
}

Graph::~Graph() {
	Node* nn = nullptr;
	for (int i = 0; i < size; i++) {
		nn = list[i];
		while (nn != nullptr) {
			Node* dn = nn;
			nn = nn->next;
			delete dn;
		}
	}
	delete nn;
}


void Graph::AddEdge(int root, int dest) {

	if (dest >= size || root >= size) {
		throw Exception("Destination or Root is not found");
		return;
	}

	Node* nn = new Node(dest);
	Node* rn = list[root];

	if (list[root] == nullptr) {
		list[root] = nn;
		return;
	}
	while (rn->next != nullptr) {
		rn = rn->next;
	}
	rn->next = nn;
}


void Graph::RemoveEdge(int root, int del) {

	if (del >= size || root >= size) {
		throw Exception("Destination or Root is not found");
		return;
	}

	Node* dn = list[root];
	Node* nn = dn;

	int counter = 0;
	while (dn->data != del) {
		if (dn->next != nullptr) {
			nn = dn;
			dn = dn->next;
			counter++;
		}
	}
	if (counter > 0) {
		nn->next = dn->next;
		list[root] = nn;
	}
	else {
		nn->next = dn->next;
		nn = nn->next;
		list[root] = nn;
	}
	delete dn; 
}

bool Graph::HasEdge(int root, int dest) {

	if (dest >= size || root >= size) {
		throw Exception("Destination or Root is not found");
	}

	Node* nn = list[root];
	while (nn != nullptr) {
		if (nn->data == dest) {
			return true;
		}
		nn = nn->next;
	}
	return false;
}

Node* Graph::OutEdges(int root) {

	if (root >= size) {
		throw Exception("Root is not found");
	}

	return list[root];
}

Node* Graph::InEdges(int root) {

	if (root >= size) {
		throw Exception("Root is not found");
	}

	Node* nn = nullptr;
	Node* head = nullptr;
	int i = 0;
	while (i < size) {
		if (HasEdge(i, root)) {
			if (nn == nullptr) {
				head = new Node(i);
				nn = head;
			}
			else {
				//Node* temp = nn;
				while (nn->next != nullptr) {
					nn = nn->next;
				}
				Node* temp = new Node(i);
				nn->next = temp;
				//nn = nn->next;
			}
		}
		i++;
	}
	head->next = nn;
	return head;
}

void Graph::BFS(int search) {

	if (search >= size) {
		throw Exception("Root is not found");
	}

	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	queue<int> bfsq;
	visited[search] = true;
	bfsq.push(search);

	Node** verts = list;

	while (!bfsq.empty()) {
		search = bfsq.front();
		cout << search << " ";
		bfsq.pop();

		for (Node* i = verts[search]; i != nullptr; i = i->next) {
			if (!visited[i->data]) {
				visited[i->data] = true;
				bfsq.push(i->data);
			}
		}
	}
}

void Graph::DFS(int search) {

	if (search >= size) {
		throw Exception("Root is not found");
	}

	dfsVisited[search] = true;
	cout << search << " ";
	Node** verts = list;
	for (Node* i = verts[search]; i != nullptr; i = i->next) {
		if (!dfsVisited[i->data]) {
			DFS(i->data);
		}
	}
}

void Graph::PrintGraph() {
	Node* nn = nullptr;
	for (int i = 0; i < size; i++) {
		nn = list[i];
		cout << "[" << i << "] -> ";
		while (nn != nullptr) {
			cout << nn->data;
			if (nn->next != nullptr) {
				cout << " -> ";
			}
			nn = nn->next;
		}
		cout << endl;
	}
}
#endif