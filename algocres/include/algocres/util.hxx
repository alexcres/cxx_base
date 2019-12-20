//
// Created by ac on 12/10/19.
//

#ifndef ALGOCRES_UTIL_HXX
#define ALGOCRES_UTIL_HXX

namespace algocres {
template<typename E>
void resize(E *&array, int size);

template<typename E>
void resize(E *&array, int size) {
	int *temp{new E[size]};
	for (int i = 0; i != size; ++i) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
}
}// namescpace algocres
#endif //algocres_UTIL_HXX
