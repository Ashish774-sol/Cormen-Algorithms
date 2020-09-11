#include <iostream>


template<class T>
class Stacks{
private:
	T *m_array;
	int m_top1;
	int m_top2;
	int m_size;
public:
	Stacks(int max_size): m_size{max_size + 2}{
		m_array = new T[m_size];
		m_top1 = 0;
		m_top2 = m_size - 1;
	}
	bool s1_empty() const{
		return m_top1 == 0;
	}
	bool s2_empty() const{
		return m_top2 == m_size - 1;
	}
	bool full() const{
		return (m_top2 - m_top1 == 1);
	}
	void push_to_s1(T x){
		if(full()){
			std::cout << "Stack space is full.\n";
			return;
		}
		else
			m_array[++m_top1] = x;
	}
	void push_to_s2(T x){
		if(full()){
			std::cout << "Stack space is full.\n";
			return;
		}
		else
			m_array[--m_top2] = x;
	}
	T pop_s1(){
		if(s1_empty()){
			std::cout << "Stack 1 is empty.\n";
			return 0;
		}
		m_top1--;
		return m_array[m_top1 + 1];
	}
	T pop_s2(){
		if(s2_empty()){
			std::cout << "Stack 2 is empty.\n";
			return -1;
		}
		m_top2++;
		return m_array[m_top2 - 1];
	}

	friend std::ostream& operator<<(std::ostream& out, const Stacks &s){
		out << "Stack 1:\n";
		for(int i{1}; i <= s.m_top1; i++)
			out << s.m_array[i] << "    ";
		out << "\nStack 2:\n";
		for(int i{s.m_size - 2}; i >= s.m_top2; i--)
			out << s.m_array[i] << "    ";
		out << '\n';
		return out;
	}
};

int main(){
	Stacks<int> s(10);
	//Fill the staack
	for(int i{0}; i < 10; i++){
		if(i < 5)
			s.push_to_s1(i);
		else
			s.push_to_s2(i);
	}
	std::cout << s;
	s.pop_s1();
	s.push_to_s1(4);
	s.push_to_s1(5);
	s.pop_s2();
	s.push_to_s2(7);
	s.push_to_s2(22);
	std::cout << s;
	return 0;
}