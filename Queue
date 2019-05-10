template<class MyType>
struct node{
MyType info;
node *next;
};

template<class MyType>
class Queue{
private:
    int length;     //number of elements
    node<MyType>* head;
    node<MyType>* tail;
public:
    Queue( )
    {
        length = 0 ;
        head= NULL;
        tail= NULL;
    }
    void push( MyType item )
    {
        node<MyType> *temp = new node<MyType>;
        temp->info = item;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp ;
        }
        length++;
    }
    void print(  )
    {
        node<MyType> *temp = head ;
        while(temp != NULL )
        {
            cout<<temp->info<<" ";
            temp = temp->next;
        }
        cout<<endl;
        delete temp;
    }
    void pop( )
    {
        if( length != 0 )
        {
            head = head->next;
            length--;
        }
    }
};
