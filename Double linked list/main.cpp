#include <iostream>

using namespace std;

struct List
{
    string data;
    List* next;
    List* previous;
};

List* tail;
List* head;

bool isListEmpty()                              //Check is list empty
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push_front()                               //Add new record to list
{
    string userData;

    cout << "Enter data: ";
    cin >> userData;

    List* temp_head;
    temp_head = head;

    List *note = new List;
    note->data = userData;

    head->previous = note;
    head = note;
    head->next = temp_head;
}

void push_back()
{
    string userData;

    cout << "Enter data: ";
    cin >> userData;

    List* temp_tail;
    temp_tail = tail;

    List *note = new List;
    note->data = userData;

    tail->next = note;
    tail = note;
    tail->previous = temp_tail;
}

string front()                                  //Return string data from list
{
    if (head != nullptr)
    {
        return head->data;
    }
    else
    {
        return "Empty";
    }
}

string back()
{
    if (tail != nullptr)
    {
        return tail->data;
    }
    else
    {
        return "Empty";
    }
}

void pop_back()
{
    tail = tail->previous;

    delete tail->next;
}

void pop_front()
{
    head = head->next;

    delete head->previous;
}

void showMenu()                                 //Write menu to console
{
    cout << "\n1 - Check is list empty\n";
    cout << "2 - Add record to the head\n";
    cout << "3 - Add record to the tail\n";
    cout << "4 - Get head\n";
    cout << "5 - Get tail\n";
    cout << "6 - Delete tail\n";
    cout << "7 - Delete head\n";
    cout << "8 - exit\n";
}

int main()
{
    cout << "Double linked list\n";

    string userData;
    cout << "\nLet's create root note\nEnter string: ";
    cin >> userData;

    List *note = new List;
    note->data = userData;
    head = note;
    tail = note;

    showMenu();

    int menu = 0;

    while(true)
    {
        cout << "\nMake choice:\n";
        cin >> menu;

        switch(menu)
        {
        case 1: isListEmpty() ? cout << "List empty\n" : cout << "List is not empty\n";
            break;
        case 2: push_front();
            break;
        case 3: push_back();
            break;
        case 4: cout << front() << "\n";
            break;
        case 5: cout << back() << "\n";
            break;
        case 6: pop_back();
            break;
        case 7: pop_front();
            break;
        case 8: return 0;
            break;
        default: cout << "Wrong input\n";
            break;
        }
    }
    return 0;
}
