#include <iostream>

template<class T>

class Stack{
private:
	T *m_array;
	int m_top;
	int max_size;
public:
	Stack(int size): max_size{size}{
		m_array = new T[max_size];
		m_top = 0;
	}

	bool isEmpty() const{
		return m_top == 0;
	}

	bool isFull(){
		return (m_top >= max_size);
	}

	void push_back(T x){
		if(isFull()){
			std::cout << "Stack is full.\n";
			return;
		}

		m_array[++m_top] = x;
		std::cout << "Pushed " << x << " onto the stack.\n";
	}

	T pop(){
		if(isEmpty()){
			std::cout << "Stack is empty.\n";
			return -1;
		}
		m_top--;
		return m_array[m_top + 1];
	}

	friend std::ostream& operator<<(std::ostream &out,const Stack &stack){
		out << "Current Elements in Stack:\n";
		for(int i{1}; i <= stack.m_top; i++){
			out << stack.m_array[i] << "    ";
		}
		out << '\n';
		return out;
	}
};

int main(){
	Stack<int> stack(5);

	stack.pop();
	stack.push_back(10);
	stack.push_back(5);
	std::cout << "Popped Value:" << stack.pop() << '\n';
	stack.push_back(231);
	stack.push_back(1);
	stack.push_back(5);
	stack.push_back(6);
	stack.push_back(12);


	std::cout << stack;
	return 0;
}


