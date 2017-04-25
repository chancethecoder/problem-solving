#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_N = 1000;
int n;
int arr[MAX_N];

int solve() {
	int ret = 0;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++) {
		a[i] = b[i] = 1;
	}
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(arr[i] > arr[j] && a[i] < a[j] + 1) {
				a[i] = a[j] + 1;
			}
			if(arr[n - 1 - i] > arr[n - 1 - j] && b[n - 1 - i] < b[n - 1 - j] + 1) {
				b[n - 1 - i] = b[n - 1 - j] + 1;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(ret < a[i] + b[i] - 1) {
			ret = a[i] + b[i] - 1;
		}
	}

	return ret;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	cout << solve();
	return 0;
}
