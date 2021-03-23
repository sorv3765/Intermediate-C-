#include <iostream>
#include <stdexcept>
#include "Queue.h"

using namespace std;

using std::underflow_error;

/*************************************************
 Default Constructor
 *************************************************/
Queue::Queue()
{
	qSize = 0;			//numbers of value currently in array
	qArray = nullptr;		//pointer in array values
	qCapacity =0;			//maximum number of elements that may be stored in array
	qFront=0;
	qBack= qCapacity-1;

}

/*************************************************
 Destructor
 *************************************************/
Queue::~Queue()
{
    delete [] qArray;
}

/*************************************************
 Copy Constructor
 *************************************************/
Queue::Queue(const Queue& other)
{
	qCapacity=other.qCapacity;		//copy capacity
	qSize = other.qSize;			//copy size
	qArray = new int[qCapacity];		//copy array pointer

	for (size_t i = 0; i < qCapacity; i++)	//copy for each capacity in array
        {
            qArray[i] = other.qArray[i];
	}

	qFront= other.qFront;			//copy front
	qBack= other.qBack;			//copy back

}

/*************************************************
 Overloaded Copy Assignment Operator
 *************************************************/
Queue& Queue::operator=(const Queue& other)
{
       if(this!=&other)				//self assignment
	{
	qCapacity=other.qCapacity;
        qSize = other.qSize;

	delete [] qArray;			//delete the data in array pointer

        qArray = new int[qCapacity];		//create new data in array

        for (size_t i = 0; i < qCapacity; i++)	//copy every data from previous to new array
        {
            qArray[i] = other.qArray[i];
        }

        qFront= other.qFront;
        qBack= other.qBack;
	}

	return *this;
}

/*************************************************
 Output Operator
 *************************************************/
ostream& operator<<(ostream &lhs, const Queue& other)
{
    size_t current, i;

        for (current = other.qFront, i=0; i < other.qSize; ++i)
        {
            // Print queue element at subscript i
            lhs << other.qArray[current] << ' ';
            // Increment i, wrapping around to front of queue array if necessary
            current = (current + 1) % other.qCapacity;
        }

    return lhs;
}

/*************************************************
 Instantly clears the data
 *************************************************/
void Queue::clear()
{
//clears everything back to zero.... except back should be -1
    delete [] qArray;
    qArray = nullptr;
    qFront =0;
    qBack =-1;
    qCapacity=0;
    qSize = 0;
    
}

/*************************************************
 Return size of the Vector
 *************************************************/
size_t Queue::size() const
{
    return qSize;
}

/*************************************************
 Return capacity of the Vector
 *************************************************/
size_t Queue::capacity() const
{
    return qCapacity;
}

/*************************************************
 Return empty of the Vector
 *************************************************/
bool Queue::empty() const
{
	if(qSize==0)					//check to see if queue size is 0
		return true;

	return false;
}

/*************************************************
 Front Queue
 *************************************************/
int Queue::front() const
{
   if(empty())							//check to see if the Front is empty
	throw underflow_error("front underflow error");

	return qArray[qFront];
}
/*************************************************
 Back Queue
 *************************************************/
int Queue::back() const
{
	if(empty())							//check to see if Back is empty
		throw underflow_error("back underflow error");

	return qArray[qBack];

}
/*************************************************
 Queue PUSH
 *************************************************/
void Queue::push(int newItem)
{
	if(qSize== qCapacity)
	{
		if(qCapacity==0)
			reserve(1);
		else
			reserve(qCapacity*2);
	}

	qBack=(qBack+1)%qCapacity;
	qArray[qBack] = newItem;
	++qSize;
}
/*************************************************
  Queue POP
 *************************************************/
void Queue::pop()
{
    if(empty())							//check if its empty then add 1 to the Front
	throw underflow_error("pop underflow error");

	qFront = (qFront+1)%qCapacity;
--qSize;
}

/*************************************************
 Return reserve of the Vector
 *************************************************/
void Queue::reserve(size_t n)
{
	if (n > qCapacity)
	{
		int* tempArray = new int[n];

		int current =qFront;
		for (size_t i = 0; i < qSize; ++i)
		{
			tempArray[i] =qArray[current];
			current=(current+1)%qCapacity;
		}

		qCapacity=n;
		qFront=0;
		qBack=qSize-1;
		delete[] qArray;
		qArray =tempArray;
	}
}
