/*
*   Console priority queue
*   based on double linked list
*/

#include <iostream>

using namespace std;

struct Queue
{
    int data;
    Queue* next;
    Queue* previous;
};

Queue* first;
Queue* last;

int number_of_notes = 0;

void push()
{
    int data;
    cout << "Enter integer: ";
    cin >> data;

    Queue* note = new Queue;
    note->data = data;

    if(number_of_notes == 0)
    {
        first = note;
        last = note;
        note->previous = nullptr;
        note->next = nullptr;
    }
    else
    {
        Queue* temp_last = last;

        last->next = note;
        last = note;
        last->previous = temp_last;
        last->next = nullptr;
    }

    number_of_notes++;
}

Queue* get_max()
{
    Queue* current = first;
    Queue* max = current;
    int i = number_of_notes;

    while(i != 0)
    {
        if(current->data > max->data)
        {
            max = current;
        }
        current = current->next;
        i--;
    }

    return max;
}

void front()
{
    if (number_of_notes > 0)
    {
        cout << "Note with highest priority is " << get_max()->data << "\n";
    }
    else
    {
        cout << "Queue is empty\n";
    }
}

void pop()
{
    if (number_of_notes < 1)
    {
        cout << "Queue is empty.\n";
        return;
    }

    Queue* max = get_max();

    if (max == first && max == last)
    {
        first = nullptr;
        last = nullptr;
    }
    else if (max == first)
    {
        (max->next)->previous = nullptr;
        first = max->next;
    }
    else if (max == last)
    {
        (max->previous)->next = nullptr;
        last = max->previous;
    }
    else
    {
        (max->previous)->next = max->next;
        (max->next)->previous = max->previous;
    }

    delete max;

    number_of_notes--;
}

void clear_queue()
{
    while(number_of_notes > 0)
    {
        pop();
    }
}

int main()
{
    cout << "1 - Add note\n";
    cout << "2 - Get front\n";
    cout << "3 - Dequeue front\n";
    cout << "4 - exit\n";

    int menu = 0;

    while(true)
    {
        cout << "Choose action:\n";
        cin >> menu;

        switch(menu)
        {
        case 1: push();
            break;
        case 2: front();
            break;
        case 3: pop();
            break;
        case 4: clear_queue();
            return 0;
        }
    }


    return 0;
}
