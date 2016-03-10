#include<iostream>

using namespace std;

#ifndef __LIST__
#define __LIST__


template<typename T>
class List {
private:
	T *array;
	int size; //se va modifica la fiecare remove/add de element!
	
	class Iterator {
	public:
		const T *element;
		int index;

		Iterator(T *element, int index) {
			this->element = element;
			this->index = index;
		}

		T& operator *() {
			return *element;
		}

		T* operator ->() {
			return element;
		}

		//prefix ++
		Iterator& operator ++() {
			if (index >= size - 1) {
				cout << endl << "At end of array";
				return element;
			}
			return Iterator(element++, index+1);
		}

		//postfix ++
		Iterator operator ++(int) {
			if (index >= size - 1) {
				cout << endl << "At end of array";
				return element;
			}
			return Iterator(element++, index + 1);
		}
	};
	
public:
	typedef Iterator iterator;
	// Metoda de initializare
	List() {
		this->size = 0;
		this->array = new T[ 0 ];
	}

	// Adauga elem pe pozitia index
	void insert (T element, int index){
		T *tmpArray = new T[size+1];
		int i;

		for(i =0; i < index; i++)
			tmpArray[i] = array[i];
		tmpArray[index]= element;
		for(i = index + 1; i< size + 1; i++)
			tmpArray[i] = array[i-1];

		delete [] array;
		array = tmpArray;
		size = size + 1;
	}

	// Metoda de eliminare a unui element la index dat
	void remove(int index) {
		int i;
		for(i = index; i < size-1; i++)
			array[i] = array[i+1];

		T *tmpArray = new T[size-1];
		for(i = 0; i < size-1; i++)
			tmpArray[i] = array[i];

		delete[] array;

		array = tmpArray;
		size = size-1;

	}
	
	void push_back(const T& element);
	void push_front(const T& element);
	
	Iterator begin() {
		return Iterator(&array, 0);
	}
	Iterator end() {
		return Iterator(&array[size - 1], size-1);
	}

	// Metoda care afiseaza elementele vectorului.
	void print() {
		std::cout << "Continut: ";
		for ( int i = 0; i < size; i++ ) {
			std::cout << array[i] << ' ';
		}
		std::cout << '\n';
	}
};

#endif // __LIST__
