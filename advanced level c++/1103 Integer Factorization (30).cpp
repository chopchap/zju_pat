#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tmpAns;
void init() {
	int tmp = 0, idx = 1;
	while (tmp <= n) {
		v.push_back(tmp);
		tmp = pow(idx++, p);
	}
}
void dfs(int idx, int sum, int depth, int facSum) {
	if (depth == k) {
		if (sum == n && facSum > maxFacSum) {
			ans = tmpAns;
			maxFacSum = facSum;
		}
		return;
	}
	while (idx >= 1) {
		if (sum + v[idx] <= n) {
			tmpAns[depth] = idx;
			dfs(idx, sum+v[idx], depth+1, facSum+idx);
		}
		if (idx-- == 1) return;
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &p);
	init(); 
	tmpAns.resize(k);
	dfs(v.size() - 1, 0, 0, 0);
	if (maxFacSum == -1) printf("Impossible");
	else {
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); i++) printf(" + %d^%d", ans[i], p);
	}
	return 0;
}
