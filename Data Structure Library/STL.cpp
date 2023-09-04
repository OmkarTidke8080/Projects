#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////

// Structure fro Singly Linear and Singly Circular Linked List

/////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS  // singly linear linked list
{
    T data;
    struct NodeS *next;
};

/////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and doubly circular

/////////////////////////////////////////////////////////////////////////
template <class T>
struct NodeD  // Doubly linear linked list
{
    T data;
    struct NodeD *next;
    struct ModeD *prev;
};

/////////////////////////////////////////////////////////////////////////

// class of sinlgy linear linked list

/////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLL
{
  public : 
         struct NodeS <T> *first;
         int iCount;

            SinglyLL();
         void Display();
         int Count();

         void InsertFirst(T);
         void InsertLast(T);
         void InsertAtPos(T,int);

         void DeleteFirst();
         void DeleteLast();
         void DeleteAtPos(int);
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
        if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{   
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        
        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////

// Class of Singly Circular linked list

/////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
  public : 
         struct NodeS <T> *first;
         struct NodeS <T>  *last;
         int iCount;

            SinglyCL();
         void Display();
         int Count();

         void InsertFirst(T);
         void InsertLast(T);
         void InsertAtPos(T,int);

         void DeleteFirst();
         void DeleteLast();
         void DeleteAtPos(int);
};

template <class T>
SinglyCL <T>::SinglyCL()
{
   last = NULL;

}

template <class T>
void SinglyCL<T>::Display()
{
   if(first != NULL && last != NULL)
   {
      do
      {
         cout<<first->data;
         first = first -> next;
      }while(first != last -> next);

      cout<<"\n";
   }
   else
   {
      cout<<"Linked List is Empty"<<"\n";
   }
}

template <class T>
int SinglyCL<T>::Count()
{
    return 0;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
      NodeS<T> * newn = new NodeS<T>;

      newn -> data = no;
      newn -> next = NULL;

      if((first == NULL) && (last == NULL))
      {
         first = newn;
         last = newn;
      }
      else
      {
         newn -> next = first;
         first = newn;
      }
      last -> next = first;

}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
   NodeS<T> * newn = new NodeS<T>;

   newn -> data = no;
   newn -> next =NULL;

   if(( first == NULL) && (last == NULL))
   {
      first = newn;
      last = newn;

      last -> next = first;
   }
   else
   {
      last -> next = newn;
      last = last -> next;
   }
   last -> next = first;
}



template <class T>
void SinglyCL<T>::DeleteFirst()
{
   if((first == NULL) && (last == NULL))
   {
      return;
   }
   else if( first == last)
   {
      delete first;
      first = NULL;
      last = NULL;
   }
   else
   {
      first = first -> next;
      delete first -> next;
      last -> next = first;
   }
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
       NodeS<T> *temp = first;

   if( (first == NULL) && (last == NULL))
   {
      return;
   }
   else if(first = last)
   {
      delete first;
      first = NULL;
      last = NULL;
   }
   else
   {
      while(temp -> next != NULL)
      {
         temp = temp -> next;
      }
      delete last;
      last = temp;
      last -> next = first;
   }
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
  int iCount = Count();
    NodeS<T> *temp = first;
    NodeS<T> *newn = NULL;


  temp = first;
  newn = NULL;

  if((iPos < 1) || (iPos > iCount + 1))
  {
    cout<<"Invalid Position"<<"\n";
  }
   if(iPos == 1)
  {
    InsertFirst(no);
  }
  else if(iPos == iCount + 1)
  {
   InsertLast(no);
  }
  else
  {
    for( int iCnt = 1; iCnt < iPos - 1; iCnt++)
    {
      temp = temp -> next;
    }

    NodeS<T> * newn = new NodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    newn -> next = temp -> next;
    temp -> next = newn;
  }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
   int iCount = 0;
   NodeS<T> *temp = new NodeS<T>;
   NodeS<T> *tempX = new NodeS<T>;

   temp = first;
   tempX = NULL;

   if((iPos < 1 ) || (iPos > iCount))
   {
      cout<<"Invalid Position"<<"\n";
   }
   if(iPos == 1)
   {
      DeleteFirst();
   }
   else if(iPos == iCount)
   {
      DeleteLast();
   }
   else
   {
      for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
      {
         temp = temp -> next;
      }
      tempX = temp -> next;

      temp -> next = temp -> next -> next;
      delete tempX;
   }
}


