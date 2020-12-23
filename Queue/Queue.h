#pragma once
template <class T>
class Queue
{
	int MaxSize;
	int head;
	int tail;
	int DataCount;
	T* pMem;
public:
	Queue(int s = 10)
	{
		head = 0;
		tail = -1;
		DataCount = 0;
		MaxSize = s;
		pMem = new T[MaxSize];
	}
	~Queue()
	{
		if (pMem)
		{
			delete[]pMem;
			pMem = 0;
		}
	}
	T front()
	{
		if (!empty())
		{
			return pMem[head];
		}
	}

	T back()
	{
		if (!empty())
		{
			return pMem[tail];
		}
	}

	bool empty()
	{
		return DataCount == 0;
	}

	bool full()
	{
		return DataCount == MaxSize;
	}

	void push(T elem)
	{
		if (!full())
		{
			DataCount++;
			tail = (tail + 1) % MaxSize;
			pMem[tail] = elem;
		}
	}

	void pop()
	{
		if (!empty())
		{
			DataCount--;
			head = (head + 1) % MaxSize;
		}
	}
};
