#include <cstdio>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long init(vector<long long> &tree, int start, int end, int node, vector<long long> &array)
{
	if(start == end) return tree[node] = array[start];

	int mid = (start + end) / 2;

	return tree[node] = (init(tree, start, mid, 2*node, array) * 
						init(tree, mid+1, end, 2*node+1, array)) % MOD;
}

long long query(vector<long long> &tree, int left, int right, int start, int end, int node)
{
	if(end < left || right < start) return 1;
	if(left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return (query(tree, left, right, start, mid, 2*node) * 
			query(tree, left, right, mid+1, end, 2*node+1)) % MOD;
}

long long update(vector<long long> &tree, int index, long long _new, int start, int end, int node)
{
	if(index < start || end < index) return tree[node];
	if(start == end) return tree[node] = _new;

	int mid = (start + end) / 2;

	return tree[node] = (update(tree, index, _new, start, mid, node*2) *
						update(tree, index, _new, mid+1, end, node*2+1)) % MOD;
}

int main()
{
	vector<long long> array;
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	array.resize(n+1);

	for(int i = 0; i < n; i++) scanf("%lld", &array[i]);

	vector<long long> tree;
	tree.resize(4*n);

	init(tree, 0, n-1, 1, array);

	for(int i = 0; i < m + k; i++)
	{
		int q, a, b;
		scanf("%d %d %d", &q, &a, &b);

		if(q == 1) update(tree, a-1, static_cast<long long>(b), 0, n-1, 1);
		else printf("%lld\n", query(tree, a-1, b-1, 0, n-1, 1));
	}
}
