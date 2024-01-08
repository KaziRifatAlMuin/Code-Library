#include<bits/stdc++.h>
using namespace std;

void test() 
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
}

class node{
public:
    int data;
    node * nxt; //data type of pointer is node (a new type variable)
    node * prv; //because it stores address of another node
};

class DoublyLinkedList{ //It keeps nodes, maintains structure
public:
    node *head; //Remembers the first node
    int sz; //size of linked list
    DoublyLinkedList() //constructor, a function
    {
        head = NULL; //initially head is pointing NULL
        sz = 0; //initially size is Zero
    }

    //Creates a new node with the given data and returns it
    node * CreateNewNode(int data)
    {
        node *newnode = new node;
        newnode ->data = data;
        newnode ->nxt = NULL;
        newnode ->prv = NULL;
        sz++;
        return newnode; // NULL<-data->NULL
    }

    //Inserting new node at Head
    void InsertAtHead(int data)
    {
        node * newnode = CreateNewNode(data); // NULL<-data->NULL
        if(head==NULL)
        {
            head = newnode; //Head will be the new created node
            return;
        }
        node * a = head; //head : NULL<-data->Y = a
        newnode->nxt = a; //newnode: NULL<-data->NULL  > NULL<-data->a
        a->prv = newnode; //a: NULL<-data->Y > newnode<-data->Y
        head = newnode; //newnode: NULL<-data->a(Previous head) = head
        // Previous : head(a) <-> Y
        // Now : head(newnode) <-> a <-> Y
    }

    void Traverse()
    {
        node * a = head;
        while(a!=NULL)
        {
            cout<<a->data<<" ";
            a = a-> nxt;
        }
        cout<<"\n";
    }

    int getSize()
    {
        return sz;
    }
};

int main()
{
    test();
    DoublyLinkedList dl;
    dl.InsertAtHead(10);
    dl.InsertAtHead(20);
    dl.InsertAtHead(30);
    dl.InsertAtHead(40);
    dl.Traverse();
    cout<<"Size : "<<dl.getSize()<<endl;
    dl.InsertAtHead(50);
    dl.InsertAtHead(60);
    dl.InsertAtHead(70);
    dl.Traverse();
    cout<<"Size : "<<dl.getSize()<<endl;
    dl.InsertAtHead(80);
    dl.InsertAtHead(90);
    dl.InsertAtHead(100);
    dl.Traverse();
    cout<<"Size : "<<dl.getSize()<<endl;
    

    return 0;
}

