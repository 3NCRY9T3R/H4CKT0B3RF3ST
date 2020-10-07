#two sum implementation in python 
def twosum(arr,summ):
        a=len(arr)
        for i in range(0,a):
            for j in range(i+1,a):
                if arr[i]+arr[j]==summ:
                    return i,j
  arr=[3,6,5,1,7]
  summ=12
  print(twosum(arr,summ))
