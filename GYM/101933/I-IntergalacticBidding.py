p = []
n, s = [int(i) for i in input().split()]
for i in range(n):
    i_ = input().split()
    p.append((int(i_[-1]), i_[0]))
p.sort(key=lambda x: -x[0])

ret = []
for i in p:
    if(i[0] <= s):
        ret.append(i[1])
        s -= i[0]
if(s == 0):
    print(len(ret))
    for i in ret:
        print(i)
else:
    print(0)
