# formula1: (a + b)2
# formula2: (a - b)2
# formula3: (a + b) * (a - b)

def main():
    formula1(5,7)
    formula2(6,4)
    formula3(8,2)

def formula1(a, b):
    result = (a*a) + (2*a*b) + (b*b)
    print(result)

def formula2(a,b):
    result = (a*a) - (2*a*b) + (b*b)
    print(result)

def formula3(a, b):
    result = (a*a) - (b*b)
    print(result)

main() # By Fonta22
