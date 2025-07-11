import heapq
from collections import Counter

def solve():
    t = int(input())
    
    for _ in range(t):
        k = int(input())
        s = input().strip()
        
        # Đếm tần suất xuất hiện của mỗi ký tự
        freq = Counter(s)
        
        # Tạo max-heap với tần suất (sử dụng số âm vì Python chỉ có min-heap)
        max_heap = [-count for count in freq.values()]
        heapq.heapify(max_heap)
        
        # Thực hiện K lần loại bỏ ký tự
        for _ in range(k):
            if max_heap:
                # Lấy tần suất lớn nhất
                max_freq = -heapq.heappop(max_heap)
                
                # Giảm tần suất đi 1
                if max_freq > 1:
                    heapq.heappush(max_heap, -(max_freq - 1))
        
        # Tính giá trị cuối cùng (tổng bình phương các tần suất)
        result = sum(freq * freq for freq in [-x for x in max_heap])
        
        print(result)

if __name__ == "__main__":
    solve() 