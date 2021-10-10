/* Created by Prashant Agheda (https://github.com/prashant-agheda/) */

/* Create a	Singly Linked list class(members ->	value and next pointer),
   with the following methods:
   1 - createNewNode()
   2 - addNodeAtBegin()
   3 - addNodeAtEnd()
   4 - length()
   5 - print() */

#include <iostream>

using namespace std;

class NODE
{
    int info;
    NODE *next;
    public:
        NODE *create_list(NODE *);
        void display_list(NODE *);
        NODE *add_node_at_begin(NODE *, int);      // int is For Value at Location
        NODE *add_node_at_end(NODE *, int);
        int find_length(NODE *);
};

// Method 1
// Argument is a Pointer as it returns Address of 1st Node
NODE *NODE::create_list(NODE *list)
{
    int no_of_nodes;
    NODE *newnode, *temp;

    cout << "\n* Enter the Number of Nodes to be Created : ";
    cin >> no_of_nodes;

    for(int i = 0; i < no_of_nodes; i++)
    {
        // Same as int a; a = new int;
        newnode = new NODE;
        cout << "\n* Enter Data " << i << " for New Node : ";
        cin >> newnode->info;

        if(list == NULL)
        {
            newnode->next = NULL;
            list = newnode;
            temp = newnode;
        }
        else
        {
            newnode->next = NULL;
            temp->next = newnode;
            temp = newnode;
        }
    }

    return list;
}

// Method 2
void NODE::display_list(NODE *list)
{
    NODE *temp;
    temp = list;
    cout << "\n\nThe Values of Linked List are : \n";
    while(temp != NULL)
    {
        cout << " " << temp->info;
        temp = temp->next;
    }
    cout << "\n\n";
}

// Method 3
NODE *NODE::add_node_at_begin(NODE *list, int num)
{
    NODE *newnode;
    newnode = new NODE;
    newnode->info = num;
    newnode->next = list;
    list = newnode;
    return list;
}

// Method 4
NODE *NODE::add_node_at_end(NODE *list, int num)
{
    NODE *newnode, *temp;
    newnode = new NODE;
    newnode->info = num;
    newnode->next = NULL;
    temp = list;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;

    // Returning so that we get the updated value in main
    return list;
}

// Method 5
int NODE::find_length(NODE *list)
{
    NODE *temp;
    int count = 0;
    temp = list;
    cout << "\nLENGTH of the List is : ";
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << count << "\n\n";
    return count;
}

int main()
{
    NODE *list = NULL, *temp;
    NODE linklist;
    int choice, element;

    do
    {
        cout << endl << "Linked List Operations";
        cout << endl << "----------------------";
        cout << endl << "1 - Create a Linked List.";
        cout << endl << "2 - Add Node at Begin.";
        cout << endl << "3 - Add Node at End.";
        cout << endl << "4 - Show Length of List.";
        cout << endl << "5 - Display the Entire List.";
        cout << endl << "6 - Exit.";
        cout << endl << "\n* Please Enter Your Choice (1-5) : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                list = linklist.create_list(list);
                linklist.display_list(list);
                break;

            case 2:
                cout << endl << "* Enter an Element to add at BEGIN : ";
                cin >> element;
                list = linklist.add_node_at_begin(list, element);
                linklist.display_list(list);
                break;

            case 3:
                cout << endl << "* Enter an Element to add at END : ";
                cin >> element;
                list = linklist.add_node_at_end(list, element);
                linklist.display_list(list);
                break;

            case 4:
                linklist.display_list(list);
                linklist.find_length(list);
                break;

            case 5:
                linklist.display_list(list);
                break;

            case 6:
                cout << endl << "Bye Bye" << "\n\n";
                exit(1);

            default:
                cout << endl << "Invalid Choice -- Try Again";
        }
    } while (choice != 6);

    return 0;
}