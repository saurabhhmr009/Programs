def cal_apples(apples, num1, location1, range1, range2):
    return (sum(1 for x in range(num1) if ((apples[x]+location1) >= range1) and ((apples[x]+location1) <=range2)))

def cal_oranges(oranges, num2, location2, range1, range2):
    return(sum(1 for x in range(num2) if ((oranges[x]+location2) <= range2) and ((oranges[x]+location2) >=range1)))


if __name__ == '__main__':
    range1,range2 = map(int, input().split())
    location1, location2 = map(int, input().split())
    num1, num2 = map(int,input().split())
    apples = list(map(int, input().split()))
    oranges = list(map(int, input().split()))
    apples_num = cal_apples(apples, num1, location1, range1, range2);
    oranges_num = cal_oranges(oranges, num2, location2, range1, range2)
    print(apples_num)
    print(oranges_num)
