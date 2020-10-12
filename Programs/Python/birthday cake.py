#hackerrank
#https://www.hackerrank.com/challenges/birthday-cake-candles/submissions/code/127907287

def birthdayCakeCandles(ar):
    q=0
    
    c=max(ar)
    for i in range(len(ar)):
        if(ar[i]==c):
            q+=1
    
    return(q)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = birthdayCakeCandles(ar)

    fptr.write(str(result) + '\n')

    fptr.close()
