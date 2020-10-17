from subprocess import call

call("cls", shell=True)
file = open("text.txt").readlines()
lines_quantity = len(file)

for line in range(lines_quantity, 0, -1):
    print(file[line-1].strip(), end="")