struct node{
    int info;
    node* next;
};
class LinkedList{
private:
    int length;
    node* head;
    node* tail;
public:
    LinkedList( )
    {
        length = 0 ;
        head = NULL;
        tail = NULL;
    }
    void add_Front( int item )
    {
        node* temp = new node;
        temp->info = item;
        if( head == NULL )
        {
            head = temp;
            tail = temp;
            temp->next = NULL;
            length++;
            return ;
        }
        temp->next = head;
        head = temp;
        length++;
    }
    void add_Back( int item )
    {
        node* temp = new node;
        temp->info = item;
        if( head == NULL )
        {
            head = temp;
            tail = temp;
            temp->next = NULL;
            length++;
            return ;
        }
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
        length++;
    }
    void Delete( int item )
    {
        if( head->info == item )
        {
            head = head->next;
            length -- ;
            return ;
        }
        node* cur = head;
        node* prev= head ;
        while(cur != NULL && cur->info != item )
        {
            prev = cur;
            cur = cur->next;
        }
        if( cur != NULL )
        {
            prev->next = cur->next;
            length--;
        }
        else
            cout<<item<<"Not Found "<<endl;
    }
    void add_Sorted( int item )
    {
        node* temp = new node;
        temp->info = item;
        if( head == NULL )
        {
            head = temp;
            tail = temp;
            temp->next = NULL;
            length++;
            return ;
        }
        if( item <= head->info )
        {
            temp->next = head;
            head = temp;
            length++;
            return ;
        }
        if( item >= tail->info )
        {
            tail->next = temp;
            temp->next = NULL;
            tail = temp;
            length++;
            return ;
        }
        node* cur = head;
        node* prev= head;
        while( cur != NULL && cur->info < item )
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = temp;
        temp->next = cur;
        length++;
    }
    void print( )
    {
        node* cur = head;
        while( cur != NULL )
        {
            cout<<cur->info<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
    node* get_start( )
    {
        return head;
    }
    void print_Backword( node* cur )
    {
        if( cur == NULL )   return ;
        print_Backword( cur->next );
        cout<<cur->info<<" ";
    }
};
