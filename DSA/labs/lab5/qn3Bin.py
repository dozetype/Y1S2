file = open("labs/lab5/qn3.txt", 'r')

capacity = 0
BOX = []
best = 0
bestSelection = []
for i in file:
    line = i.strip().split()
    if(len(line) == 1):
        capacity = int(line[0])
    elif(len(line) == 2):
        BOX.append(line)
        
    else:
        size = len(BOX)
        for i in range(pow(2,size)):
            currChoice = format(i, 'b').rjust(size, '0') #generating binary or combi
            currValue = 0
            currWeight = 0
            currSelection = []
            for pos, bin in enumerate(currChoice):
                if(bin=='1'): #add if bin is '1'
                    currSelection.append(BOX[pos])
                    currWeight += int(BOX[pos][0])
                    currValue += int(BOX[pos][1])

            if(currWeight <= capacity): #checking if current combi is better
                if(currValue > best):
                    bestSelection = currSelection #storing best
                    best = currValue
        print(size , bestSelection)

        
        BOX = []
        best = 0