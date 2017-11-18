#include <iostream>

using namespace std;

struct Stack
{
    string data;
    Stack* lower;
};

Stack* upper;
int number = 0;

void push()
{
    string data;
    cout << "Enter data: ";
    cin >> data;

    Stack* note = new Stack;
    note->data = data;
    note->lower = upper;
    upper = note;
    number++;
}

void top()
{
    if (number < 1)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << upper->data;
}

void pop()
{
    if (number < 1)
    {
        cout << "Stack is empty\n";
    }

    Stack* temp_top = upper;
    upper = upper->lower;

    delete temp_top;
    number--;
}

void clear_stack()
{
    while(number > 0)
    {
        pop();
    }
}

int main()
{
    string data;
    cout << "Add first record: ";
    cin >> data;

    Stack *note = new Stack;
    note->data = data;
    note->lower = nullptr;
    upper = note;
    number++;

    cout << "\n1 - Add upper note\n";
    cout << "2 - Show upper note\n";
    cout << "3 - Remove upper note\n";
    cout << "4 - exit\n";

    int menu = 0;
    while(true)
    {
        cout << "\nChoose operation > ";
        cin >> menu;

        switch(menu)
        {
        case 1: push();
            break;
        case 2: top();
            break;
        case 3: pop();
            break;
        case 4: clear_stack();
            return 0;
        default: cout << "Wrong input\n";
            break;
        }
    }

    return 0;
}
