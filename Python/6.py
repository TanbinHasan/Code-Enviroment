s = input()
low = 0
up = 0
dig = 0
spec = 0
i = 0
len = len(s)
while i < len:
  ch = s[i]
  i = i + 1
  if ch >= 'a' and ch <= 'z':
    low = 1
  if ch >= 'A' and ch <= 'Z':
    up = 1
  if ch >= '0' and ch <= '9':
    dig = 1
  if ch == '_' or ch == '$' or ch == '#' or ch == '@':
    spec = 1
cnt = 0
ans = ""
if low == 0:
  if cnt == 0:
    ans += "Lowercase character missing"
  else:
    ans += ", Lowercase character missing"
  cnt += 1
if up == 0:
  if cnt == 0:
    ans += "Uppercase character missing"
  else:
    ans += ", Uppercase character missing"
  cnt += 1
if dig == 0:
  if cnt == 0:
    ans += "Digit missing"
  else:
    ans += ", Digit missing"
  cnt += 1
if spec == 0:
  if cnt == 0:
    ans += "Special character missing"
  else:
    ans += ", Special character missing"
  cnt += 1
if cnt == 0:
  print("OK")
else:
  print(ans)