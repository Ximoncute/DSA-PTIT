#include <iostream>
#include <vector>
#include <utility> 

// Hàm thực hiện thuật toán sắp xếp nổi bọt và in ra các bước
void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    bool swapped;
    // Vòng lặp ngoài: mỗi lần lặp sẽ đưa phần tử lớn nhất về cuối mảng
    for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;
        // Vòng lặp trong: so sánh các cặp phần tử liền kề
        // và đổi chỗ nếu chúng sai thứ tự
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true; // Đánh dấu là đã có sự thay đổi
            }
        }

        // Tối ưu: Nếu trong một vòng lặp không có sự đổi chỗ nào,
        // có nghĩa là mảng đã được sắp xếp và có thể dừng lại.
        if (swapped == false)
        {
            break;
        }

        // In ra trạng thái của mảng sau mỗi bước lặp có sự thay đổi
        std::cout << "Buoc " << i + 1 << ": ";
        for (int k = 0; k < n; ++k)
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

    bubbleSort(arr);

    return 0;
}
