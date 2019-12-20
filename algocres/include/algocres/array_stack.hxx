#ifndef ALGOCRES_ARRAYSTACK_HXX
#define ALGOCRES_ARRAYSTACK_HXX

#include <stdexcept>
#include "stackable.hxx"
#include "util.hxx"

namespace algocres {
template<typename E>
class ArrayStack : public Stackable<E> {
public:
	ArrayStack();

	~ArrayStack();

	void push(E elem);

	E &pop();

	[[nodiscard]] bool isEmpty() const;

	int getSize() { return size_; } // for test

private:
	int top_{0};
	int size_{2};
	E *stack_{new E[2]};

//	void resize(int newSize);
};

template<typename E>
ArrayStack<E>::ArrayStack() = default;

template<typename E>
ArrayStack<E>::~ArrayStack() {
	delete[] stack_;
}

template<typename E>
inline bool ArrayStack<E>::isEmpty() const {
	return top_ == 0;
}

template<typename E>
void ArrayStack<E>::push(E elem) {
	if (top_ > size_) {
//			resize(size_ *= 2);
		resize(stack_, size_ *= 2);
	}
	stack_[top_++] = elem;
}

template<typename E>
E &ArrayStack<E>::pop() {
	if (isEmpty()) {
		throw std::out_of_range("ArrayStack Underflow");
	}
	// top_ > 1: prevent division by 0
	if (top_ > 1 && size_ / (top_ - 1) >= 4) {
//			resize(size_ /= 2);
		resize(stack_, size_ /= 2);
	}
	return stack_[--top_];
}


//template<typename E>
//void ArrayStack<E>::resize(int newSize) {
//	E *temp{new E[newSize]};
//	for (int i = 0; i != top_; ++i) {
//		temp[i] = stack_[i];
//	}
//	delete[] stack_;
//	stack_ = temp;
//}
}// namespace algocres
#endif //CMAKE_PROJECT_TEMPLATE_STACK_HXX
