
class Solution{
    typedef vector<int> vec;
    typedef unordered_map<int, vec> map;
    typedef pair<int,int> P;
    bool detect_cycle_in_undirected_graph_bfs(vector<vector<int>> &graph, int V){
        map adj;

        for(auto & g : graph){
            int u = g[0];
            int v = g[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vec vis(V, 0);
        queue<P> q;

        q.push({0, -1});
        vis[0] = 1;


        while(!q.empty()){

            P p = q.front();
            q.pop();

            int node = p.first;
            int parent = p.second;


            for(auto curr : adj[node]){
                if(curr == parent)continue;
                if(vis[curr] == 1)return true;

                vis[curr] = 1;
                q.push({curr, node});
            }
        }

        return false;
    }
}