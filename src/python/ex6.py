file = open("test.txt", "r")
words = 0
for line in file:
    words += len(line.strip("\n").split())

file.close()
print(words)
