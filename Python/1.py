MOD = int(1e9 + 7)

def fastadd(x, y):
    return (MOD + (x % MOD) + (y % MOD)) % MOD

def fastmul(x, y):
    return ((x % MOD) * (y % MOD)) % MOD

def binpow(x, y):
    if y == 0:
        return 1
    powa = binpow(x, y // 2)
    powa = fastmul(powa, powa)
    if (y % 2 == 1):
        return fastmul(powa, x)
    return powa

def modinv(x, m = MOD):
    return binpow(x, m - 2)

def main():
    tc = int(input())
    for _ in range(tc):
        n = int(input())
        arr = list(map(int, input().split()))

        total_sum = sum(arr)

        sol = 0
        for i in range(n):
            sol = fastadd(sol, fastmul(total_sum - arr[i], arr[i]))
        
        print(fastmul(sol, modinv(fastmul(n, n - 1))))

if __name == "main__":
    main()
