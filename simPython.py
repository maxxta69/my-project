greet = "Good day!"

print(f'{greet}\nYou are welcome to my python tutorial class')

name = input('Enter your name: ')
password = input('Enter your password: ')

if password == "example@123" and name == "example":
    print('Access granted!')
else:
    print('Access denied!')