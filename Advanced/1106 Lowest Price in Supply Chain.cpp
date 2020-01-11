/**
 * Sample input:
 * 10 1.80 1.00
 * 3 2 3 5
 * 1 9
 * 1 4
 * 1 7
 * 0
 * 2 6 1
 * 1 8
 * 0
 * 0
 * 0
 * --------------
 * Sample output:
 * 1.8362 2
 */
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
const double INF = 1e12;
vector<int> node[maxn];
int n, num = 0;
double p, r, ans = INF;

void DFS(int index, int depth)
{
	if (node[index].size() == 0) {
		double price = p * pow(1+r, depth);
		if (price < ans) {
			ans = price;
			num = 1;
		} else if (price == ans)
			num++;
		return;
	}
	for (int i = 0; i < (int)node[index].size(); i++)
		DFS(node[index][i], depth+1);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	int k, child;

	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k != 0)
			for (int j = 0; j < k; j++) {
				scanf("%d", &child);
				node[i].push_back(child);
			}
	}
	DFS(0, 0);
	printf("%.4f %d\n", ans, num);

	return 0;
}


