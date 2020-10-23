def QuickSort(v):
    if len(v) <= 1:
        return v
    pivot = v[0]
    same = [x for x in v if x == pivot]
    smallers = [x for x in v if x < pivot]
    biggers = [x for x in v if x > pivot]
    return QuickSort(smallers) + same + QuickSort(biggers)

# Quick Sort implementation in python
Arr = [60, 25, 10, 32, 9] 

Sorted = QuickSort(Arr)
# Driver code 
print ("Sorted array: ") 
for i in Sorted: 
    print("%d" % i), 
