#seprate strings with even and odd strings
n=input()
b=len(n)
s=''
u=''
for i in range(b):
    if ((i%2)==0):
        s+=str(n[i])
    else:
        u+=str(n[i])
print(s+" "+u)