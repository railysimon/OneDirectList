#include <iostream>
#include <iomanip>

using namespace std;

struct Link
{
    int data;
    Link *next;
};

class List
{
private:
        Link *first;
public:
        List() { first = NULL; }
        void Add(int data);
        void Show();
        ~List();
};

void List::Add(int data)
{
    Link *newlink = new Link;
    newlink->data = data;
    newlink->next = first;
    first = newlink;
}

void List::Show()
{
    Link *current = first;
    while(current)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

List::~List()
{
    while(first)
    {
        Link *temp = first->next;
        delete first;
        first = temp;
    }
}


int main()
{
    List object;

    object.Add(10);
    object.Add(100);
    object.Add(1000);

    object.Show();

    return 0;
}
