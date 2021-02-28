def staircase(n):
    levels = n-2
    for i in range(1, n):
        print(" " * levels, "#" * i)
        levels -= 1
    print("#" * n)
        

if __name__ == '__main__':
    n = int(input())
    staircase(n)
