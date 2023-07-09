#include<stdbool.h>                                 //for bool datatypes
#include<stdlib.h>                                  //to access malloc

#define SIZE_OF_INT             16                  //integer is 2 bytes
#define SIZE_OF_FlOAT           32                  //float is 4 bytes

/** This function takes a parameter head, reads the size, 
 * and takes the input of the values of the elements, and 
 * links them to create a linked list
 * 
 * @param head Taking a pointer to the first element of the list
 * @return None
*/
void createLinkedList(struct node *head) {

    //A temporary pointer that moves from one element to the next
    struct node *temp,

    //A pointer to the address of a node
    *newnode;

    //The number of nodes user will input in the list
    int numberofNodes;
    printf("%d", "Enter the number of nodes: ");
    scanf("%d", &numberofNodes);

    //The number of the node that is allocated in memory
    int i;

    //Run a loop until we create a number of nodes that equals
    //numberofNodes
    for (int i = 0; i < numberofNodes; i++) {
    
        //Allocate node in memory
        newnode = (struct node*) malloc(sizeof(struct node));

        //Value of node read from user
        int value;
        printf("Enter the value for node %d: ", i);
        scanf("%d", &value);

        /*Create a node 'newnode' with read value in 'data'. The 'next' address should be null 
        temporarily as there is no node we can link it with in the list.*/ 
        newnode->data = value;
        newnode->next = NULL;

        //Let a temporary ptr 'temp' point to the index of the value of the first node
        if (head == NULL) {
            head = newnode;
            temp = head;  
        }

        /*Change the value of the first node 'next', which was allocated
        in memory previously, to the address of the next node. Shift the temporary
        ptr to the address of that next node.*/
        else {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    LinkedlistTraversal(head, temp);
}

/** This function is to traverse the created linked list
 * 
 * @param head Taking a pointer to the first element of the list
 * @param temp A temporary pointer that moves from one element to the next
 * @return None
*/
void LinkedlistTraversal(struct node *head, struct node *temp) {
    //Temp is in the end after linked creation. Therefore,
    //we redeclare to equal to head
    temp = head;

    //Traverse through the linked list
    while (temp != NULL) {
        printf("%d ", temp->data);
        //Move to the next element
        temp = temp->next;
    }

}

/** The main function, to call all of the other functions
 * and take inputs
*/
int main() {

    //Define head to NULL
    struct node *head = NULL;
    createLinkedlist(head);
    //For arithmetic operations, prevention of certain unxepectec errors
    return 0;

}

