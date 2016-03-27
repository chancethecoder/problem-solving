#include <limits>
#include <cstdio>
#include <vector>
using namespace std;

const int INT_MAX = numeric_limits<int>::max();

int min(int a, int b)
{
	return a < b ? a : b;
}

struct RMQ{
	int n;
	vector<int> rangeVal;
	RMQ(const vector<int> &array)
	{
		n = array.size();
		rangeVal.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	int init(const vector<int> &array, int left, int right, int node)
	{
		if(left == right) return rangeVal[node] = array[left];

		int mid = (left + right) / 2;
		int leftVal = init(array, left, mid, node * 2);
		int rightVal = init(array, mid + 1, right, node * 2 + 1);
		return rangeVal[node] = min(leftVal, rightVal);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return INT_MAX;
		if(left <= nodeLeft && right >= nodeRight) return rangeVal[node];

		int mid = (nodeLeft + nodeRight) / 2;
		int leftVal = query(left, right, node * 2, nodeLeft, mid);
		int rightVal = query(left, right, node * 2 + 1, mid + 1, nodeRight);

		return min(leftVal, rightVal);
	}

	// interface
	int query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}
};

int main()
{
	int tc;
	for(scanf("%d", &tc); tc--;)
	{
		int n, q;
		vector<int> height;
		scanf("%d %d", &n, &q);
		height.resize(n);

		for(int i = 0; i < n; i++) scanf("%d", &height[i]);

		RMQ minTree(height);

		for(int i = 0; i < n; i++) height[i] *= -1;

		RMQ maxTree(height);
		
		for(int i = 0; i < q; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d\n", (-1) * maxTree.query(a, b) - minTree.query(a, b));
		}
	}
}
