#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int str[10000];

int find(int a)
{
	if (a == arr[a])
		return a;

	return arr[a] = find(arr[a]);
}

bool join(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a==b)	return false;

	if (str[a] < str[b])
		swap (a,b);

	ste[b] = a;
	if (str[a] == str[b])
		str[a]++;

	return true;
}

int main()
{
	long long weight = 1;

	int n,m;
	cin >> n >> m;

	vector <pair < long long, pair<int,int> > > v;

	for (int i=0; i<n; i++)
	{
		arr[i] = i;
		str[i] = 1;
	}

	for (int i=0; i<m; i++)
	{
		long long k;
		int a,b;
		cin >> a >> b >> k;

		v.push_back(make_pair(k, make_pair(a,b)));
	}

	sort(v.rbegin(), v.rend());

	for (auto it: v)
	{
		long long k;
		int a,b;

		k = it.first;
		a = it.second.first;
		b = it.second.second;

		if (join(a,b))
			weight = (weight * k) % 1000000007;
	}

	cout << weight << "\n";
	return 0;
}
