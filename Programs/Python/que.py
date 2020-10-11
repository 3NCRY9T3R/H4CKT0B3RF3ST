##  variables stack(dict data and meta properties)
import json
import os


# import time

class Que:
    def _data_validate(self):
        self._que['size']=len(self._que['data'])

    def __init__(self,elements=[], filename="nil" ):
        self._que={}
        self._que['size']=[]
        self._que['data']=elements
        self._que['size']=len(elements)
        if filename=="nil":
            self._file_handle=False
        else: 
            self._file_handle= True
            self._quefile=filename
            if os.path.exists(self._quefile):
                file=open(self._quefile)
                self._que = json.loads(file.read())    
                
            else:    
                file=open(self._quefile,'w')
                file.write(json.dumps(self._que))

            
            file.close()
            self._data_validate()
    
    def get(self):
        if not self._que['size']:
            raise Exception("QUE Exausted")
        temp=self._que['data'][0]
        del self._que['data'][0]
        self._data_validate()
        return temp

    def put(self,newElement=""):
        self._que['data'].append(newElement)
        self._data_validate()
        return 0

    def empty_que(self):
        self._que["data"]=[]
        self._data_validate()

    def is_empty(self):
        if self._que['size']:
            return 0
        else:
            return 1 
    
    def size(self):
            temp=self._que['size']
            return temp
    
    def top(self):
        if not self._que['size']:
            raise Exception("stack empty")
        temp = self._que['data'][0]
        return temp

    def que(self):
        temp=self._que['data']
        return temp 

    def raw_que(self):
        temp=self._que
        return temp


    def fileupdate(self, filename=False):
        self._data_validate()
        if not filename :
            file = open(self._quefile,"w")
        elif os.path.exists(filename):
            file = open(filename, "a+")
        else:
            file = open(filename, "w")
        file.write(json.dumps(self._que)+"\n")
        file.close()
        return 0
    def sync_file(self):
        file=open(self._quefile)
        self._que=json.loads(file.read())
        file.close()
def main():
    # s=Que([1,2,3,4,5])
    s=Que(filename="file.json")
    # print("   ",s.raw_que())
    # print(s.get()," ",s.raw_que())
    # print(s.get()," ",s.raw_que())
    # print(s.get()," ",s.raw_que())
    # print(s.get()," ",s.raw_que())
    # print(s.get()," ",s.raw_que())

    # print("Puting elements")

    for i in range(11):
        s.put(i)
        print(s.raw_que())


    # print(s.size())

        # time.sleep(0.1)
    s.fileupdate()
    # print("\n Getting elements")
    # while s.size():
    #     print(s.get()," ",s.raw_que())
        # time.sleep(0.5)

    # s.fileupdate()
    # print(s.get()," ",s.que())
    # print(s.pop())
    # print(s.pop())
    # s.push("3")
    # s.fileupdate("file.json")    

def main2():
    s=Que(filename="file.json")
    s.put(12)
    # print(s.stack)
    # print(s.pop())
    # print(s.pop())
    # print(s.pop())
    # file=open("file.json")
    # data = json.loads(file.read())
    # print(type(data))
    # print(data)
    # print(s.raw_stack())
    # print(s.stack())
    # a=s.raw_stack()
    # print(a)
    # a['size']=12
    # s.empty_stack()
    # for i in range(11):
    #     s.push(i)
    # print(s.raw_stack())
    # s.fileupdate()
    # s.push("1")
    # s.push("2")
    # s.fileupdate("file.j")
def main1():
    a=[1,2,3,5,6,6]
    print(a)
    del a[0]
    print(a)
    del a[0]
    print(a)
    del a[0]
    print(a)    
    del a[0]
    print(a)    
    del a[0]
    print(a)    
    del a[0]
    print(a)

if __name__=='__main__':
    main()