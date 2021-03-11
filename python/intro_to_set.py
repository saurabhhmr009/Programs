def average(array):
    # your code goes here
    arr_set = set(arr)
    total = len(arr_set)
    arr_sum = sum(arr_set)
    aver = arr_sum/total
    return aver

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
