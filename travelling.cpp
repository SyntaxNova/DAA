#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int n; // Number of cities
vector<vector<int>> cost; // Cost matrix
vector<int> path; // Current path
vector<int> minPath; // Minimum cost path
int minCost = INF; // Minimum cost

void branchAndBound(int curr, int currentCost, vector<bool>& visited) 
 {
    if (currentCost >= minCost)
    {
        return; // Pruning the branch if the cost exceeds the minimum cost found so far
    }

    bool allVisited = true;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i]) 
        {
            allVisited = false;
            break;
        }
    }

    if (allVisited) 
    {
        if (cost[curr][0] != 0 && currentCost + cost[curr][0] < minCost) 
        {
            minCost = currentCost + cost[curr][0];
            minPath = path;
        }
        return;
    }

    for (int i = 0; i < n; ++i) 
    {
        if (!visited[i] && cost[curr][i] != 0) 
        {
            visited[i] = true;
            path.push_back(i);
            branchAndBound(i, currentCost + cost[curr][i], visited);
            visited[i] = false;
            path.pop_back();
        }
    }
}

int main()
   {
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the cost matrix (enter 0 for unreachable cities):\n";
    cost.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true; // Starting from city 0
    path.push_back(0);
    branchAndBound(0, 0, visited);

    cout << "Minimum Cost: " << minCost << endl;
    cout << "Minimum Cost Path: ";
    for (int city : minPath) 
    {
        cout << city << " ";
    }
    cout << "0\n";

    return 0;
}