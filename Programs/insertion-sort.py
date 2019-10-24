def insSort(arr):
    for i in range(1,len(arr)):  #we initiate it from 1 as we assume 0th element as sorted.
        key=arr[i] #assign the key
        j=i-1
        while key<arr[j] and j>=0: #this loop shifts all the elements greater than key
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key #after shifting prosess this give the key its right position.
    return arr
    
    
x=[2,7,3,9,1,6]
print(insSort(x))
