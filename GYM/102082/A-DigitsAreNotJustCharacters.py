import re
n = int(input())


def split_(s):
    ret = re.findall(r"([a-zA-Z]+)|(\d+)", s)
    ret = [i or j for i, j in ret]
    ret = [i if re.match('[a-zA-Z]+', i) else int(i) for i in ret]
    return ret


def cmp_(a, b):
    for idx in range(min(len(a), len(b))):
        i = a[idx]
        j = b[idx]
        if(isinstance(i, str) and isinstance(j, str)):
            if(i < j):
                return -1
            elif(i > j):
                return 1
        elif(isinstance(i, int) and isinstance(j, int)):
            if(i < j):
                return -1
            elif(i > j):
                return 1
        elif(isinstance(i, str)):
            return 1
        else:
            return -1
    if(len(a) < len(b)):
        return -1
    elif(len(b) < len(a)):
        return 1
    else:
        return 0


s0 = split_(input())
for i in range(n):
    sn = split_(input())
    c = cmp_(s0, sn)
    if(c == 1):
        print("-")
    else:
        print("+")
