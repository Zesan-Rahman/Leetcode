#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        //Problem information
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> answer(n);

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


        //Choose a valid even root in case the nodes are numbered weirdly
        int root1 = 0;
        vector<int> numTargets1(n, 0);
        vector<int> visited1(n, -1);
        visited1[root1] = 0;
        fillNumTargets(adj1, visited1, root1, numTargets1);

        int evenCount1 = numTargets1[0];
        int oddCount1 = numTargets1[1];
        for (int i = 0; i < visited1.size(); i++) {
            if(visited1[i] % 2 == 0) {
                numTargets1[i] = evenCount1;
            }
            else {
                numTargets1[i] = oddCount1;
            }
        } 
        

        //The best node to connect to tree2 with is the node with the most targets where target node = odd distance.
        int evenRoot2 = 0;
        vector<int> numTargets2(m, 0);
        vector<int> visited2(m, -1);
        visited2[evenRoot2] = 0;
        fillNumTargets(adj2, visited2, evenRoot2, numTargets2);


        //Select the best node from the second tree
        int bestNodeTargets = max(numTargets2[1], numTargets2[0]);

        //"Connect" each node with the bestnode and combine the resulting number of target nodes
        for (size_t i = 0; i < answer.size(); i++) {
            answer[i] = numTargets1[i] + bestNodeTargets;
        }
        return answer;
    }


    void fillNumTargets(vector<vector<int>>& adj, vector<int>& visited, int node, vector<int>& numTargets) {    
        if (visited[node] % 2 == 0) {
            numTargets[0]++;
        }
        else {
            numTargets[1]++;
        }
        for (int i = 0; i < adj[node].size(); i++) {
            int adjNode = adj[node][i];
            if(visited[adjNode] == -1) {
                visited[adjNode] = visited[node] + 1;
                fillNumTargets(adj, visited, adjNode, numTargets);
            }
        }
    }
};