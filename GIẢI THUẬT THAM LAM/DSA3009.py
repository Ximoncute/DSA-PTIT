def solve():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        
        jobs = []
        for i in range(n):
            job_id, deadline, profit = map(int, input().split())
            jobs.append((job_id, deadline, profit))
        
        # Sắp xếp theo profit giảm dần
        jobs.sort(key=lambda x: x[2], reverse=True)
        
        # Tìm deadline lớn nhất
        max_deadline = max(job[1] for job in jobs)
        
        # Mảng để kiểm tra time slot đã sử dụng
        time_slot = [False] * (max_deadline + 1)
        
        job_count = 0
        total_profit = 0
        
        # Lặp qua các công việc đã sắp xếp
        for job_id, deadline, profit in jobs:
            # Tìm time slot trống gần deadline nhất
            for j in range(deadline, 0, -1):
                if not time_slot[j]:
                    time_slot[j] = True
                    job_count += 1
                    total_profit += profit
                    break
        
        print(job_count, total_profit)

if __name__ == "__main__":
    solve() 