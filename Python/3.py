def is_valid(i, j):
    return 1 <= i <= 3 and 1 <= j <= 3

def probability(grid, i, j, prev1, prev2, memo):
    if i > 3:
        return 1  # All squares seen without disappointment.
    
    if (i, j, prev1, prev2) in memo:
        return memo[(i, j, prev1, prev2)]
    
    total_prob = 0
    next_i = i if j < 3 else i + 1
    next_j = j + 1 if j < 3 else 1
    
    for num in range(1, 10):
        if num != grid[i][j] and num != prev1 and num != prev2:
            total_prob += probability(grid, next_i, next_j, prev2, num, memo)
    
    memo[(i, j, prev1, prev2)] = total_prob
    return total_prob

def main():
    grid = []
    for _ in range(3):
        row = list(map(int, input().split()))
        grid.append(row)
    
    memo = {}
    prob = probability(grid, 1, 1, 0, 0, memo)
    print(prob)

if __name__ == "__main__":
    main()
