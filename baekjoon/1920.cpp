#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
int n, m;
int a[MAX_N];

void quick(int* arr, int left, int right);
void merge(int* arr, int left, int right);
void mergesort(int* arr, int left, int right);
bool binarySearch(int* arr, int left, int right, int target);

int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
  scanf("%d", &a[i]);
  // quick(a, 0, n - 1);
  merge(a, 0, n - 1);

  cin >> m;
  for(int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    printf("%d\n", binarySearch(a, 0, n - 1, x));
  }

  return 0;
}

bool binarySearch(int* arr, int left, int right, int target)
{
  if(left >= right)
  return arr[left] == target;

  int mid = (left + right) / 2;

  if(arr[mid] == target) return true;
  bool f = arr[mid] < target;
  return binarySearch(arr, f ? mid + 1 : left, f ? right : mid - 1, target);
}

void quick(int* arr, int left, int right)
{
  int pivot = arr[(left + right) / 2];
  int l = left;
  int r = right;

  while(l <= r) {
    while(arr[l] < pivot) l++;
    while(arr[r] > pivot) r--;

    if(l <= r) {
      int tmp = arr[l];
      arr[l++] = arr[r];
      arr[r--] = tmp;
    }
  }

  if(left < r) quick(arr, left, r);
  if(l < right) quick(arr, l, right);
}

void merge(int* arr, int left, int right)
{
  if(left >= right) return;
  int mid = (left + right) / 2;
  merge(arr, left, mid);
  merge(arr, mid + 1, right);
  mergesort(arr, left, right);
}

void mergesort(int* arr, int left, int right)
{
  int tmp[right - left];
  int mid = (left + right) / 2;
  int l = left;
  int r = mid + 1;
  int k = 0;

  while(l <= mid && r <= right) {
    if(arr[l] <= arr[r]) tmp[k++] = arr[l++];
    else tmp[k++] = arr[r++];
  }

  while(l <= mid) tmp[k++] = arr[l++];
  while(r <= right) tmp[k++] = arr[r++];

  for(int i = 0; i < k; i++) arr[left + i] = tmp[i];
}
