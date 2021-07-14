#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL;

struct Node *create_cll(struct Node *start)
{
    struct Node *newNode,*ptr;
    int num;
    cout << "Enter -1 to end." << endl;
    cout << "Enter the Data : " << endl;
    cin >> num;
    while(num != -1)
    {
        newNode = new Node;
        newNode -> data = num;
        if(start == NULL)
        {
            newNode -> next = newNode;
            start = newNode;
        }
        else
        {
            ptr = start;
            while(ptr -> next != start)
            {
                ptr = ptr -> next;
            }
            ptr -> next = newNode;
            newNode -> next = start;
        }
        cout << "Enter the data : " << endl;
        cin >> num;
    }
    return start;
};

struct Node *display(struct Node *start)
{
    struct Node *ptr;
    ptr = start;
    do
    {
        cout << ptr -> data << "\t" << endl;
        ptr = ptr -> next;
    }
    while(ptr->next != start);
    return start;
};

struct Node *insert_beg(struct Node *start)
{
    struct Node *newNode,*current;
    int num;
    cout << "Enter the data to be inserted at start : " << endl;
    cin >> num;
    newNode = new Node;
    newNode -> data = num;
    current = start;
    while(current -> next != start)
    {
        current = current -> next;
    }
    current -> next = newNode;
    start = newNode;
    return start;
};

struct Node *insert_end(struct Node *start)
{
    struct Node *newNode,*current;
    int num;
    cout << "Enter the data to be inserted at end : " << endl;
    cin >> num;
    newNode = new Node;
    newNode -> data = num;

    current = start;
    while(current -> next != start)
    {
        current = current -> next;
    }
    current ->next = newNode;
    newNode -> next = start;
    return start;
};
struct Node *delete_beg(struct Node *start)
{
    struct Node *current;
    current = start;
    while(current -> next != start)
    {
        current = current -> next;
    }
    current ->next = start -> next;
    free(start);
    start = current -> next;
    return start;
};

struct Node *delete_end(struct Node *start)
{
    struct Node *current,*previous;
    current = start;
    while(current -> next != start)
    {
        previous = current;
        current = current -> next;
    }
    previous -> next = current -> next;
    free(current);
    return start;
};
struct Node *delete_after(struct Node *start)
{
    struct Node *current,*previous;
    int val;
    cout << "Enter the value after which the node has to be deleted : " << endl;
    cin >> val;
    current = start;
    previous = current;
    while(previous -> data != val)
    {
        previous = current;
        current = current -> next;
    }
    previous -> next = current -> next;
    if(current == start)
    {
        start = previous -> next;
    } 
    free(current);
    return start;
};
/*

*/
struct Node *insert_after(struct Node *start)
{
    struct Node *newNode,*current,*previous;
    int val,num;
    cout << "Enter the value after which the node has to be inserted : " << endl;
    cin >> val;
    cout << "Enter the data to be inserted" << endl;
    cin >> num;
    newNode = new Node;
    newNode -> data = num;
    current = start;
    previous = current;
    while(previous -> data != val)
    {
        previous = current;
        current = previous -> next;
    }
    previous -> next = newNode;
    newNode -> next = current;
    return start;
};

struct Node *insert_before(struct Node *start)
{
    struct Node *newNode,*current,*previous;
    int val,num;
    cout << "Enter the value before which the node has to be inserted : " << endl;
    cin >> val;
    cout << "Enter the value to be inserted : " << endl;
    cin >> num;
    newNode -> data = num;
    current = start;
    previous = current;
    while(current -> data != val)
    {
        previous = current;
        current = current -> next;
    }
    previous -> next = newNode;
    newNode -> next = current;
    return start; 
};

struct Node *delete_node(struct Node *start)
{
    struct Node *current,*previous;
    int val;
    cout << "Enter the value of the node to be deleted : " << endl;
    cin >> val;
    current = start;
    previous = current;
    if(current -> data = val)
    {
        start = delete_beg(start);
        return start;
    }
    while(current -> data != val)
    {
        previous = current;
        current = current -> next;
    }
    previous -> next = current -> next;
    free(current);
    return start;
};

struct Node *delete_clist(struct Node *start)
{
    struct Node *current;
    current = start;
    while(current -> next != start)
    {
        start = delete_end(start);
    }
    free(start);
    return start;
};

int main()
{
    int option;
    do
    {
        cout << "*** MAIN MENU ***" << endl;
        cout << " 1 : Creat a circular list" << endl;
        cout << " 2 : Display the circular list" << endl;
        cout << " 3 : Add a node at the beginning" << endl;
        cout << " 4 : Add a node at the end" << endl;
        cout << " 5 : Add a node before a given Number" << endl;
        cout << " 6 : Add a node after a given Number" << endl;
        cout << " 7 : Delete a node from the beginning" << endl;
        cout << " 8 : Delete a node from the end" << endl;
        cout << " 9 : Delete a given node" << endl;
        cout << " 10 : Delete a node after a given number" << endl;
        cout << " 11 : Delete the entire list" << endl;
        cout << " 12 : EXIT" << endl;
        cin >> option ;

        switch (option)
        {
            case 1:
                start = create_cll(start);
                cout << "Linked list Created" << endl;
                break;
            case 2:
                start = display(start);
                break; 
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start); 
                break;
            case 9:
                start = delete_node(start);
                break;
            case 10:
                start = delete_after(start);
                break;
            case 11:
                start = delete_clist(start);
                cout << "Linked List Deleted" << endl;
                break;  
        }
    }
    while(option != 12);

    return 0;
}