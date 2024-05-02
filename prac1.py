
class HashTableLinearProbing:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self.hash(key)
        while self.table[index] is not None:     #collision handling
            if self.table[index][0] == key:
                self.table[index] = (key, value)
                return
            index = (index + 1) % self.size
        self.table[index] = (key, value)      #add value without collision

    def find(self, key):
        index = self.hash(key)
        comparisons = 0
        while self.table[index] is not None:
            comparisons += 1
            if self.table[index][0] == key:
                return self.table[index][1], comparisons
            index = (index + 1) % self.size
        return None, comparisons

class HashTableChaining:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def hash(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self.hash(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                self.table[index][i] = (key, value)
                return
        self.table[index].append((key, value))

    def find(self, key):
        index = self.hash(key)
        comparisons = 0
        for k, v in self.table[index]:
            comparisons += 1
            if k == key:
                return v, comparisons
        return None, comparisons

# Allow the user to define the hash table size
size = int(input("Enter the size of the hash table: "))
ht_lp = HashTableLinearProbing(size)
ht_chain = HashTableChaining(size)

while True:
    print("\nMenu:")
    print("1. Add clients in bulk")
    print("2. Search client")
    print("3. Exit")
    choice = input("Enter your choice (1/2/3): ")

    if choice == '1':
        n = int(input("Enter the number of clients to add: "))
        for _ in range(n):
            key = int(input("Enter client ID (key): "))
            value = input("Enter telephone number (value): ")
            ht_lp.insert(key, value)
            ht_chain.insert(key, value)
        print("Clients added successfully.")
    elif choice == '2':
        key = int(input("Enter client ID to search: "))
        number_lp, comparisons_lp = ht_lp.find(key)
        number_chain, comparisons_chain = ht_chain.find(key)
        print(f"\nLinear Probing: Telephone Number = {number_lp}, Comparisons = {comparisons_lp}")
        print(f"Chaining: Telephone Number = {number_chain}, Comparisons = {comparisons_chain}")
    elif choice == '3':
        print("Exiting program.")
        break
    else:
        print("Invalid choice. Please enter 1, 2, or 3.")
