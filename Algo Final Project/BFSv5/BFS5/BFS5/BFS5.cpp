#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    vector<int> state;
    Node* parent;
	int numMove = 0;
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
		leftChild->numMove = moveLeft[pos];

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
		downChild->numMove = moveDown[pos];

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
		rightChild->numMove = moveRight[pos];

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
		upChild->numMove = moveUp[pos];

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
	int cost = 0;
	while (curr->parent != NULL)
	{
		printStack.push(curr->state);
		curr = curr->parent;
	}

	printStack.push(curr->state);

	int size = printStack.size();
	cout << "Minimum Path: " << size - 1 << '\n';

	printSol(printStack);

}

void BFS(vector<int> root, vector<int> goal)
{
	queue<Node*> Q;
	bool foundGoal = false;
	Node* v = new Node;
	v->state = root;
	v->parent = NULL;
	v->numMove = 0;
	Q.push(v);

	while (!Q.empty() && !foundGoal)
	{
		v = Q.front();
		Q.pop();

		if (v->state == goal)
		{
			foundGoal = true;
			MakeStack(v);
		}

		if (left(v) != v)
		{
			Q.push(left(v));
		}
		if (up(v) != v)
		{
			Q.push(up(v));
		}
		if (right(v) != v)
		{
			Q.push(right(v));
		}
		if (down(v) != v)
		{
			Q.push(down(v));
		}
	}
}


int main()
{
	vector<int> initial = { 1, 3, 4, 
							8, 0, 6, 
							7, 5, 2 };
	vector<int> goal = { 1, 2, 3, 
						 8, 0, 4, 
						 7, 6, 5 };

	BFS(initial, goal);
}