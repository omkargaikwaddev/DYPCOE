"""Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two collision
handling techniques and compare them using number of comparisons required to find a
set of telephone numbers""" 
class HashTable:
    def __init__(self, size):
        self.m = size
        self.table = [None] * self.m
        self.count = 0

    def is_full(self):
        return self.count == self.m

    def hash(self, key):
        return key % self.m

    def insert(self, key, value, method='linear'):
        if self.is_full():
            print("Table is full")
            return
        index = self.hash(key)
        if self.table[index] is None:
            self.table[index] = [key, value]
        else:
            print("Collision occurred. Applying", method.title(), "Probing...")
            self._probe(key, value, method)
        self.count += 1
        print("Current Table:", self.table)
        
    def _probe(self, key, value, method):
        i = 1
        compare = 0
        while True:
            index = (self.hash(key) + (i if method == 'linear' else i * i)) % self.m
            compare += 1
            if self.table[index] is None:
                self.table[index] = [key, value]
                break
            i += 1
        print("Data inserted at", index)
        print("Comparisons:", compare)

    def search(self, key, value, method='linear'):
        i = 0
        while i < self.m:
            index = (self.hash(key) + (i if method == 'linear' else i * i)) % self.m
            if self.table[index] is None:
                return None
            if self.table[index] == [key, value]:
                return index
            i += 1
        return None


def menu():
    size = int(input("Enter size of hash table: "))
    ht_linear = HashTable(size)
    ht_quadratic = HashTable(size)

    while True:
        print("\n1. Linear Probing\n2. Quadratic Probing\n3. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 3:
            print("Exiting.")
            break

        method = 'linear' if choice == 1 else 'quadratic'
        ht = ht_linear if method == 'linear' else ht_quadratic

        while True:
            print("\n1. Insert\n2. Search\n3. Back")
            ch2 = int(input("Enter your choice: "))
            if ch2 == 3:
                break
            elif ch2 == 1:
                key = int(input("Enter phone number: "))
                value = input("Enter name: ")
                ht.insert(key, value, method)
            elif ch2 == 2:
                key = int(input("Enter phone number to search: "))
                value = input("Enter name: ")
                idx = ht.search(key, value, method)
                print("Key found at index", idx if idx is not None else "Not Found")

menu()


