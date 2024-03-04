#include <bits/stdc++.h>
using namespace std;

// Graph Map
map<char, vector<char> > graph;

// Map to store cost of edges
map<pair<char, char>, int> cost;

// Returns the minimum cost in a vector( if there are multiple goal states)
map<char, int> uniform_cost_search(vector<char> goal, char start)
{
	// Minimum cost upto goal state from starting state
	map<char, int> answer;

	// create a priority queue
	priority_queue<pair<int, char> > queue;

	// set the answer vector to max value
	for (char i : goal)
		answer[i] = INT_MAX;

	// insert the starting index
	queue.push(make_pair(0, start));

	// map to store visited node
	map<char, int> visited;

	// count
	int count = 0;

	// while the queue is not empty
	while (queue.size() > 0) {

		// get the top element of the
		// priority queue
		pair<int, char> p = queue.top();

		// pop the element
		queue.pop();

		// get the original value
		p.first *= -1;

		// check if the element is part of the goal list
		if (find(goal.begin(), goal.end(), p.second) != goal.end()) {

			// if a new goal is reached
			if (answer[p.second] == INT_MAX)
				count++;

			// if the cost is less
			if (answer[p.second] > p.first)
				answer[p.second] = p.first;

			// pop the element
			queue.pop();

			// if all goals are reached
			if (count == goal.size())
				return answer;
		}

		// check for the non visited nodes
		// which are adjacent to present node
		if (visited[p.second] == 0)
			for (char i : graph[p.second]) {

				// value is multiplied by -1 so that
				// least priority is at the top
				queue.push(make_pair((p.first +
				cost[make_pair(p.second, i)]) * -1,
				i));
			}

		// mark as visited
		visited[p.second] = 1;
	}

	return answer;
}

// main function
int main()
{
	// add edge
    graph['S'].push_back('A');
    graph['S'].push_back('G');
    graph['A'].push_back('B');
    graph['A'].push_back('C');
    graph['B'].push_back('D');
    graph['C'].push_back('D');
    graph['C'].push_back('G');
    graph['D'].push_back('G');
    graph['D'].push_back('G');


    // add the cost
    cost[make_pair('S', 'A')] = 1;
    cost[make_pair('S', 'G')] = 12;
    cost[make_pair('A', 'B')] = 3;
    cost[make_pair('A', 'C')] = 1;
    cost[make_pair('B', 'D')] = 3;
    cost[make_pair('C', 'D')] = 1;
    cost[make_pair('C', 'G')] = 2;
    cost[make_pair('D', 'G')] = 3;
    cost[make_pair('D', 'G')] = 3;

	// goal state
	vector<char> goal;

	// set the goal ,there can be multiple goal states
	goal.push_back('G');

	// Answer array contain the final ans
	map<char, int> answer = uniform_cost_search(goal, 'S');

	// print the answer
	cout << "Minimum cost from Starting node S to Goal node G is = "
		<< answer['G'] << endl;
    return 0;
}
