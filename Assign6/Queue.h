#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

using namespace std;

class Queue
{
friend std::ostream& operator<<(std::ostream&, const Queue&);

private:
	int *qArray;						//array pointer
	size_t qSize;						// current number of items in Queue
	size_t qCapacity;					// maximum number of elements that may be stored in array
	int qFront;
	int qBack;
public:
        Queue();						//Default constructor
        ~Queue();						//Deconstructor
	Queue(const Queue&);					//copy constructor
	Queue&  operator=(const Queue&);			//overloaded copy assignment operator
        void clear();
        size_t  size()const;
        size_t capacity()const;
	bool empty()const;
	int front()const;
        int  back()const;
        void push(int);
        void pop();
	void reserve(size_t);
};

#endif
