if __name__ == '__main__':
    queries = int(input())
    l = []
    for _ in range(queries):
        user_input = input().split()
        command = user_input[0]
        arguments = user_input[1:]
        if command != "print":
            command = command+"("+",".join(arguments)+")"
            print(command)
            eval("l."+command)
        else:
            print(l)
