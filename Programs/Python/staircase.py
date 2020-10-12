#Hacker rank
# https://www.hackerrank.com/challenges/staircase/problem
def staircase(n):
    i=1
    for j in range(n,0,-1):
         print(' '*(j-1)+'#'*i)
         i+=1
         

if __name__ == '__main__':
    n = int(input())

    staircase(n)
