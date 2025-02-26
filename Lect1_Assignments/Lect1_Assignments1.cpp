#include <iostream>
#include <string>
using namespace std;
string dao_tu(string str)
{
	int phong = str.length();
	for (int i = 0; i < phong / 2; i++)
	{
		char phong1 = str[i];
		str[i] = str[phong - i - 1];
		str[phong - i - 1] = phong1;
	}
	return str;
}
int main()
{
	string str;
	getline(cin, str);
	cout << dao_tu(str);
	return 0;
}
