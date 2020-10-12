def shellSort(arr): 
  
    # Start with a big gap, then reduce the gap 
    n = len(arr) 
    gap = n//2
    while gap > 0: 
  
        for i in range(gap,n): 
            temp = arr[i]
            j = i 
            while  j >= gap and arr[j-gap] >temp: 
                arr[j] = arr[j-gap] 
                j -= gap 
  
            # put temp (the original a[i]) in its correct location 
            arr[j] = temp 
        gap //= 2
