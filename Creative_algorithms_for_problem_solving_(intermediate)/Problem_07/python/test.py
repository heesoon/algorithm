
def solve(v, n, w):
    r = 0
    for i in range(n - w):
        ir = 0
        for j in range(i, i + w):
            ir += v[j]
        
        if(ir > r):
            r = ir
    
    return r

def main():
    v = [1, 0, 2, 0, 4, 3]
    n = 6
    w = 3
    r = 0
    
    r = solve(v, n, w)
    
    print(r)

if __name__ == "__main__":
    main()