/////////////////////////////////////////////////////////////////////////

// Class of Doubly Linear linked list

/////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyLL <T>::DoublyLL()
{
   first = NULL;
   iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
   NodeS<T> temp = new NodeS<T>;

   temp = first;

   cout<<"Elements of linked list are \n";

   cout<<"NULL\n";
   while(temp != NULL)
   {
      cout<<"  | <=>  "<<temp -> data;
      temp = temp -> next;
   }
   cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
   NodeS<T> newn = new NodeS<T>;

   newn = new NodeS<T>;

   newn -> data = no;
   newn -> next = NULL;
   newn -> prev = NULL;

   if(first == NULL)
   {
      first = newn;
   }
   else
   {
      first -> prev = newn;
      newn -> next = first;
      first = newn;
   }
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
   NodeS<T> newn = new NodeS<T>;

   newn = new NodeS<T>;

   NodeS<T> temp = new NodeS<T>;

   temp = first;

   newn -> data = no;
   newn -> next = NULL;

   if(first == NULL)
   {
      first = newn;
   }
   else
   {
      while(temp -> next != NULL)
      {
         temp = temp ->next;
      }
      temp -> next = newn;
   }
}



template <class T>
void DoublyLL<T>::DeleteFirst()
{
   if(first == NULL)
   {
      return ;
   }
   else if( (first) -> next == NULL)
   {
      free (first);
      first = NULL;
   }
   else
   {
      first = first -> next;
      free((first) -> prev);
      first -> prev = NULL;
   }
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
  NodeS<T> temp = new NodeS<T>;

  if(first == NULL)
  {
    return;
  }
  else if( (first) -> next == NULL)
  {
   free(first);
   first = NULL;
  }
  else
  {
   while(temp -> next -> next != NULL)
   {
      temp = temp -> next;
   }
   free(temp -> next);
   temp -> next = NULL;
  }
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
   int iCount = Count();
   NodeS<T> newn = new NodeS<T>;

   NodeS<T> temp = new NodeS<T>;

   temp = first;

   if( (iPos < 1) || (iPos > iCount + 1))
   {
      cout<<"Invalid Position"<<"\n";
      return;
   }
   if(iPos == 1)
   {
      InsertFirst(first, no);
   }
   else if(iPos == iCount + 1)
   {
      InsertLast(first,no);
   }
   else
   {
      for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
      {
         temp = temp -> next;
      }

      newn -> data = no;
      newn -> next = NULL;
      newn -> prev = NULL;

      newn -> next = temp -> next;
      temp -> next -> prev;
      temp -> next = newn;
      newn -> prev = temp;
   }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
   int iCount = 0;
   int iCnt = 1;

   NodeS<T> temp = new NodeS<T>;

   if( (iPos < 1) || (iPos > iCount))
   {
      cout<<"Invalid Position\n";
   }

   if(iPos == 1)
   {
      DeleteFirst();
   }
   else if(iPos == iCount)
   {
      DeleteLast();
   }
   else
   {
      for(iCnt = 1; iCnt < iPos - 1; iCnt++)
      {
         temp = temp -> next;
      }

      temp -> next = temp -> next -> next;
      free(temp->next->prev);
      temp->next->prev = temp;
   }
}


/////////////////////////////////////////////////////////////////////////

// Class of Doubly Circular linkd list

/////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

