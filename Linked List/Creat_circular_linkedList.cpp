/*
There are two of creating a single linked list.
First method is by using Self Referential Structure
Second method is by using Class as C++ has OOPs
*/

/*
#include <iostream>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp)
    {
        printf("%d —> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
 
int main(void)
{
    struct Node e = { 5, NULL };    // last node
    struct Node d = { 4, &e };
    struct Node c = { 3, &d };
    struct Node b = { 2, &c };
    struct Node a = { 1, &b };      // first node
 
    struct Node* head = &a;
 
    printList(head);
 
    return 0;
}
*/

#include <iostream>

using namespace std;

class Node 
{
    public:
        int data;
    Node *next;    
};

void display(Node *head)
{
    Node *current;
    current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    }
    while(current -> next != head);
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    cout << "Enter first Number :" << endl;
    cin >> head->data;
    head->next = second;

    cout << "Enter Second Number :" << endl;
    cin >> second->data;
    second->next = third;

    cout << "Enter third Number :" << endl;
    cin >> third->data;
    third->next = head;

    display(head);
    return 0;
}