#ifndef _QUEUE_H_
#define _QUEUE_H_

template <class ValType>
class TQueue
{
	int begin, end, len, max_size;
	ValType *mas;
public:
	TQueue(int m_size = 10)
	{
		max_size = m_size;
		mas = new ValType[max_size];
		begin = 0;
		end = -1; 
		len = 0;
	}
	~TQueue()
	{
		delete[]mas;
	}
	bool IsEmpty()
	{
		return(len == 0);
	}
	bool IsFull()
	{
		return (len == max_size)
	}
	void Push(const ValType n)
	{
		if (end < = max_size - 1) end++; else end = 0;
		mas[end] = n; len++;
	}
	ValType Pop()
	{
		if (IsEmpty()) throw - 1;
		else
		{
			ValType tmp = mas[begin];
			if (begin < max_size - 1) begin++; else begin = 0;
			len--; return tmp;
		}
	}
	ValType Front()
	{
		if (IsEmpty()) throw - 1;
		return mas[begin];
	}
	ValType Back()
	{
		if (IsEmpty()) throw - 1;
		return mas[end];
	}
};

#endif
