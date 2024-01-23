void dfs(int start, vector<int>*edges, bool *visited, vector<int>& ans)
{
	visited[start] = true;
	for (auto i : edges[start])
	{
		if (visited[i])
			continue;
		dfs(i, edges, visited, ans);
	}
	ans.pb(start);
}
vector<int> topo_sort(int n, vector<int>*edges)
{
	vector<int> v1;
	bool *visited = new bool[n]();
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		dfs(i, edges, visited, v1);
	}
	reverse(v1.begin(), v1.end());
	return v1;
}