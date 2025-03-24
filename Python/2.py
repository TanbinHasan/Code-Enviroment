from math import inf

MX = 50
g = [[] for _ in range(MX)]
w = [0] * MX  # Weighted values


def minimax(u, is_max_node, alpha, beta):
  if not g[u]:  # Leaf node
    return w[u]

  if is_max_node:
    best = -inf
    for v in g[u]:
      best = max(best, minimax(v, 0, alpha, beta))
      alpha = max(alpha, best)
      if alpha >= beta:
        break
    return best
  else:
    best = inf
    for v in g[u]:
      best = min(best, minimax(v, 1, alpha, beta))
      beta = min(beta, best)
      if alpha >= beta:
        break
    return best


def main():
  n, m = map(int, input().split())  # Nodes and edges
  w[1:n + 1] = map(int, input().split())  # Weighted values
  for _ in range(m):
    u, v = map(int, input().split())
    g[u].append(v)

  print(minimax(1, 1, -inf, inf))


if __name__ == "__main__":
  main()

"""
Sample Input:
31 30
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 3 1 5 6 2 1 7 3 8 9 2 10 1 3 7
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15
8 16
8 17
9 18
9 19
10 20
10 21
11 22
11 23
12 24
12 25
13 26
13 27
14 28
14 29
15 30
15 31

Expected Output:
3
"""
