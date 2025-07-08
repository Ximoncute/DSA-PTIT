#include <iostream>
#include <vector>
#include <utility> 

void interchangeSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
        // In ra bước thực hiện sau mỗi vòng lặp ngoài
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

    interchangeSort(arr);

    return 0;
}
