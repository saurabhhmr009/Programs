if __name__ == '__main__':
    n = int(input())
    student = [[input(), float(input())] for i in  range(n)]           
    scores = sorted({s[1] for s in student})
    print(scores)
    result = sorted(s[0] for s in student if s[1] == scores[1])
    print(result)
    print('\n'.join(result))
