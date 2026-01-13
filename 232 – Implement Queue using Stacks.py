class MyQueue(object):

    def __init__(self):
        self.s1 = []
        self.s2 = []

    def push(self, x):
        while self.s1:
            self.s2.append(self.s1.pop())
        self.s1.append(x)
        while self.s2:
            self.s1.append(self.s2.pop())

    def pop(self):
        return self.s1.pop()

    def peek(self):
        return self.s1[-1]

    def empty(self):
        return not self.s1


# ------------------ USER INPUT DRIVER CODE ------------------

if __name__ == "__main__":
    q = MyQueue()

    print("Operations:")
    print("1 x -> Push x")
    print("2   -> Pop")
    print("3   -> Peek")
    print("4   -> Empty")
    print("0   -> Exit")

    while True:
        choice = int(input("\nEnter choice: "))

        if choice == 1:
            x = int(input("Enter value: "))
            q.push(x)
            print("Pushed:", x)

        elif choice == 2:
            if q.empty():
                print("Queue is empty")
            else:
                print("Popped:", q.pop())

        elif choice == 3:
            if q.empty():
                print("Queue is empty")
            else:
                print("Front element:", q.peek())

        elif choice == 4:
            print("Is Empty:", q.empty())

        elif choice == 0:
            print("Exiting...")
            break

        else:
            print("Invalid choice")

# Time Complexity

# Operation  	Complexity
# push()	      O(n)
# pop()	          O(1)
# peek()	      O(1)
# empty()	      O(1)

# Space Complexity
# O(n) → Two stacks storing n elements

# Company	          Asked In

# Amazon	        2018–2024
# Google	        2019–2023
# Microsoft  	    2018–2024
# Facebook (Meta)	2019–2022
# Apple	            2020–2023
# Adobe     	    2021–2024
# Flipkart	        2020–2023
# Paytm	            2021–2024
# Infosys / TCS / Wipro	2019–2024