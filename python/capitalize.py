import string
# Complete the solve function below.
def solve(s):
    s = s.split(' ')
    for i in range(len(s)):
        s[i] = s[i].capitalize()
    return(' '.join(s))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()
