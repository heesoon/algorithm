n = 5
m = 60
a = [30, 10, 20, 35, 40]
c = [3, 0, 3, 5, 4]

def self_define_min(a, b):
    #[ true value ] if [condition] else [false value]
    return a if a < b else b

def solve(idx, ms):
    if idx == n:
        if ms >= m:
            return 0
        else:
            return n*100
    
    return self_define_min(solve(idx+1, ms), solve(idx+1, ms+a[idx]) + c[idx])

def main():
    print(solve(0, 0))

if __name__ == "__main__":
    main()