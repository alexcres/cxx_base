//
// Created by ac on 12/18/19.
//

#ifndef ALGOCRES_STACKABLE_HXX
#define ALGOCRES_STACKABLE_HXX
namespace algocres {
template<typename E>
class Stackable {
	[[nodiscard]] virtual bool isEmpty() const = 0;

	virtual void push(E elem) = 0;

	virtual E &pop() = 0;
};
}// namespace algocres
#endif //algocres_STACKABLE_HXX
