// T.C -: O(NLogN) & S.C -: O(1) Ternary Search
#include <bits/stdc++.h>
using namespace std;

int computeCost(int arr[], int N, int X)
{
	int cost = 0;
	for (int i = 0; i < N; i++)
		cost += abs(arr[i] - X);
	return cost;
}


int minCostToMakeElementEqual(int arr[], int N)
{
	int low, high;
	low = high = arr[0];
	for (int i = 0; i < N; i++) {
		if (low > arr[i])
			low = arr[i];
		if (high < arr[i])
			high = arr[i];
	}

	while ((high - low) > 2) {

		int mid1 = low + (high - low) / 3;
		int mid2 = high - (high - low) / 3;

		int cost1 = computeCost(arr, N, mid1);
		int cost2 = computeCost(arr, N, mid2);
		if (cost1 < cost2)
			high = mid2;

		else
			low = mid1;
	}

	return computeCost(arr, N, (low + high) / 2);
}

int main()
{
	int arr[] = { 1, 100, 101 };
	int N = sizeof(arr) / sizeof(int);
	cout << minCostToMakeElementEqual(arr, N);
	return 0;
}

// T.C -: O(N) & S.C -: O(1) Geometric Solution
#include <bits/stdc++.h>
using namespace std;

int minCostToMakeElementEqual(int a[], int n)
{

	int y;
	if (n % 2 == 1)
		y = a[n / 2];
	else
		y = (a[n / 2] + a[(n - 2) / 2]) / 2;

	int s = 0;
	for(int i = 0; i < n; i++)
		s += abs(a[i] - y);
		
	return s;
}

int main()
{
	int a[] = { 1, 100, 101 };
	int n = sizeof(a) / sizeof(a[0]);
	
	cout << (minCostToMakeElementEqual(a, n));
}

