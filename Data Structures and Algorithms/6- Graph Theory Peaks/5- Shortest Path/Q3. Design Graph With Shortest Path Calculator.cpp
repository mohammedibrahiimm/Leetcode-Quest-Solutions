class Graph {
public:
    vector<int>dist;
    vector<vector<pair<int, int>>>g;
    Graph(int n, vector<vector<int>>& edges) {
        dist.resize(n, 1e9);
        g.resize(n);
        for (auto &it : edges) {
            g[it[0]].push_back({it[1], it[2]});
        }
    }

    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {

        priority_queue<pair<int, int>>pq;
        pq.push({0, node1});
        for (int i = 0; i < dist.size(); i++)
            dist[i] = 1e9;
        dist[node1] = 0;
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            if (-cur.first != dist[cur.second])
                continue;
            for (auto &it : g[cur.second]) {
                if (dist[it.first] > dist[cur.second] + it.second) {
                    dist[it.first] = dist[cur.second] + it.second;
                    pq.push({ -dist[it.first], it.first});
                }
            }
        }
        if (dist[node2] == 1e9)
            dist[node2] = -1;
        return dist[node2];
    }
};