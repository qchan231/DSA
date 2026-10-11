#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tim_kiem(const vector<int>& a, int x)
{
	int l = 0, r = a.size() - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] < x) l = m + 1;
		else r = m - 1;
	}
	if (l == a.size()) return -1;
	return a[l];
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, q;
	if (! (cin >> n >> q)) return 0;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	sort(a.begin(), a.end());
	/*while (q--)
	{
		int x;
		cin >> x;	
		cout << tim_kiem(a, x) << endl;
	}*/
	vector <int> b(q);
	for (int i = 0; i < q; i++) cin >> b[i];
	for (int i = 0; i < q; i++) cout << tim_kiem(a, b[i]) << endl;
	return 0;
}