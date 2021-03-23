#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using std::underflow_error;


template <class T>
struct Node
{
    T data;
    Node<T>* next;
    Node(const T& = T(), Node<T>* next = nullptr);
};

template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
    data = newData;
    next = newNext;
}

template<class T>
class Queue;

template<class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template<class T>
class Queue
{
friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

private:
        size_t qSize=0;				//number of items currently stored in queue
        Node <T> *qFront=nullptr;		//pointer to front node in list
        Node <T> *qBack=nullptr;		//pointer to rear node in the list
public:
        Queue();                                                //Default constructor
        ~Queue();                                               //Deconstructor
        Queue(const Queue<T>&);                                 //copy constructor
        Queue<T>&  operator=(const Queue<T>&);                  //overloaded copy assignment operator
        void clear();
        size_t  size()const;
        bool empty()const;
        const T& front()const;
        const T& back()const;
	void push(const T&);
        void pop();
};

/*************************************************
 Default Constructor
 *************************************************/
template <class T>
Queue<T>::Queue()
{

// Purpose: is to set queue to initial empty state.

    qFront = nullptr;
    qBack = nullptr;
    qSize = 0;

}

/*************************************************
 Destructor
 *************************************************/
template <class T>
Queue<T>::~Queue()
{
    clear();
}

/*************************************************
 Copy Constructor
 *************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
	//set both front an back to nullptr before attempting to insert any nodes
	//Purpose to copy the linked list by using push() method.

	qSize = 0;
	qFront =nullptr;
	qBack= nullptr;

	for (Node<T>* i=other.qFront; i != nullptr; i=i->next)
	{
		push(i-> data);
	}
}

/*************************************************
 Overloaded Copy Assignment Operator
 *************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{

       if(this!=&other)
	{
		clear();

		qSize =0;

		qFront =nullptr;

		qBack =nullptr;

        	for (Node<T>* i=other.qFront; i!= nullptr; i=i->next)
        	{
            		push(i-> data);
        	}

	}

	return *this;
}

/*************************************************
 Output Operator
 *************************************************/
template <class T>
std::ostream& operator<<(std::ostream &lhs, const Queue<T>& other)
{
	//standard output

       for (Node<T>* i=other.qFront; i!=nullptr; i=i->next)
        {
            // Print queue element at subscript i
            lhs << i-> data << ' ';
        }

    return lhs;
}

/*************************************************
 Instantly clears the data
 *************************************************/
template <class T>
void Queue<T>::clear()
{
	//should clear all the nodes and data with a while loop

	while(!empty())
		pop();
}

/*************************************************
 Return size of the Vector
 *************************************************/
template <class T>
size_t Queue<T>::size() const
{
    return qSize;
}

/*************************************************
 Return empty of the Vector
 *************************************************/
template <class T>
bool Queue<T>::empty() const
{
	if(qSize==0)					//check to see if queue size is 0
		return true;

	return false;
}

/*************************************************
 Front Queue
 *************************************************/
template <class T>
const T& Queue<T>::front() const
{
	if(qSize==0)							//check to see if the Front is empty
		throw underflow_error("front underflow error");
	else
	return qFront->data;
}
/*************************************************
 Back Queue
 *************************************************/
template <class T>
const T& Queue<T>::back() const
{
	if(qSize==0)							//check to see if Back is empty
		throw underflow_error("back underflow error");

	return qBack->data;

}
/*************************************************
 Queue PUSH
 *************************************************/
template <class T>
void Queue<T>::push(const T& item)
{
	Node<T>* newNode=new Node<T>(item);

	if(empty())
		qFront=newNode;
	else
		qBack->next =newNode;

	qBack=newNode;
	++qSize;
}

/*************************************************
  Queue POP
 *************************************************/
template <class T>
void Queue<T>::pop()
{
	if(empty())							//check if its empty then add 1 to the Front
		throw underflow_error("pop underflow error");

	Node<T>* delNode = qFront;
	qFront =qFront->next;

	if(qFront==nullptr)
		qBack= nullptr;

	delete delNode;
	--qSize;
}

#endif

