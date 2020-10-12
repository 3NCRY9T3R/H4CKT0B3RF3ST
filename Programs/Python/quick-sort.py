#quick sort
x=[5,7,1,9,2,7,3,6]
lowest=0
highest=(len(x)-1)

def partition(arr,low,high):
    i=low-1
    pivot=arr[high] #setting the last element as pivot
    for j in range(low,high): # j is the loop variable
        
        if arr[j]<pivot:
            i=i+1         #i is the count of the greater number , that needs to be swapped
            arr[i],arr[j]=arr[j],arr[i] 
    arr[i+1],arr[high]=arr[high],arr[i+1]      # at last bring the pivot to its correct position
    return i+1

def quicksort(array,initial,final):
    if initial<final:
        pi=partition(array,initial,final)   #pi represents the position of the pivot
        quicksort(array,initial,pi-1)    #recursively call for first half
        quicksort(array,pi+1,final)    #recursively call for 2nd half
    return array
        
quicksort(x,lowest,highest)
for q in x:
    print(q,end=" ")
