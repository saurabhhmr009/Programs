if __name__ == '__main__':
    x1,v1,x2,v2 = map(int, input().split())
    if v2>=v1:
        print("NO")
    else:
        if(x1-x2)%(v2-v1) == 0:
            print("YES")
        else:
            print("NO")
