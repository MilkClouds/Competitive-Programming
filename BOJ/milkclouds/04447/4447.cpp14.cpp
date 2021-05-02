#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	char c = getchar();

	while (n--)
	{
		int g = 0, b = 0;
		string str;
		getline(cin, str);
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 'g' || str[i] == 'G')
				g++;
			else if (str[i] == 'b' || str[i] == 'B')
				b++;
		}
		if (g > b)
			cout << str << " is GOOD" << endl;
		else if (g < b)
			cout << str << " is A BADDY" << endl;
		else
			cout << str << " is NEUTRAL" << endl;
	}
	return 0;
}