from collections import deque

class MyStack:
    def __init__(self):
        self.q = deque()

    def push(self, x):
        self.q.append(x)

    def pop(self):

        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())
        return self.q.popleft()

    def top(self):
        return self.q[-1]

    def empty(self):
        return len(self.q) == 0


# ------------------ USER INPUT DRIVER CODE ------------------

if __name__ == "__main__":
    stack = MyStack()

    print("Operations:")
    print("1 x -> Push x")
    print("2   -> Pop")
    print("3   -> Top")
    print("4   -> Empty")
    print("0   -> Exit")

    while True:
        choice = int(input("\nEnter choice: "))

        if choice == 1:
            x = int(input("Enter value: "))
            stack.push(x)
            print("Pushed:", x)

        elif choice == 2:
            if stack.empty():
                print("Stack is empty")
            else:
                print("Popped:", stack.pop())

        elif choice == 3:
            if stack.empty():
                print("Stack is empty")
            else:
                print("Top element:", stack.top())

        elif choice == 4:
            print("Is Empty:", stack.empty())

        elif choice == 0:
            print("Exiting...")
            break

        else:
            print("Invalid choice")

# Time Complexity

# Operation	 Complexity
# push()	   O(1)
# pop()	       O(n)
# top()	       O(1)
# empty()	   O(1)

# Company	         Asked In	   Context
# Amazon	         2018–2024	   Stack–Queue conversion
# Google	         2019–2023	   Data structure simulation
# Microsoft	         2018–2024	   Queue & Stack fundamentals
# Facebook (Meta)	 2019–2022	   LIFO using FIFO
# Apple	             2020–2023	   Core DS logic
# Adobe	             2021–2024	Stack implementation
# Flipkart	         2020–2023	Queue rotation logic
# Paytm	             2021–2024	Data structures basics