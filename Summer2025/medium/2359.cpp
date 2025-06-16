#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int answerNode = 0;
        vector<vector<float>> visited(edges.size(), {INFINITY, INFINITY});
        visited[node1][0] = 0;
        visited[node2][1] = 0;
        //In this case, edges is like an adjacency array where -1 means empty
        BFS(edges, visited, node1, 0);
        BFS(edges, visited, node2, 1);
        float minMax = INFINITY;
        //int instead of size_t because min doesn't work with size_t
        for (int i = 0; i < visited.size(); i++) {
            float currentMax = max(visited[i][0], visited[i][1]);
            if(currentMax < minMax) {
                minMax = currentMax;
                answerNode = i;
            }
            if (currentMax == minMax) {
                answerNode = min(answerNode, i);
            }
        }
        if(minMax == INFINITY) {
            return -1;
        }
        else {
            return answerNode;
        }
    }

    void BFS(vector<int>& adj, vector<vector<float>>& visited, int node, int nodePos) {
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int adjNode = adj[node];
            if(adjNode != -1 && visited[adjNode][nodePos] == INFINITY) {
                visited[adjNode][nodePos] = visited[node][nodePos] + 1;
                q.push(adjNode);
            }
        }
    }
};