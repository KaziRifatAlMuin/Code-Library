bool dfs(int start, vector<int>*edges, bool *w, bool *g, bool *b)
{
	w[start] = false;
	g[start] = true;
	for (auto i : edges[start])
	{
		if (g[i])
			return false;
		if (w[i])
		{
			bool ans = dfs(i, edges, w, g, b);
			if (!ans)
				return false;
		}
	}
	g[start] = false;
	b[start] = true;
	return true;
}
bool check_cycle(int n, vector<int>*edges)
{
	bool *white = new bool[n]();
	bool *grey = new bool[n]();
	bool *black = new bool[n]();
	for (int i = 0; i < n; i++)
		white[i] = true;
	for (int i = 0; i < n; i++)
	{
		if (white[i])
		{
			bool ans = dfs(i, edges, white, grey, black);
			if (!ans)
				return true;
		}
	}
	return false;
}