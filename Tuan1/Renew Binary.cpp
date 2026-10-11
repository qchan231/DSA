#include <iostream>
using namespace std;

long long a, k, b, n, m;

bool check(long long d) 
{
	long long x = d - d / k;
	long long y = d - d / m;
	if (x >= (n + a - 1) / a) return true;
	if (y >= (n + b - 1) / b) return true;
	long long u = a * x;
	long long v = b * y;
	return (u + v >= n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> k >> b >> m >> n;
	long long l = 0, r = n;
	while (l < r)
	{
		long long mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << "\n";
	return 0;
}