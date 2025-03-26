file = open("labs/lab5/qn3.txt", 'r')

def combs(a):
    if len(a) == 0:
        return [[]]
    cs = []
    for c in combs(a[1:]):
        cs += [c, c+[a[0]]]
    return cs

capacity = 0
currSelection = []
max = 0
best = []
for i in file:
    line = i.strip().split()
    if(len(line) == 1):
        capacity = int(line[0])
    elif(len(line) == 2):
        currSelection.append(line)
    else:
        combi = combs(currSelection)
        for i in combi:
            curr = [0, 0]
            curr2 = []
            for j in i:
                curr[0] += int(j[0])
                curr[1] += int(j[1])
                curr2.append(j)
            if(curr[1] > max and curr[0]<=capacity):
                best = curr2
                max = curr[1]
        print(best)
        currSelection = []
        print("\n\n")
