#isHappyNumber() will determine whether a number is happy or not    
def isHappyNumber(num):    
    rem = sum = 0;    
        
    #Calculates the sum of squares of digits    
    while(num > 0):    
        rem = num%10;    
        sum = sum + (rem*rem);    
        num = num//10;    
    return sum;    
            
#Displays all happy numbers between 1 and 100    
print("List of happy numbers between 1 and 100: ");    
for i in range(1, 101):    
    result = i;    
        
    #Happy number always ends with 1 and     
    #unhappy number ends in a cycle of repeating numbers which contains 4    
    while(result != 1 and result != 4):    
        result = isHappyNumber(result);    
        
    if(result == 1):    
        print(i),    
        print(" "),    
