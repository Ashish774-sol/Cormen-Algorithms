#include <iostream>

template<class T>
class Queue{
private:
	T *m_array;
	int m_head;
	int m_tail;
	int m_size;
public:
	Queue(int max_size): m_size{max_size}{
		m_array = new T[m_size];
		m_head = 0;
		m_tail = 0;
	}
	bool empty() const{
		return m_head == m_tail;
	}
	bool full() const{
		return ((m_head == 0 and m_tail == m_size) or (m_tail + 1 == m_head));
	}
	void enqueue(T x){
		if(full()){
			std::cout << "Queue is full.\n";
			return;
		}
		m_array[m_tail] = x;
		if(m_tail == m_size)
			m_tail = 0;
		else
			m_tail++;
	}
	T dequeue(){
		if(empty()){
			std::cout << "Queue is empty.\n";
			return 0;
		}
		T x = m_array[m_head];
		if(m_head == m_size)
			m_head = 1;
		else
			m_head++;
		return x;
	}
	friend std::ostream& operator<<(std::ostream &out, const Queue &q){
		out << "Current Queue:\n";
		int i = q.m_head;
		while(i != q.m_tail){
			out << q.m_array[i] << " ";
			if(i == q.m_size)
				i = 0;
			else
				i++;
		}
		out << '\n';
		return out;
	}
};

int main(){
	Queue<int> q1(5);\
	for(int i{1}; i <= 6; i++){
		q1.enqueue(i);
		q1.enqueue(i+1);
		q1.dequeue();
	}
	std::cout << q1;
	return 0;
}