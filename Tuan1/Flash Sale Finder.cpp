#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> items(N);
	vector<int> price(N);
	for (int i = 0; i < N; i++)
	{
		cin >> items[i] >> price[i];
	}
	int X;
	cin >> X;
	bool found = false;
	for (int i = 0; i < N; i++)
	{
		if (price[i] <= X)
		{
			cout << items[i] << endl;
			found = true;
		}
	}
	if (!found)
	{
		cout << "No items found" << endl;
	}
}