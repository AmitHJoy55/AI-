#include<bits/stdc++.h>
using namespace std;

//Depth First Search
bool DFS(const vector<vector<int>>& g, int startnode, int targetnode, int depth)
{
    if (startnode == targetnode)
        return true;
    if (depth <= 0)
        return false;
    for (int nextnode : g[startnode])
    {
        if (DFS(g, nextnode, targetnode, depth - 1))
            return true;
    }
    return false;
}

// Iterative Deepening Search
bool IDS(const vector<vector<int>>& g, int startnode, int targetnode, int maxDepth)
{
    for (int depth = 0; depth <= maxDepth; ++depth)
    {
        if (DFS(g, startnode, targetnode, depth))
            return true;
    }
    return false;
}

int main()
{
    vector< vector<int> > g = { {1, 2}, {1,}, {}, {3}, {2} };
    int startnode = 0;
    int targetnode = 3;
    int maxDepth = 4;
    if (IDS(g, startnode, targetnode, maxDepth))
        cout << "Congo! Target is reachable within Depth Limit." << endl;
    else
        cout << "Sorry! Target is not reachable within Depth Limit." << endl;
    return 0;
}
