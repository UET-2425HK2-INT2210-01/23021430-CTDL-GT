#include <iostream>
using namespace std;
int uoc_max(int a, int b)
{
	int phong = a % b;
	if (phong == 0)
	{
		return b;
	}
	else {
		uoc_max(b, phong);
	}
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << uoc_max(a, b);
	return 0;
}
