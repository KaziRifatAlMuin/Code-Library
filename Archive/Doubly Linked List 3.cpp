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

    //Prints the Linked List O(n)
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

    //Inserts the given data at the given index O(n)
    void Insert (int index, int data)
    {
        if(index>=sz)
        {
            return;
        }

        if(index==0)
        {
            InsertAtHead(data);
            return;
        }
        node * a = head;
        int cur_index = 0;
        while(cur_index!=index-1)
        {
            a = a->nxt;
            cur_index++;
        }
        //cur_index = index-1
        //a = (index-1)th node
        node * newnode = CreateNewNode(data);
        newnode ->nxt = a->nxt;
        newnode ->prv = a;
        node * b = a->nxt;
        b ->prv = newnode;
        a ->nxt = newnode;
    }

    //Deletes the given index
    void Delete(int index)
    {
        if(index>=sz)
        {
            cout<<"Error Deletation! Index ["<<index<<"] doesn't exist!\n";
            return;
        }
        node * a = head;
        int cur_index = 0;
        while(cur_index!=index)
        {
            a = a->nxt;
            cur_index++; //we are going to a=(index)th node
        }
        node * b = a->prv; //b <-> a
        node * c = a->nxt; //a <-> c
        if(b!=NULL)
        {
            b->nxt = c; // b <-> a <->c to b->c
        }
        if(c!=NULL)
        {
            c->prv = b; // b <-> a <->c to b<-c
        }
        delete a;
        sz--;
        if(index==0)
        {
            head = c;
        }
    }

    //Reverse the doubly linked list O(n)
    void Reverse()
    {
        if(head==NULL)
        {
            return;
        }
        node * a = head;
        int cur_index = 0;
        while(cur_index!=sz-1)
        {
            a = a->nxt;
            cur_index++;
        }
        //Last index is in a 
        node * b = head; //new node b will iterate from head
        while(b!=NULL)
        {
            swap(b->nxt, b->prv); //swaping every node nxt and prv
            b = b->prv; //nxt of b is now in prv
        }
        head = a;
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
    
    dl.Insert(2,100);
    dl.Insert(1,500);
    dl.Traverse();
    cout<<"Size : "<<dl.getSize()<<endl;
    
    dl.Insert(4,10000);
    dl.Traverse();
    cout<<"Size : "<<dl.getSize()<<endl;
    
    dl.Delete(2);
    dl.Traverse();
    cout<<"Size : "<<dl.getSize()<<endl;
    
    dl.Delete(0);
    dl.Traverse();
    cout<<"Size : "<<dl.getSize()<<endl;
    

    dl.Delete(4);
    dl.Insert(3,10000);
    dl.Traverse();
    cout<<"Size : "<<dl.getSize()<<endl;
    
    dl.Reverse();
    dl.Traverse();

    return 0;
}

