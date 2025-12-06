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
        c += (i+n) // 100

        i = (i+n) % 100
    elif f == "L":
        s = (i-1) // 100
        e = (i-n-1) // 100

        c += (s-e)

        i = (i-n) % 100

print(c)