#include<bits/stdc++.h>
using namespace std;

//Depth Limited Search
bool DLS(const vector< vector<int> >& g, int startnode, int targetnode, int DepthLimit)
{
    if (startnode == targetnode)
        return true;
    if (DepthLimit <= 0)
        return false;
    for (int nextnode : g[startnode])
    {
        if (DLS(g, nextnode, targetnode, DepthLimit - 1))
            return true;
    }
    return false;
}

int main()
{
    vector< vector<int> > g = { {1, 2}, {1,}, {}, {3}, {2} };
    int startnode = 0;
    int targetnode = 3;
    int DepthLimit = 4;
    if ( DLS(g, startnode, targetnode, DepthLimit) )
        cout << "Congo! Target is reachable within Depth Limit." << endl;
    else
        cout << "Sorry! Target is not reachable within Depth Limit." << endl;
    return 0;
}
