

class Solution{
    typedef vector<int> vec;
    typedef unordered_map<int, vec> map;
    bool detect_cycle_in_undirected_graph_dfs(vector<vector<int>> &graph, int V){

        map adj;

        for(auto & g : graph){
            int u = g[0];
            int v = g[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vec vis(V, 0);

        return dfs(adj, 0, -1, vis);
    }

    bool solve(map &adj, int node, int parent, vec &vis){

        // mark node as visited
        vis[node] = 1;


        for(auto curr : adj[node]){
            if(curr == parent)continue;
            if(vis[curr] == 1)return true;

            return solve(adj, curr, node, vis);
        }

        return false;
    }   
}