// Phân đoạn Lomuto
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm partition: sắp xếp lại mảng xung quanh pivot
// Trả về chỉ số của pivot
int partition(int arr[], int l, int r)
{
	int pivot = arr[r];     // Chọn phần tử cuối cùng làm pivot
	int i = l - 1;          // i là chỉ số của phần tử nhỏ hơn pivot

	for (int j = l; j < r; j++)  // Duyệt từ l đến r - 1
	{
		if (arr[j] <= pivot)    // Nếu phần tử nhỏ hơn hoặc bằng pivot
		{
			i++;
			swap(arr[j], arr[i]);  // Đưa phần tử nhỏ hơn về trước
		}
	}
	i++; // Đặt pivot vào vị trí đúng giữa các phần tử nhỏ hơn và lớn hơn
	swap(arr[i], arr[r]);
	return i; // Trả về chỉ số pivot sau sắp xếp
}

// Hàm quicksort
void quicksort(int arr[], int l, int r)
{
	if (l >= r) // Điều kiện dừng
		return;         // Trường hợp cơ bản: mảng có 0 hoặc 1 phần tử

	int p = partition(arr, l, r);  // Chia mảng và lấy chỉ số pivot
	quicksort(arr, l, p - 1);      // Đệ quy sắp xếp phần bên trái pivot
	quicksort(arr, p + 1, r);      // Đệ quy sắp xếp phần bên phải pivot
}

int main()
{
	int n;
	cin >> n;                     // Nhập số lượng phần tử

	vector<int> arr(n);           // Tạo vector chứa n phần tử

	for (int i = 0; i < n; i++)   // Nhập các phần tử
	{
		cin >> arr[i];
	}

	// Gọi quicksort với dữ liệu thô từ vector
	quicksort(arr.data(), 0, n - 1);

	for (int i = 0; i < n; i++)   // In mảng đã sắp xếp
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}