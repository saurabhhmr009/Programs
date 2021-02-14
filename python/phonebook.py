

if __name__ == '__main__':
	number = int(input())
	phone_book = {}
	for _ in range(number):
		name,number = input().split(" ")
		print(name)
		print(number)
		phone_book[name] = number
	print(phone_book)
	
	while True:
		try:
			name = input()
			if name in phone_book:
				print(name, phone_book[name])
			else:
				print("Not found")
		except EOFError:
			break

