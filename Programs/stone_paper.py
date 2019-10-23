# coding: utf-8

#Game of Stone, Paper and Scissors using Python

#starts

#import random for generating computer choice.
import random 

#list containing options
options = ['Stone','Paper','Scissors','ERROR']

#USER INPUT
def user_input():
    print('''0. Stone 
1. Paper
2. Scissors ''');
    x = int(input('Enter your choice: '))
    if x == 0:
        user = options[0]
    elif x ==1:
        user = options[1]
    elif x == 2:
        user = options[2]
    else:
        user = options[3]
    return user

#COMPUTER - PC INPUT
def pc_input():
    y = random.randint(0,2)
    if y == 0:
        pc = options[0]
    elif y ==1:
        pc = options[1]
    elif y == 2:
        pc = options[2]
    return pc

#PLAY GAME FUNCTION
def play(u,p):
    flag=True
    while(flag != False):
        a = user_input()
        b = pc_input()
        if (a == b):
            print("User: ",a,"PC: ",b)
            print("MATCH TIE\n")
        elif (a=="Paper"):
            if(b=="Stone"):
                print("User: ",a,"PC: ",b)
                print("YOU WON!\n")
                u=u+1
            elif(b=="Scissors"):
                print("User: ",a,"PC: ",b)
                print("YOU LOSE!\n")
                p=p+1
        elif (a=="Stone"):
            if(b=="Paper"):
                print("User: ",a,"PC: ",b)
                print("YOU LOSE!\n")
                p=p+1
            elif(b=="Scissors"):
                print("User: ",a,"PC: ",b)
                print("YOU WON!\n")
                u=u+1
        elif (a=="Scissors"):
            if(b=="Paper"):
                print("User: ",a,"PC: ",b)
                print("YOU WON!\n")
                u=u+1
            elif(b=="Stone"):
                print("User: ",a,"PC: ",b)
                print("YOU LOSE!\n")
                p=p+1
        res=input("Want to play again ? (y/n): ")
        if res == "y":
            flag = True
        else:
            flag = False
    return u,p

#call play with arguments (0,0)
#intinally score of both the players is ZERO
score=play(0,0)
print("Result: ")
print("User - PC:",score[0],"-",score[1])

#ends
