# Split and join functions in Python

def split_and_join(line):
    split_line = line.split(" ")
    joined_line  = "-".join(split_line)
    return joined_line

if __name__ == '__main__':
    string = input()
    result = split_and_join(string)
    print(result)
