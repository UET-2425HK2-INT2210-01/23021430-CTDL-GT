#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm merge: trộn hai đoạn
void merge(int a[], int l, int r, int m)
{
	// Tạo hai mảng tạm để chứa phần tử của hai nửa
	vector<int> left(a + l, a + m + 1);       // Mảng trái từ l đến m
	vector<int> right(a + m + 1, a + r + 1);  // Mảng phải từ m + 1 đến r

	int i = 0;  // Chỉ số hiện tại trong mảng trái
	int j = 0;  // Chỉ số hiện tại trong mảng phải

	// So sánh và trộn hai mảng lại vào mảng chính
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])  // Nếu phần tử bên trái nhỏ hơn hoặc bằng bên phải
		{
			a[l] = left[i];       // Gán phần tử trái vào mảng gốc
			i++;
		}
		else
		{
			a[l] = right[j];      // Gán phần tử phải vào mảng gốc
			j++;
		}
		l++; // Di chuyển chỉ số mảng gốc
	}

	// Sao chép các phần tử còn lại (nếu có) bên trái
	while (i < left.size())
	{
		a[l] = left[i];
		i++;
		l++;
	}

	// Sao chép các phần tử còn lại (nếu có) bên phải
	while (j < right.size())
	{
		a[l] = right[j];
		j++;
		l++;
	}
}

// Hàm mergeSort đệ quy: chia mảng thành các phần nhỏ, sau đó trộn lại
void mergeSort(int a[], int l, int r)
{
	if (l < r) // Điều kiện dừng 
	{
		int m = l + (r - l) / 2; // Tính chỉ số giữa
		mergeSort(a, l, m);      // Sắp xếp nửa trái
		mergeSort(a, m + 1, r);  // Sắp xếp nửa phải
		merge(a, l, r, m);       // Trộn hai nửa lại với nhau
	}
}

int main()
{
	int n;
	cin >> n; // Nhập số lượng phần tử

	vector<int> a(n); // Tạo vector chứa n phần tử

	for (int i = 0; i < n; i++) // Nhập các phần tử
	{
		cin >> a[i];
	}

	mergeSort(a.data(), 0, n - 1); // Gọi hàm mergeSort trên mảng dữ liệu gốc của vector

	for (int i = 0; i < n; i++) // In mảng đã sắp xếp
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
