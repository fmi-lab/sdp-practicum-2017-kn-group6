#include "stdafx.h"
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

struct glass {
	int capacity;
	int current;

	glass() {
		capacity = 0;
		current = 0;
	}

	bool isEmpty() {
		return current == 0;
	}

	bool isFull() {
		return current == capacity;
	}
};

int G;

class State {
public:
	vector<glass> glasses;

	bool isGoal()
	{
		for (glass g : glasses)
		{
			if (g.current == G)
				return true;
		}
	}

	vector<State> generateNext()
	{
		vector<State> final;
		for (size_t i = 0; i < glasses.size(); ++i)
		{
			for (size_t j = 0; j < glasses.size(); ++j)
			{
				if (i != j)
				{

				}
			}
		}
	}

	State pour(State currState, int from, int to) {
		/*
		int toNew = currState.glasses[to].current += currState.glasses[from].current;
		// capacity of glass 2 is enough
		if (toNew <= currState.glasses[to].capacity) {
			currState.glasses[to].current = toNew; // pour into new glass
			currState.glasses[from].current = 0; // empty current glass
		}
		else {
			currState.glasses[to].
		}

		return currState;
		*/
		int x = min(currState.glasses[from].current, currState.glasses[to].capacity-currState.glasses[to].current);
		State curr = currState;
		curr.glasses[from].current -= x;
		curr.glasses[to].current += x;
		return curr;
	}
};
State bfs(State first) {
	queue<State> queue;
	queue.push(first);
	while (!queue.empty()) {
		State current = queue.front();
		if (current.isGoal())
			return current;
		queue.pop();
		vector<State> possibleStates = current.generateNext();
		for (size_t i = 0; i < possibleStates.size(); i++) {
			if(!isVisited(possibleStates[i]))
				queue.push(possibleStates[i]);
		}
	}
		return first;
}

State parent[30][30][30];
bool visited[30][30][30];

State getParent(State st) {
	return parent[st.glasses[0].current][st.glasses[1].current][st.glasses[2].current];
}

bool isVisited(State st) {
	return visited[st.glasses[0].current][st.glasses[1].current][st.glasses[2].current];
}

int main()
{
	cin >> G;
	// prevent autoclosing
	int a; cin >> a;
    return 0;
}

