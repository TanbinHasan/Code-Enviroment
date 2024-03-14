n = int(input())

d = {}
memo = [[-1, -1, -1] for i in range(n+1)]
print(memo)
curo = 0
def dfs(v):
    if memo[v][0] != -1:
        return memo[v]
    l = len(d[v])
    nz = no = ni = 0
    for i in range(l):
        if memo[d[v][i][0]][0] == -1:
            a, b, c = dfs(d[v][i][0])
            if d[v][i][1]:
                no += 1
            else:
                nz += 1
            nz += a
            no += b
            ni = curo * a + c
            curo += b

    memo[v] = [nz, no, ni]
    return memo[v]


for i in range(n):
    m = int(input())
    for j in range(m):
        v, w = list(map(int, input().split()))
        if (i+1) in d:
            d[i+1] += [(v, w)]
        else:
            d[i+1] = [(v, w)]
a, b, c = dfs(1)
print(a, b, c)