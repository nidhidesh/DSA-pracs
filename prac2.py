class hashtable:
    def __init__(self,size=10):
        self.size= size
        self.table=[[]for _ in range(size)]
    def ghash(self,key):
        return hash(key) % self.size
    def insert(self,key,value):
        index= self.ghash(key)
        for i,(k,_)in enumerate(self.table[index]):
            if k==key:
                self.table[index][i]=(key,value)
                return
        self.table[index].append((key,value))
    def find(self,key):
        index=self.ghash(key)
        for i,(k,v)in enumerate(self.table[index]):
            if k==key:
                return v
        return None
    def delete(self,key):
        index=self.ghash(key)
        for i,(k,_)in enumerate(self.table[index]):
            if k==key:
                del self.table[index][i]
                return True
        return False
ht=hashtable()
while True : 
    print("1. Enter key,value\n2. Search\n3. Delete\n4. Exit\n")
    ch=int(input("Enter your choice : "))
    if ch==1:
        key=input("Enter the key: ")
        value=input("Enter the value: ")
        ht.insert(key,value)
        print("Inserted successfully !!\n")
    elif ch==2:
        key= input("Enter the key to be searched : ")
        value=ht.find(key)
        if value is not None:
            print("Value : ",value)
        else:
            print("Value not found !")
    elif ch==3:
        key= input("Enter the key to be deleted : ")
        if ht.delete(key):
            print("Deleted successfully !")
        else:
            print("Not deleted !")
    else :
        print("Exiting program !")
        break







