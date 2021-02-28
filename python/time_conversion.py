
def convert_time(input_time):
    input_time = input_time.split(":");
    if input_time[2][2] == "A" :
        if input_time[0] == "12":
            con_time = f"00:{input_time[1]}:{input_time[2][:2]}"
        else :
            con_time = f"{input_time[0]}:{input_time[1]}:{input_time[2][:2]}"
    else:
        if input_time[0] == "12":
            con_time = f"{input_time[0]}:{input_time[1]}:{input_time[2][:2]}"
        else:
            con = int(input_time[0]) + 12
            con_time = f"{con}:{input_time[1]}:{input_time[2][:2]}"
    return con_time



if __name__ == '__main__':
    input_time = input()
    converted_time = convert_time(input_time)
    print(converted_time)
