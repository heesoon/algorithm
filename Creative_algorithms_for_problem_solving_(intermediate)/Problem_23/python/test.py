
H = 3
W = 4
cnt = 0

def solve(h, w):
    global H, W, cnt
    if h > H or w > W+1:
        return
    
    if h == H and w == W+1:
        cnt = cnt + 1

    solve(h+1, w)
    if float(H)/W <= float(h)/w :
        solve(h, w+1)
    
def main():
    solve(0, 1)
    print(cnt)

if __name__ == "__main__" :
    main()