def solve():
    # Đọc số lượng test case
    T = int(input())
    
    for _ in range(T):
        # Đọc số phần tử của mảng
        N = int(input())
        
        # Đọc mảng A
        A = list(map(int, input().split()))
        
        # Đọc mảng B
        B = list(map(int, input().split()))
        
        # Sắp xếp mảng A tăng dần
        A.sort()
        
        # Sắp xếp mảng B giảm dần
        B.sort(reverse=True)
        
        # Tính tổng tích
        result = 0
        for i in range(N):
            result += A[i] * B[i]
        
        print(result)

if __name__ == "__main__":
    solve() 