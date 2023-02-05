
def hanoi(n, s, d):
    if n == 1:
        print(s, ' ', d)
        return

    via = 6 - s - d
    hanoi(n-1, s, via)
    print(s, ' ', d)
    hanoi(n-1, via, d)

if __name__ == '__main__':
    N = int(input())
    hanoi(N, 1, 3)