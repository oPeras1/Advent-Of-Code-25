lines = ""

with open('input.txt') as f:
    lines = f.read()

lines = lines.split()

i = 50
c = 0

for line in lines:
    n = int(line[1:])
    f = line[0]

    if f == "R":
        i += n
    elif f == "L":
        i -= n

    i = i % 100

    if i == 0:
        c += 1

print(c)