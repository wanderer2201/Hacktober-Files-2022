
def soln(n, m):
    if (n == 1 and m == 2) or (m == 1 and n == 2):
        return "Yes"
    if n == 1 or m == 1:
        return "No"
    if n&1 and m&1:
        return "No"
    return "Yes"

for _ in range(int(input())):
    n, m = map(int, input().split())
    print(soln(n, m))
