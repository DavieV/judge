name = raw_input("What is your name? ")
age = raw_input("What is your age? ")
u_name = raw_input("What is your username? ")

print "your name is", name, ", you are", age, "years old, and your username is", u_name

f = open("easy.txt", "a")
data = name + " " + age + " " + u_name + '\n'
f.write(data)
