##  variables stack(dict data and meta properties)
import json
import os
# import hashlib 


class Stack:
    def _data_validate(self):
        self._stack['size']=len(self._stack['data'])

    def __init__(self,elements=[], filename="nil" ):
        self._stack={}
        self._stack['size']=[]
        self._stack['data']=elements
        self._stack['size']=len(elements)
        if filename=="nil":
            self._file_handle=False
        else: 
            self._file_handle= True
            self._stackfile=filename

            if  os.path.exists(self._stackfile):
                file=open(self._stackfile)
                self._stack = json.loads(file.read())
            else :
                file=open(self._stackfile,'a+')
                file.write(json.dumps(self._stack))
            file.close()
            self._data_validate()
    
    def pop(self):
        if not self._stack['size']:
            raise Exception("stack Exausted")
        temp=self._stack['data'][self._stack['size']-1]
        del self._stack['data'][self._stack['size']-1]
        self._stack['size']=len(self._stack['data'])
        
        return temp

    def empty_stack(self):
        self._stack["data"]=[]
        self._data_validate()

    def push(self,newElement=""):
        self._stack['data'].append(newElement)
        self._stack['size']=len(self._stack['data'])
        return 0

    def is_empty(self):
        if self._stack['size']:
            return 0
        else:
            return 1 
    
    def size(self):
            temp=self._stack['size']
            return temp
    
    def top(self):
        if not self._stack['size']:
            raise Exception("stack empty")
        return self._stack['data'][self._stack['size']-1]

    def stack(self):
        temp=self._stack['data']
        return temp 

    def raw_stack(self):
        temp=self._stack
        return temp


    def fileupdate(self, filename=False):
        self._data_validate()
        if not filename :
            file = open(self._stackfile,"w")
        elif os.path.exists(filename):
            file = open(filename, "a+")
        else:
            file = open(filename, "w")
        file.write(json.dumps(self._stack)+"\n")
        file.close()
        return 0
    def sync_file(self):
        file=open(self._stackfile)
        self._stack=json.loads(file.read())
        file.close()

def main1():
    s=Stack([1,2,3,4,5])
    # print(s.pop())
    # print(s.pop())
    # s.push("3")
    s.fileupdate("file.json")    

def main():
    s=Stack(filename="file.json")
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
    # for i in range(1000000000000 ):
    #     hsh = hashlib.md5(str(i).encode()).hexdigest()
    #     s.push([i,hsh])
    #     print(i,hsh)
    #     s.fileupdate()
    for i in range(15):
        s.push(i)
        # hashlib.md5
    # hashlib.sha384(i.encode())
    # print(s.raw_stack())
    s.fileupdate()
    # s.push("1")
    # s.push("2")
    # s.fileupdate("file.j")

if __name__=='__main__':
    main()