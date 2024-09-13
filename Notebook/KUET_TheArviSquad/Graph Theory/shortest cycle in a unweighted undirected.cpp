const int N = 1e5 + 9; 
vector<int> graph[N+5];
void find_shortest_cycle(int n) {
    int ans = INT_MAX;
    for(int i=0;i<n;i++) {
        vector<int> dis(n, INT_MAX);
        vector<int> parents(n, -1);
        dis[i] = 0;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()) {
            int par = Q.front();
            Q.pop();
            for(auto child : graph[par]) {
                if(dis[child] == INT_MAX) {
                    dis[child] = dis[par] + 1;
                    parents[child] = par;
                    Q.push(child);
                }
                else if(parents[par] != child) {
                    ans = min(ans, dis[par] + dis[child] + 1);
                }
            }
        }
    }
    if(ans == INT_MAX) cout << "impossible\n";
    else {
        cout << ans << "\n";
    }
}