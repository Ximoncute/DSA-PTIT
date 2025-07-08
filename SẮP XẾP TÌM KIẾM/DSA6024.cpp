#include <iostream>
#include <vector>
#include <utility>

void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        std::swap(arr[min_idx], arr[i]);
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

    selectionSort(arr);

    return 0;
}
