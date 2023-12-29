#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

static bool compare(const string& a, const string& b)
{
	// a가 b보다 먼저 오면 true

	// 길이 구하기
	if (a.size() > b.size())
	{
		return false;
	}
	else if (b.size() > a.size())
	{
		return true;
	}

	// 자리수 
	uint8_t asum = 0;
	uint8_t bsum = 0;

	for (const char c : a)
	{
		if (isdigit(c))
		{
			asum += c - '0';
		}
	}

	for (const char c : b)
	{
		if (isdigit(c))
		{
			bsum += c - '0';
		}
	}

	if (asum < bsum)
	{
		return true;
	}
	else if (asum > bsum)
	{
		return false;
	}

	return a < b;
}

int main()
{
	int N;
	cin >> N;

	vector<string> serials;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		serials.push_back(s);
	}

	sort(serials.begin(), serials.end(), compare);

	for (const string& s : serials)
	{
		cout << s << '\n';
	}

}