struct node{
int value;
node* left;
node* rigth;
};
class Binary_Tree{
private:
    int getMin();
    void destroy_tree(node *leaf);
        void add(int key, node *leaf);
        node *serch(int key, node *leaf);
        void inorder_print(node *leaf);
        void postorder_print(node *leaf);
        void preorder_print(node *leaf);
        void Delete(node*& leaf , int key);
    node* root;
public:
    void  add(int key);
        node* serch(int key);
        void  destroy_tree();
        void  inorder_print();
        void  postorder_print();
        void  preorder_print();
        void  Delete(int key);
        int getMin(node* leaf);
        Binary_Tree( )
        {
            root = NULL;
        }
        ~Binary_Tree( )
        {
            destroy_tree();
        }
};
int Binary_Tree::getMin(node* leaf)
{
    if( leaf->left == NULL )
        return leaf->value;
    else
    return getMin(leaf->left);
}
int Binary_Tree::getMin( )
{
    if( root == NULL )
        throw "Empty tree";
    return getMin(root);
}

void Binary_Tree::destroy_tree(node* leaf )
{
    if(leaf != NULL )
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->rigth);
        delete leaf;
    }
}
void Binary_Tree::destroy_tree( )
{
    destroy_tree( root );
}

void Binary_Tree::add(int key , node* leaf )
{
    if( key < leaf->value )
    {
        if( leaf->left != NULL )
            add(key , leaf->left);
        else
        {
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->rigth = NULL;
        }
    }
    else if( key >= leaf->value )
    {
        if( leaf->rigth != NULL )
            add( key , leaf->rigth );
        else
        {
            leaf->rigth = new node;
            leaf->rigth->value = key;
            leaf->rigth->rigth = NULL;
            leaf->rigth->left = NULL ;
        }
    }
}
void Binary_Tree::add( int key )
{
    if( root != NULL ){
        add( key , root );
    }
    else
    {
        root = new node;
        root->value = key;
        root->left = NULL;
        root->rigth = NULL;
    }
}

node* Binary_Tree::serch(int key , node* leaf )
{
    if( leaf != NULL )
    {
        if(key == leaf->value )
            return leaf;
        if( key < leaf->value )
            return serch(key , leaf->left);
        else
            return serch(key , leaf->rigth);
    }
    else
        return NULL;
}
node* Binary_Tree::serch(int key)
{
     return  serch(key , root );
}

void Binary_Tree::inorder_print(node* leaf )
{
    if(leaf != NULL )
    {
        inorder_print(leaf->left);
        cout<<leaf->value<<" ";
        inorder_print(leaf->rigth);
    }
}
void Binary_Tree::inorder_print()
{
    inorder_print(root);
    cout<<endl;
}

void Binary_Tree::postorder_print(node* leaf )
{
    if( leaf != NULL )
    {
        postorder_print(leaf->left);
        postorder_print(leaf->rigth);
        cout<<leaf->value<<" ";
    }
}
void Binary_Tree::postorder_print()
{
    postorder_print(root);
    cout<<endl;
}

void Binary_Tree::preorder_print(node* leaf )
{
    cout<<leaf->value<<" ";
    preorder_print(leaf->left);
    preorder_print(leaf->rigth);
}
void Binary_Tree::preorder_print()
{
    preorder_print(root);
    cout<<endl;
}

void Binary_Tree::Delete(node*& leaf , int key)
{
    if( leaf == NULL ){

    }
    if( key > leaf->value )
        Delete( leaf->rigth , key );
    else if( key < leaf->value )
        Delete(leaf->left , key);
    else{
        node* trash = NULL;
        if( leaf->left == NULL && leaf->rigth == NULL ){
            trash = leaf;
            leaf = NULL;
        }
        else if( leaf->rigth == NULL ){
             trash = leaf;
             leaf = leaf->left;
        }
        else if( leaf->left == NULL )
        {
            trash = leaf;
            leaf = leaf->rigth;
        }
        else{
            int newData = getMin(root->rigth);
            leaf->value = newData;
            Delete(leaf->rigth , newData);
        }
        if( trash != NULL )
            delete trash;
    }
}
void Binary_Tree::Delete(int key)
{
    Delete( root , key );
}
int main( )
{
    Binary_Tree b;
    b.add(1);
    b.add(5);
    b.add(8);
    b.add(1);
    b.add(2);
    b.add(12);
    b.add(7);
    b.add(13);
    b.add(-1);
    b.inorder_print();
    b.Delete(12);
    b.inorder_print();
    return 0;
}
