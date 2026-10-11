#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector <long long>& a, int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	MergeSort(a, l, m);
	MergeSort(a, m + 1, r);
	vector<long long> tmp;
	int i = l, j = m + 1;
	while (i <= m && j <= r)
	{
		if (a[i] < a[j]) tmp.push_back(a[i++]);
		else tmp.push_back(a[j++]);
	}
	while (i <= m) tmp.push_back(a[i++]);
	while (j <= r) tmp.push_back(a[j++]);
	for (int t = 0; t < tmp.size(); t++) a[l + t] = tmp[t];
}

int Search(const vector<long long>& a, long long la, long long x)
{
	int l = la, r = a.size() - 1, res = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] <= x)
		{
			res = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long x;
	cin >> n >> x;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	MergeSort(a, 0, n - 1);
	long long best = 0;
	for (int i = 0; i < n - 1;i++)
	{
		int j = Search(a, i + 1, x - a[i]);
		if (j != -1 && a[i] + a[j] > best) best = a[i] + a[j];
	}
	cout << best << "\n";
	return 0;
}