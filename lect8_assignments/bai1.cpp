#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm phân hoạch Hoare
int partitionHoare(int arr[], int l, int r)
{
    int pivot = arr[l];       // Chọn phần tử đầu tiên làm pivot
    int i = l - 1;            // i bắt đầu từ ngoài biên trái
    int j = r + 1;            // j bắt đầu từ ngoài biên phải

    while (true)
    {
        // Di chuyển i sang phải đến khi tìm được phần tử >= pivot
        do
        {
            i++;
        } while (arr[i] < pivot);

        // Di chuyển j sang trái đến khi tìm được phần tử <= pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        // Nếu i < j thì hoán đổi 2 phần tử sai vị trí
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            // Khi i >= j thì trả về chỉ số j là vị trí phân hoạch
            return j;
        }
    }
}

// Hàm sắp xếp nhanh phân hoạch Hoare
void quickSortHoare(int arr[], int l, int r)
{
    if (l < r)
    {
        int j = partitionHoare(arr, l, r); // Phân hoạch mảng
        quickSortHoare(arr, l, j);         // Đệ quy sắp xếp phần bên trái
        quickSortHoare(arr, j + 1, r);     // Đệ quy sắp xếp phần bên phải
    }
}

int main()
{
    int n;
    cin >> n; // Nhập số lượng phần tử

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // Nhập mảng đầu vào
    }

    quickSortHoare(a.data(), 0, n - 1); // Gọi hàm QuickSort với mảng

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; // In mảng sau khi sắp xếp
    }
    cout << endl;

    return 0;
}