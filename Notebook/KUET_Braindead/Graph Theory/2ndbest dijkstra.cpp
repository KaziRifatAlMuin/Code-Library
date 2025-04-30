pair<ll, ll> dis[N + 2];
void bfs() {
    queue<pair<int, int>> Q;
    Q.push({1, 0});
    dis[1].first = 0;
    while(!Q.empty()) {
        auto [pn, pw] = Q.front();
        Q.pop();
        for(auto [w, v] : adj[pn]) {
            //cout << v << " " << w << "\n";
            //cout << dis[v].second << " " << (pw + w) << "\n"; 
            if(dis[v].second > (pw + w)) {
                if(dis[v].first > (pw + w)) {
                    dis[v].second = dis[v].first;
                    dis[v].first = (pw + w);
                    Q.push({v, pw + w});
                }
                else if(dis[v].first != (pw + w)) {
                    dis[v].second = (pw + w);
                    Q.push({v, pw + w});
                }
            }
        }
    }
}
