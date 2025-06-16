#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        //Problem information
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> answer(n);

        //Special case of k = 0
        if (k == 0) {
            answer = vector<int>(n, 1);
            return answer;
        }  

        //Adjacency list for tree 1
        vector<vector<int>> adj1(n);
        for (size_t i = 0; i < edges1.size(); i++) {
            int node1 = edges1[i][0];
            int node2 = edges1[i][1];
            adj1[node1].push_back(node2);
            adj1[node2].push_back(node1);
        }

        //Create an adjacency list for tree 2
        vector<vector<int>> adj2(m);
        for (int i = 0; i < edges2.size(); i++) {
            int node1 = edges2[i][0];
            int node2 = edges2[i][1];
            adj2[node1].push_back(node2);
            adj2[node2].push_back(node1);
        }


        //The best node to connect to tree2 with is the node with the most targets for k-1.
        //We can find that via breadth first search on each node of tree 2.
        vector<int> numTargets2 = findNumTargets(adj2, m, k-1);

        //Select the best node from the second tree
        int bestNode = 0;
        for (size_t i = 0; i < numTargets2.size(); i++) {
            if (numTargets2[bestNode] < numTargets2[i]) {
                bestNode = i;
            }
        }

        //Now, we find the number of target nodes for each node in tree 1
        vector<int> numTargets1 = findNumTargets(adj1, n, k);

        //"Connect" each node with the bestnode and combine the resulting number of target nodes
        for (size_t i = 0; i < answer.size(); i++) {
            answer[i] = numTargets2[bestNode] + numTargets1[i];
        }
        return answer;
    }

    //Breadth First Search to find number of target nodes of each node in a tree
    vector<int> findNumTargets(vector<vector<int>> adj, int size, int k) {
        vector<int> numTargets(size, 0);
        for (size_t i = 0; i < adj.size(); i++) {
            //-1 means not visited, any other value means level of the node
            vector<int> visited(size, -1);
            queue<int> q;
            q.push(i);
            visited[i] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                numTargets[i]++;
                for (int j = 0; j < adj[node].size(); j++) {
                    int adjNode = adj[node][j];
                    if(visited[adjNode] == -1) {
                        visited[adjNode] = visited[node] + 1;
                        if(visited[adjNode] <= k) q.push(adjNode);
                    }
                }
            }
        }
        return numTargets;
    }
};