def squr_root(n):
    x=0
    while (x+1)*(x+1)<=n:
        x+=1
    return x
print(squr_root(16))
