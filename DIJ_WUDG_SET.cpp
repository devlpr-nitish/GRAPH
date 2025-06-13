
// used set to reduce extra operations
class Solution{
    typedef pair<int, int> P;
    typedef unordered_map<int, P> map;
    vector<int> dijkstra_algo_weighted_undirected_graph(vector<vector<int>> &graph, int src, int V){

        map adj;

        for(auto & g : graph){
            int u = g[0];
            int v = g[1];
            int w = g[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> dist(V, INT_MAX);
        set<P> st;

        // src to src distance will be 0
        st.insert({0, src});
        dist[src] = 0;


        while(!pq.empty()){
            auto &p = *st.begin();
            pq.pop();
            int node = p.second;
            int weight = p.first;


            for(auto &ngh : adj[node]){
                int curr_node = ngh.first;
                int curr_weight = ngh.second;

                // found a better way
                if(weight + curr_weight < dist[curr_node]){

                    // if that distance is previously updated and not again there is smaller distance
                    // available then set must have that node present so, erase that node
                    // to reduce further operations 
                    if(dist[curr_node] != INT_MAX){
                        st.erase({dist[curr_node], curr_node});

                        // other way to erase
                        /*
                        auto itr = st.find({dist[curr_node], curr_node})
                        st.erase(itr);
                        */
                    }

                    dist[curr_node] = weight + curr_weight;
                    st.insert({dist[curr_node], curr_node});
                }
            }
        }
        
        return dist;
    }
}