template <class T>
DoublyCL <T>::DoublyCL()
{
   first = NULL;
   iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
   if( (first != NULL) && (last != NULL))
   {
      do
      {
         cout<<"  "<<first->data;
      } while (first != last -> next);

      cout<<"\n";
   }
   else
   {
      cout<<"Linked list is empty "<<"\n";
   }
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
   NodeS<T> newn = new NodeS<T>;

   newn -> data = no;
   newn -> next = NULL;
   newn -> prev = NULL;

   if( (first == NULL) && (last == NULL))
   {
      first = newn;
      last = newn;
   }
   else
   {
      newn -> next = first;
      first -> prev = newn;

      first = newn;
   }
   last -> next = first;
   first -> prev = newn;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
   NodeS<T> newn = new  NodeS<T>;

   newn -> data = no;
   newn > next = NULL;
   newn -> prev = NULL;

   if( ( first == NULL) && (first == NULL))
   {
      first = newn;
      last = newn;
   }
   else
   {
      last -> next = newn;
      newn -> prev = last;
      last = newn;
   }
   last -> next = first;
   first -> prev = last;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
   int iCount = Count();
   int iCnt = 0;

   NodeS<T> temp = new NodeS<T>;
   NodeS<T> newn = new NodeS<T>;

   if( (iPos < 1) && (iPos + 1))
   {
      cout<<"Invalid Position"<<"\n";
   }
   if(iPos == 1)
   {
      InsertFirst(first,no);
   }
   else if(iPos = iCount + 1)
   {
      InsertLast(last,no);
   }
   else
   {
      for(iCnt = 1; iCnt < iPos - 1; iCnt++)
      {
         temp = temp -> next;
      }

      newn -> data = no;
      newn -> next = NULL;
      newn -> prev = NULL;

      newn -> next = temp -> next;
      temp -> next -> prev = newn;

      temp -> next = newn;
      newn -> prev = temp;
   }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
   if( (first == NULL) && (last == NULL))
   {
      return;
   }
   else if(first == last)
   {
      free(first);

      first = NULL;
      last = NULL;
   }
   else
   {
      first = first -> next;
      free( (last) -> next);

      last -> next = first;
      first -> prev = last;
   }
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
   if( (first == NULL) && (last = NULL))
   {
      return;
   }
   else if(first == last)
   {
      free(first);

      first = NULL;
      last = NULL;
   }
   else
   {
      last = last -> prev;

      free( (last) -> next);

      first -> prev = last;
      last -> next = first;
   }
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
   int iCount = Count();

   NodeS<T> temp = new NodeS<T>;

   temp = first;
   int iCnt = 0;

   if( (iPos < 1) || (iPos > iCount))
   {
      cout<<"Invalid Position"<<"\n";
      return;
   }

   if(iPos == 1)
   {
      DeleteFirst();
   }
   else if(iPos == iCount)
   {
      DeleteLast();
   }
   else
   {
      for(iCnt = 1; iCnt < iPos - 1; iCnt++)
      {
         temp = temp -> next;
      }

      temp -> next = temp -> next -> next;
      free(temp->next->prev);
      temp->next->prev = temp;
   }
}

int main()
{
     SinglyLL <int>obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.InsertAtPos(55,4);
    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    obj1.DeleteAtPos(4);
    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    SinglyLL <char>obj2;

    obj2.InsertFirst('C');
    obj2.InsertFirst('B');
    obj2.InsertFirst('A');

    obj2.InsertLast('D');
    obj2.InsertLast('E');

    obj2.Display();
    cout<<"Number of elements are : "<<obj2.Count()<<"\n";


    SinglyLL <double>obj3;

    obj3.InsertFirst(90.90);
    obj3.InsertFirst(80.80);
    obj3.InsertFirst(70.70);

    obj3.InsertLast(60.60);
    obj3.InsertLast(50.50);

    obj3.Display();
    cout<<"Number of elements are : "<<obj3.Count()<<"\n";





    return 0;
}
