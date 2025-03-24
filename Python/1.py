def rec(k, pos, v, n, a):
    global ans
    if k == 0:
        ans = max(ans, v)
        return
    for i in range(pos, n - k + 1):
        rec(k - 1, i + 1, v ^ a[i], n, a)

def solve():
    global ans
    ans = 0
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    rec(k, 0, 0, n, a)
    print(ans)

if __name__ == "__main__":
    solve()