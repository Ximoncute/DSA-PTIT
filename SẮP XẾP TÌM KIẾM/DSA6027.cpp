#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::vector<std::string> steps;
    for (int i = 0; i < n - 1; ++i)
    {

        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
        std::stringstream ss;
        ss << "Buoc " << (i + 1) << ": ";
        for (int k = 0; k < n; ++k)
        {
            ss << arr[k] << " ";
        }
        // Thêm chuỗi kết quả của bước này vào vector
        steps.push_back(ss.str());
    }

    // In các bước đã lưu theo thứ tự ngược
    for (int i = steps.size() - 1; i >= 0; --i)
    {
        std::cout << steps[i] << std::endl;
    }
}

int main()
{
    int t;
    std::cin >> t; // Đọc số lượng bộ test
    while (t--)
    {
        solve();
    }
    return 0;
}
