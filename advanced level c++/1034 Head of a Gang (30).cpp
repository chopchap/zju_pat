#include <iostream>
#include <map>
using namespace std;
map<string, int> str2int, ans;
map<int, string> int2str;
int index = 1, k;
int stoifunc(string s) {
	if (str2int[s] == 0) {
		str2int[s] = index;
		int2str[index] = s;
		return index++;
	} else
		return str2int[s];
}
int G[2010][2010], weight[2010];
bool vis[2010];
void dfs(int u, int &head, int &numMbr, int &totalweight) {
	vis[u] = true;
	numMbr++;
	if (weight[u] > weight[head]) head = u;
	for (int v = 1; v < index; v++)
		if (G[u][v] > 0) {
			totalweight += G[u][v];
			G[u][v] = G[v][u] = 0;
			if (!vis[v]) dfs(v, head, numMbr, totalweight);
		}
}
void dfsTrave() {
	for (int i = 1; i < index; i++)
		if (!vis[i]) {
			int head = i, numMbr = 0, totalweight = 0;
			dfs(i, head, numMbr, totalweight);
			if (numMbr > 2 && totalweight > k) ans[int2str[head]] = numMbr;
		}
}
int main() {
	int n, w;
	cin >> n >> k;
	string s1, s2;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w;
		int id1 = stoifunc(s1);
		int id2 = stoifunc(s2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}
	dfsTrave();
	cout << ans.size() << endl;
	for (auto it = ans.begin(); it != ans.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}
