# Enter your code here. Read input from STDIN. Print output to STDOUT
if __name__ == '__main__':
    n, m = input().split()
    elements = list(map(int, input().split()))
    set_A = set(map(int, input().split()))
    set_B = set(map(int, input().split()))
    happiness = 0
    for i in range(len(elements)):
        if elements[i] in set_A:
            happiness = happiness+1
        if elements[i] in set_B:
            happiness = happiness -1
    print(happiness)
