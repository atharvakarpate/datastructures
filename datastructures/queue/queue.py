import random

class Queue:
        def __init__(self):
            self.items = list()

        def enqueue(self, data):
            self.items.append(data)

        def dequeue(self):
            if not self.isEmpty():
                self.items.pop(0)
            else:
                print("Queue empty")

        def isEmpty(self):
            if len(self.items) == 0:
                return True
            else:
                return False

        def peek(self):
            if self.isEmpty():
                return None
            else:
                return self.items[0]

        def Qsize(self):
            return len(self.items)

        def printQueue(self):
            for i in self.items:
                print(i, end = "->")
            print("None")

if __name__ == "__main__":
    obj =  Queue()

    print("Enqueue 20 elements")
    for i in range(0, 20):
        obj.enqueue(random.randrange(0,10))

    print("Printing Queue")
    obj.printQueue();
    print("Queue size", end = " ")
    print(obj.Qsize())

    print("Dequeue 10 elements")
    for i in range(0, 10):
        obj.dequeue()

    print("Printing Queue")
    obj.printQueue();
    print("Queue size", end = " ")
    print(obj.Qsize())

    print("Peek: ", obj.peek())

    print("Dequeue 11 elements")
    for i in range(0, 11):
        obj.dequeue()

    print("Peek: ", obj.peek())

    print("Queue Empty? ", obj.isEmpty())

