#Question 4 ################################################
li = [None] * 11
counter = 0

def hash(num, i):
    h = num%11
    d = i*(num%7+1)
    return (h+d)%11

def insert(num):
    for i in range(11):
        total = hash(num, i)
        if(li[total]==None):
            li[total] = num
            break

def search(num):
    global counter
    for i in range(11):
        counter += 1
        slot = hash(num, i)
        if(li[slot] == num):
            print("found", num)
            break
        if li[slot] is None:
            break


nums = [7,23,29, 15, 34]

for num in nums:
    insert(num)

for num in nums:
    search(num)

print(counter)
#####################################################################

