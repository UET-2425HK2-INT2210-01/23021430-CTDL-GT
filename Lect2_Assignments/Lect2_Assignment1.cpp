#include <iostream>
using namespace std;

void readArray(int n, int array[])
{
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
}

int count(int n, int array[])
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i] == array[j])
			{
				sum++;
			}
		}
	}
	return sum;
}

int main()
{
	int n, array[100];
	cin >> n;
	readArray(n, array);
	cout << count(n, array);

	return 0;
}