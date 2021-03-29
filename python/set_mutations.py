main = int(input())
A = set(map(int, input().split()))
operations = int(input())
for i in range(operations):
    cmd, num = input().split()
    B = set(map(int, input().split()))
    expression = f'A.{cmd}(B)'
    eval(expression)
print(sum(A))