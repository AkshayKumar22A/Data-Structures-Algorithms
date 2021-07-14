#include <iostream>

using namespace std;

struct Node
{
    int data;
        struct Node *next;
};
struct Node *start;

struct Node *createLL(struct Node *start)
{
    struct Node *NewNode,*ptr;
    int num;
    cout << "Enter the Element to be inserted in Linked List :" << endl;
    cout << "Enter -1 to exit." << endl;
    cin >> num;
    while (num != -1)
    {
        NewNode->data = num;
        if(start = NULL)
        {
            NewNode = new Node;
            NewNode->next = NULL;
        }
        else
        {
            ptr = start;
            while(ptr != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = NewNode;
            NewNode->next = NULL; 
        }
        cout << "Enter the data :" << endl;
        cin >> num;
    }
    return start;

};

int countNode(struct Node *start)
{
    struct Node *ptr;
    ptr = start;
    int count;
    count = 1;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;

};

int main()
{
    int len;
    start = createLL(start);
    len = countNode(start);
    if(len % 2 == 0)
    {
        cout << "Linked List length is Even." << endl;
    }
    else
    {
        cout << "Linked List length is Odd." << endl;
    }
    return 0;
}

