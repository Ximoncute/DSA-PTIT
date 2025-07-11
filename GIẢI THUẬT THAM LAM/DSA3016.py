def solve():
    t = int(input())
    
    for _ in range(t):
        S, D = map(int, input().split())
        
        # Kiểm tra tính hợp lệ
        if S == 0:
            if D == 1:
                print("0")
            else:
                print("-1")
            continue
        
        if S > 9 * D:
            print("-1")
            continue
        
        # Tạo mảng chứa các chữ số (khởi tạo với 0)
        result = [0] * D
        
        # Để có số nhỏ nhất, ta bắt đầu từ chữ số đầu tiên
        # Đặt chữ số đầu tiên là 1 để đảm bảo số không bắt đầu bằng 0
        result[0] = 1
        remaining = S - 1
        
        # Điền từ cuối về đầu để có số nhỏ nhất
        for i in range(D - 1, 0, -1):
            if remaining > 0:
                add = min(9, remaining)
                result[i] = add
                remaining -= add
        
        # Thêm phần còn lại vào chữ số đầu tiên
        result[0] += remaining
        
        # In kết quả
        print(''.join(map(str, result)))

if __name__ == "__main__":
    solve() 