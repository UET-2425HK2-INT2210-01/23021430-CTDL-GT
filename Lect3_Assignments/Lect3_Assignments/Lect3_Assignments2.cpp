#include <iostream>
using namespace std;

double result(int n)
{
	double value = 1;
	if (n == 0)
	{
		return 1;
	}
	else if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			value = value * 2;
		}
		return value;
	}
	else if (n < 0)
	{
		for (int i = 0; i < (n * -1); i++)
		{
			value = value / 2;
		}
		return value;
	}
}

int main()
{
	int n;
	cin >> n;
	cout << result(n);
	return 0;
}

//giả code
//khai báo hàm result có kiểu trả về là double nhận vào 1 int n
//khai báo 1 biến double value = 1
//xét 3 trường hợp
//TH1: n = 0 return 1
//TH2: n > 0
//duyệt vòng lặp for từ 0 đến n - 1
//mỗi vòng lặp nhân thên value với 2
//return value
//TH3: n < 0
//duyệt vòng lặp for từ 0 đến n - 1
//mỗi vòng lặp chia value cho 2
//return value
//=> đọ phức tạp của thuật toán O(n)