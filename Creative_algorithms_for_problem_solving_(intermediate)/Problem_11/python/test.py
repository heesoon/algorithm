# refer to https://wikidocs.net/14

a = 7
b = 34
q = []

def solve(a):
    global q
    global b

    q.append([a, 0])

    while(len(q) != 0):
        (v, c) = q.pop(0)

        if v == b:
            return c
        elif v < b:
            q.append([v+10, c+1])
            q.append([v+5, c+1])
            q.append([v+1, c+1])
        else:
            q.append([v-10, c+1])
            q.append([v-5, c+1])
            q.append([v-1, c+1])

def main():
    r = solve(a)
    print(r)

if __name__ == "__main__":
    main()