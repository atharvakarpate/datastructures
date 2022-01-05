''' Stack  Implementations 
Functions: 
    push: push Node at the top of stack
    pop: pop Node from the top of stack 
    peek: print the head of stack 
    search_element: search element in the stack and print its index
    print_stack: print the stack
    print_size: print_size of stack
'''

import random 

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None #Pointer to a node


class stack:
    def __init__(self):
       self.head = None #Pointer to a node
       self.size = 0

    def push(self, new_node):
        new_node.next = self.head
        self.head = new_node
        self.size += 1
        print("Element Pushed ", self.head.data)

    def pop(self):
        if self.head != None:
            print("Popping element ", self.head.data)
            self.head = self.head.next
            self.size -= 1
        else:
            print("Stack Underflow")

    def peek(self):
        if self.head != None:
            print("Head Element ", self.head.data)
        else:
            print("Stack Underflow")

    def print_size(self):
        print("Size of the stack", self.size)

    def print_stack(self):
        if self.head != None:
            stack_iterator = self.head 
            while stack_iterator != None:
                print( stack_iterator.data, " -> ", end = '')
                stack_iterator = stack_iterator.next 
            print("None")
        else:
            print("Stack Underflow")

    def search_element(self, element):
        index = 0
        flag = 0
        if self.head != None:
            stack_iterator = self.head 
            
            while stack_iterator != None:
                if stack_iterator.data == element:
                    print("Element found at index", index)
                    flag = 1
                stack_iterator = stack_iterator.next
                index += 1
            
            if flag == 0:
                print("Element Not found in stack")

        else:
            print("Stack Underflow")
                    



if __name__ == '__main__':
    test_stack = stack()
    
    #Inserting 100 random elements in the stack
    print("Pushing 100 random numbers - O(1)")
    for i in range(0, 100):
        test_stack.push(Node(random.randint(0, 10)))

    #Peeking head of stack
    print("\nPeeking the head of stack - O(1)")
    test_stack.peek()

    #Printing Stack and its size
    print("\nPrinting all elements in the stack - O(n)")
    test_stack.print_stack()
    test_stack.print_size()

    #Popping random number of elements
    print("\nPopping random number of elements from stack - O(1)")
    for i in range(0, random.randint(1, 10)):
        test_stack.pop()
    
    #Printing Stack and its size after popping elements
    print("\nPrinting all elements in the stack after popping elements- O(n)")
    test_stack.print_stack()
    test_stack.print_size()
    
    #Searching for element - 8
    print("\nSearching for an element in the stack - O(1)")
    test_stack.search_element(8)



