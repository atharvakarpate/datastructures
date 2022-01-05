'''
Single Linkedlist Implementation 
Functions: 
    insert_list_at_end: insert at the head.
    display_list: displays the linkedlist.
    search_list: Search an element. 
    remove_element: remove an element at a position.
'''
import random 

class Node: 
     def __init__(self, data):
         self.data = data
         self.next = None 


class SingleLinkedList: 
    def __init__(self):
        self.head = None #head is pointer to the head node.

    def insert_list_at_end(self, new_node):
        if self.head:
            last_node = self.head #last_node stores the value of head and next nodes.
            while last_node.next != None:
                last_node = last_node.next 

            last_node.next = new_node
        else:
            self.head = new_node

    def insert_list_at_head(self, new_node):
        new_node.next = self.head
        self.head = new_node

    def display_list(self):
        disp_node = self.head
        while disp_node != None: 
            print(disp_node.data, " -> ", end = '')
            disp_node = disp_node.next
        print('Null')

    def search_list(self, element):
        flag = 0
        position = 0
        search_node = self.head
        while search_node != None:
            if search_node.data == element:
                flag = 1
                print("Element found at position", position)
                search_node = search_node.next
                position += 1
            else:
                search_node = search_node.next
                position += 1

        if flag == 0:
            print("Element not found")

    def remove_element(self, element):
        #To make sure if linkedlist has atleast 1 element
        if self.head == None: 
            print("Linkedlist is empty")
        else:
            pointer_1 = self.head 
            pointer_2 = self.head.next
            while pointer_2 != None: 
                #If element is present at the head of the array
                if self.head.data == element: 
                    self.head = self.head.next
                    print("Element Removed - ", element)
                    pointer_1 = self.head 
                    pointer_2 = self.head.next
                else: 
                    if pointer_2.data == element:
                        pointer_1.next = pointer_2.next
                        print("Element Removed - ", element)
                        if pointer_1.next == None:
                            print("End of list reached")
                            break
                    pointer_1 = pointer_1.next
                    pointer_2 = pointer_1.next
            
            #For case where linkedlist is only - element -> Null
            if self.head.data == element:
                self.head = None
                print("Element Removed - ", element)

            
            

                

if __name__ == '__main__':
    s_linkedlist = SingleLinkedList() 
   
    print("Inserting 100 random elements at the head - O(1)")
    #inserting 100 random elements in the linkedlist
    for i in range(0, 100):
        s_linkedlist.insert_list_at_head(Node(random.randint(0,10)))
   
    #displaying linkedlist
    s_linkedlist.display_list();
   
    print("\nInserting element - 10 at the end of the list - O(n)")
    #Inserting at the end of linkedlist
    s_linkedlist.insert_list_at_end(Node(10))
    
    #displaying linkedlist
    s_linkedlist.display_list();

    print("\nSearching for element - 8 in the list - O(n)")
    #searching for element - 8 in linkedlist
    s_linkedlist.search_list(8);

    print("\nRemoving element - 8 from the list - O(n)")
    #removing element - 8 from linkedlist
    s_linkedlist.remove_element(8);

    s_linkedlist.display_list();
    




