#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool linearSearch(const vector<string>& arr, const string& target)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == target)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int M;
	cin >> M;
	vector<string> blacklist(M);
	for (int i = 0; i < M; i++)
	{
		cin >> blacklist[i];
	}
	int N;
	cin >> N;
	cin.ignore();
	vector<int> spamIndices;
	for (int i = 1; i <= N; i++)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);
		string word;
		while (ss >> word)
		{
			if (linearSearch(blacklist, word))
			{
				spamIndices.push_back(i);
				break;
			}
		}
	}
	if (spamIndices.empty())
	{
		cout << "No spam found" << endl;
	}
	else
	{
		for (int i = 0; i < spamIndices.size(); i++)
		{
			cout << spamIndices[i] << endl;
		}
	}
	return 0;
}