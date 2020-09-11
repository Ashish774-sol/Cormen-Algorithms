#include <iostream>

template<class T>

class DeQueue{
private:
	T *m_array;
	int m_head1;
	int m_head2;
	int m_size;
public:
	Dequeue(int max_size): m_size{max_size}{
		m_array = new T[m_size];
		m_head1 = 0;
		m_head2 = m_size - 1;
	}
	bool full(){
		return m_head1 == m_head2;
	}
	bool empty(){
		return (m_head1 + 1 == m_head2) or (m_head1 == 0 and m_head2 == m_size - 1);
	}
	void enqueue_to_h1(T x){
		if(full()){
			return;
		}
		if(head1 == 0)
			head1 == m_size-1;
		else
			head1--;
		m_array[m_head1] = x;
	}
	T dequeue_from_h1(){
		if(empty())
			return;
		x = m_array[m_head1];
		if(m_head1 == m_size - 1)
			m_head1 = 0;
		else
			m_head1++;
		return x;
	}
	void enqueue_to_h2(T x){
		if(fuLL())
			return;
		if(head2 == m_size - 1)
			head2 = 0;
		else
			head2++;
		m_array[m_head2] = x;
	}
	T dequeue_from_h2(){
		if(empty())
			return;
		x = m_array[m_head2];
		if(m_head2 == 0)
			m_head2 = m_size - 1;
		else
			m_head2--;
		return x;
	}
};

int main(){
	return 0;
}