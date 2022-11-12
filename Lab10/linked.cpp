#include<iostream>
using namespace std ;

class Node
{
    public:
    int data ;
    Node* next ;

};

class List 
{
    public :
    Node* head  = NULL;

    bool isempty()
    {
        Node* temp = head ;
        if(temp == NULL)
        {
            cout<<"Empty"<<endl;
            return 1;
        }
        else 
        {
            cout<<"Not empty"<<endl;
            return 0;
        }

    }

    void Insert(int data_insert )
    {
        Node* temp = head ;
        if(isempty())
        {
            temp->data = data_insert;
            temp->next = NULL;
        }
        // else insert at the end 
        while(temp->next !=NULL)
        {
            temp = temp->next ;

        }
        temp->data = data_insert;
        temp->next = NULL;

    }

    void delete(int data_delete)
    {
    
    }


};


int main()
{



    return 0;
}