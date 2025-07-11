def solve():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        
        # Số may mắn chỉ có chữ số 4 và 7
        # Để có số nhỏ nhất, ta cần ít chữ số nhất
        # Ưu tiên sử dụng chữ số 7 (lớn hơn) để giảm số lượng chữ số
        
        # Kiểm tra tính khả thi
        # n phải chia hết cho một tổ hợp của 4 và 7
        found = False
        result = ""
        
        # Thử từ số lượng chữ số 7 tối đa xuống 0
        max_sevens = n // 7
        
        for sevens in range(max_sevens, -1, -1):
            remaining = n - sevens * 7
            
            # Kiểm tra xem phần còn lại có chia hết cho 4 không
            if remaining % 4 == 0:
                fours = remaining // 4
                
                # Tạo số may mắn nhỏ nhất: đặt các chữ số 4 trước, sau đó là 7
                result = '4' * fours + '7' * sevens
                found = True
                break
        
        if found:
            print(result)
        else:
            print(-1)

if __name__ == "__main__":
    solve() 