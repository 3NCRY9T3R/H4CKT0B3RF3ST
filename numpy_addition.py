# Python program explaining 
# numpy.add() function 
# when inputs are array 

import numpy as np

in_arr1 = np.array([[2, -7, 5], [-6, 2, 0]]) 
in_arr2 = np.array([[5, 8, -5], [3, 6, 9]]) 

print ("1st Input array : ", in_arr1) 
print ("2nd Input array : ", in_arr2) 
	
out_arr = np.add(in_arr1, in_arr2) 
print ("output added array : ", out_arr) 
