#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Node
{
public:
	vector<int> state;
	Node* parent;
};

int findZero(vector<int> G)
{
	vector<int>::iterator i;
	i = find(G.begin(), G.end(), 0);
	auto pos = distance(G.begin(), i);
	return (int)pos;
}

Node* left(Node* G)
{
	int pos = findZero(G->state);

	if (pos != 0 && pos != 3 && pos != 6)
	{
		vector<int> moveLeft = G->state;
		Node* leftChild = new Node;
		swap(moveLeft[pos], moveLeft[pos - 1]);
		leftChild->parent = G;
		leftChild->state = moveLeft;

		return leftChild;
	}
	else
	{
		return G;
	}

}

Node* down(Node* G)
{
	int pos = findZero(G->state);

	if (pos != 0 && pos != 1 && pos != 2)
	{
		vector<int> moveDown = G->state;
		Node* downChild = new Node;
		swap(moveDown[pos], moveDown[pos - 3]);
		downChild->parent = G;
		downChild->state = moveDown;

		return downChild;
	}
	else
	{
		return G;
	}

}

Node* right(Node* G)
{
	int pos = findZero(G->state);

	if (pos != 2 && pos != 5 && pos != 8)
	{
		vector<int> moveRight = G->state;
		Node* rightChild = new Node;
		swap(moveRight[pos], moveRight[pos + 1]);
		rightChild->parent = G;
		rightChild->state = moveRight;

		return rightChild;
	}
	else
	{
		return G;
	}

}

Node* up(Node* G)
{
	int pos = findZero(G->state);

	if (pos != 6 && pos != 7 && pos != 8)
	{
		vector<int> moveUp = G->state;
		Node* upChild = new Node;
		swap(moveUp[pos], moveUp[pos + 3]);
		upChild->parent = G;
		upChild->state = moveUp;

		return upChild;
	}
	else
	{
		return G;
	}
}

void printSol(stack<vector<int>> sol)
{
	vector<int> printState;

	if (sol.empty())
		return;

	printState = sol.top();
	sol.pop();

	int count = 0;
	for (int i = 0; i < printState.size(); i++)
	{
		if (count % 3 == 0)
		{
			cout << '\n';
		}
		cout << printState[i] << ' ';
		count++;
	}
	cout << '\n';

	printSol(sol);
}

void MakeStack(Node* goal)
{
	stack<vector<int>> printStack;
	Node* curr = goal;
	while (curr->parent != NULL)
	{
		printStack.push(curr->state);
		curr = curr->parent;
	}

	printStack.push(curr->state);

	int size = printStack.size();
	cout << "Minimum Cost: " << size - 1 << '\n';

	printSol(printStack);

}

vector<Node*> getN(Node* node)
{
	vector<Node*> neighbors;
	if (left(node) != node) { neighbors.push_back(left(node)); }
	if (up(node) != node) { neighbors.push_back(up(node)); }
	if (right(node) != node) { neighbors.push_back(right(node)); }
	if (down(node) != node) { neighbors.push_back(down(node)); }
	return neighbors;
}

void DFS(Node* state, vector<int> goal, stack<Node*> Q)
{
	if (state->state == goal) { MakeStack(state); }
	if (down(state) != state) { Q.push(down(state)); }
	if (right(state) != state) { Q.push(right(state)); }
	if (up(state) != state) { Q.push(up(state)); }
	if (left(state) != state) { Q.push(left(state)); }
	if (!Q.empty() && state->state != goal) { Q.pop(); DFS(Q.top(), goal, Q); }
}

int main()
{
	vector<int> initial = { 1, 3, 4,
							8, 0, 2,
							7, 6, 5 };
	vector<int> goal = { 1, 2, 3,
						 8, 0, 4,
						 7, 6, 5 };

	Node* root = new Node;
	root->state = initial;
	root->parent = NULL;
	stack<Node*> Q;

	DFS(root, goal, Q);

}