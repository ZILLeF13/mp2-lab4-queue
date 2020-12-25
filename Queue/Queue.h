#pragma once
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include<iostream>
template <class T>
class Queue
{
	int MaxSize;
	int head;
	int tail;
	int DataCount;
	T* pMem;
public:
	Queue(int s = 10);
	Queue(const Queue<T>& s);
	~Queue();
	Queue<T>& operator = (const Queue<T>& s);
	bool operator == (const Queue<T>& s) const;
	bool operator != (const Queue<T>& s) const;
	T front();
	T back();
	bool empty();
	bool full();
	void push(T elem);
	T pop();
	T GetSize();
	T GetMaxSize();
};
 
template<class T>
Queue<T>::Queue(int s)
{
	if (s <= 0)
	{
		throw"Queue";
	}
	head = 1;    //0
	tail = 0;    //-1
	DataCount = 0;
	MaxSize = s;
	pMem = new T[MaxSize];
}

template <class T>
Queue<T>::Queue(const Queue<T>& s)
{
	MaxSize = s.MaxSize;
	pMem = new T[MaxSize];
	DataCount = s.DataCount;
	head = s.head;
	tail = s.tail;
	int _head = head, _DataCount = 0;
	while (_DataCount != DataCount)
	{
		pMem[_head] = s.pMem[_head];
		_head = (_head + 1) % MaxSize;
		_DataCount++;
	}
}

template <class T>
Queue<T>::~Queue()
{
	if (pMem)
	{
		delete[]pMem;
		pMem = 0;
	}
}

template <class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& s)
{
	if (this != &s)
	{
		if (DataCount != s.DataCount)
		{
			MaxSize = s.MaxSize;
			delete[]pMem;
			pMem = new T[MaxSize];
		}
		DataCount = s.DataCount;
		head = s.head;
		tail = s.tail;
		int _head = head, _DataCount = 0;
		while (_DataCount != DataCount)
		{
			pMem[_head] = s.pMem[_head];
			_head = (_head + 1) % MaxSize;
			_DataCount++;
		}
	}
	return *this;
}

template<class T>
bool Queue<T>::operator == (const Queue<T>& s) const
{
	if (this != &s)
	{
		if (DataCount != s.DataCount || MaxSize != s.MaxSize)
		{
			return false;
		}
		int _head = head,_head_=s.head, _DataCount = 0;
		while (_DataCount != DataCount)
		{
			if (pMem[_head] = s.pMem[_head_])
			{
				return false;
			}
			_head = (_head + 1) % MaxSize;
			_head_ = (_head_ + 1) % MaxSize;
			_DataCount++;
		}
	}
	return true;
}

template<class T>
bool Queue<T>::operator != (const Queue<T>& s) const
{
	return !(*this == s);
}

template<class T>
T Queue<T>::front()
{
	if (!empty())
	{
		return pMem[head];
	}
}

template<class T>
T Queue<T>::back()
{
	if (!empty())
	{
		return pMem[tail];
	}
}

template<class T>
bool Queue<T>::full()
{
	if (DataCount == MaxSize)
	{
		return true;
	}
	return false;
}

template<class T>
bool Queue<T>::empty()
{
	if (DataCount == 0)
	{
		return true;
	}
	return false;
}

template <class T>
void Queue<T>::push(const T elem)
{
	if (!full())
	{
		DataCount++;
		tail = (tail + 1) % MaxSize;
		pMem[tail] = elem;
	}
	else
	{
		throw "push";
	}
}

template<class T>
T Queue<T>::pop()
{
	if (!empty())
	{
		DataCount--;
		head = (head + 1) % MaxSize;
	}
	else
	{
		throw "pop";
	}
	if (head == 0)
	{
		return pMem[MaxSize - 1];
	}
	return pMem[head - 1];
}

template<class T>
T Queue<T>::GetSize()
{
	return DataCount;
}

template<class T>
T Queue<T>::GetMaxSize()
{
	return MaxSize;
}
