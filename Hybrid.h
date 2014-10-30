#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"

template < class T >
class Hybrid
{

   private:
      QueueLinked<DoubleNode<T>>* q;
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   q = new QueueLinked<T>();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove

bool Hybrid<T>::isEmpty()
{
	return q->isEmpty();
}

void Hybrid<T>::enqueue(T* item)
{
	DoubleNode<T>* temp = new DoubleNode();
	temp = sldl->addDN(item);
	q->enqueue(temp);
	
	
	
	//q->enqueue(item);
	//sldl->add(item);
}

T* Hybrid<T>::dequeue()
{
	DoubleNode<T>* temp = q->dequeue();
	sldl->remove((temp->getItem()->getKey());



	//T* dqed;
	//dqed=q->dequeue();
	//sldl->remove(dqed->getKey());
	return dqed;
}

ListDoublyLinkedIterator<T>* Hybrid::iterator()
{
	ListDoublyLinkedIterator<T>* iter= new sldl->iterator();
	return iter;
}






#endif
