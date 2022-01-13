#include <iostream>
using namespace std;

string validate(string s)
{
	int n = 0, l = 0, u = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
			n++;
		else if (isalpha(s[i]))
		{
			if (isupper(s[i]))
				u++;
			else
				l++;
		}
	}
	if (n && l && u)
		return "YES";
	return "NO";
}

int main()
{
	// code
	int T;
	cin >> T;
	string s;
	for (int i = 0; i < T; i++)
	{
		cin >> s;
		cout << validate(s);
	}
	return 0;
}