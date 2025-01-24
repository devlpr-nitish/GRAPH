
class Solution{

    // Function to perform Topological Sort using BFS (Kahn's Algorithm)
    bool topologicalSort(int V, vector<vector<int>>& adj) {

        vector<int> indegree(V, 0); // To store indegree of each vertex
        vector<int> topo;          // To store the topological order

        // Calculate the indegree of all vertices
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        // Queue to process nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process vertices in the queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node); // Add to topological order

            // Reduce indegree of neighbors
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor); // If indegree becomes 0, add to queue
                }
            }
        }

        // Check if the graph contains a cycle
        if (topo.size() != V) {
            return true;
        }

        return false;
    }

}