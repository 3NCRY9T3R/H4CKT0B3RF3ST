#Initialize array     
arr = [1, 2, 3, 4, 5];     
#n determine the number of times an array should be rotated    
n = 3;    
     
#Displays original array    
print("Original array: ");    
for i in range(0, len(arr)):    
    print(arr[i]),     
     
#Rotate the given array by n times toward right    
for i in range(0, n):    
    #Stores the last element of array    
    last = arr[len(arr)-1];    
        
    for j in range(len(arr)-1, -1, -1):    
        #Shift element of array by one    
        arr[j] = arr[j-1];    
            
    #Last element of the array will be added to the start of the array.    
    
    arr[0] = last;    
     
print();    
     
#Displays resulting array after rotation    
print("Array after right rotation: ");    
for i in range(0, len(arr)):    
    print(arr[i]),  
