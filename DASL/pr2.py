"""To create ADT that implement the “set” concept.
a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the
value
c. Contains (element) Return true if element is in collection, d. Size () Return number of
values in collection Iterator () Return an iterator used to loop over collection, e.
Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset

Sample code"""

class MySet:
    def __init__(self):
        self.data = []

    def add(self, e):
        if e not in self.data:
            self.data.append(e)

    def remove(self, e):
        if e in self.data:
            self.data.remove(e)

    def contains(self, e):
        return e in self.data

    def size(self):
        return len(self.data)

    def iterator(self):
        return iter(self.data)
    

    def intersection(self, other):
        result = MySet()
        for e in self.data:
            if e in other.data:
                result.add(e)
        return result

    def union(self, other):
        result = MySet()
        for e in self.data + other.data:
            result.add(e)
        return result

    def difference(self, other):
        result = MySet()
        for e in self.data:
            if e not in other.data:
                result.add(e)
        return result

    def subset(self, other):
        return all(e in other.data for e in self.data)

# --- User Interactive Program ---
def main():
    A = MySet()
    B = MySet()

    while True:
        print("\nMenu:\n1.Add to Set A\n2.Add to Set B\n3.Remove from Set A\n4.Remove from Set B")
        print("5.Display Sets\n6.Intersection\n7.Union\n8.Difference (A-B)\n9.Subset (A in B?)\n10.Size of set A\n11.Size of set B\n12.Enter element to check whether set A contains that element:")
        choice = input("Enter choice: ")

        if choice == '1':
            val = input("Enter element to add to A: ")
            A.add(val)
        elif choice == '2':
            val = input("Enter element to add to B: ")
            B.add(val)
        elif choice == '3':
            val = input("Enter element to remove from A: ")
            A.remove(val)
        elif choice == '4':
            val = input("Enter element to remove from B: ")
            B.remove(val)
        elif choice == '5':
            print("Set A:", list(A.iterator()))
            print("Set B:", list(B.iterator()))
        elif choice == '6':
            print("Intersection:", list(A.intersection(B).iterator()))
        elif choice == '7':
            print("Union:", list(A.union(B).iterator()))
        elif choice == '8':
            print("Difference (A-B):", list(A.difference(B).iterator()))
        elif choice == '9':
            print("Is A subset of B?", A.subset(B))
        elif choice == '10':
            print("Size of set A is:",A.size())
        elif choice == '11':
            print("Size of set B is:",B.size())
        elif choice == '12':
            val = input("Enter element to check")
            print("Is set A contains:",A.contains(val))
        else:
            print("Invalid choice!")


main()

