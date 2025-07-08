#include <iostream>
#include <vector>

// Hàm thực hiện thuật toán sắp xếp chèn và in ra các bước
void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();
    // Bắt đầu từ phần tử đầu tiên (chỉ số 0)
    for (int i = 0; i < n; ++i)
    {
        // Lấy phần tử hiện tại để chèn vào dãy đã sắp xếp
        int key = arr[i];
        int j = i - 1;

        // Di chuyển các phần tử của dãy đã sắp xếp (arr[0...i-1])
        // lớn hơn key về phía sau một vị trí
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Chèn key vào đúng vị trí
        arr[j + 1] = key;

        // In ra trạng thái của mảng sau mỗi bước
        std::cout << "Buoc " << i << ": ";
        for (int k = 0; k <= i; ++k)
        {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    insertionSort(arr);

    return 0;
}
