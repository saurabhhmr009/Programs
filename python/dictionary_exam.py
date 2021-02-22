# Find the percentage

if __name__ == '__main__':
    student_dict = {}
    student_num = int(input())
    for _ in range(student_num):
        name, *marks = input().split()
        marks = list(map(float, marks))
        student_dict[name] = marks
        #student_dict[name] = [float(input()), float(input()), float(input())]
    print(student_dict)
    
    query_name = input()
    
    if query_name in student_dict:
        result = (student_dict[query_name][0]+student_dict[query_name][1]+student_dict[query_name][2])/3
        print('%.2f'% result)
    else:
        print("Query name not found")

