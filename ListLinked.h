#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
	private:
		Node<T>* first;
		int n;
	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}

		~ListLinked(){
			Node<T>* aux = first->next;
			delete first;
			first = aux;
		}

		T operator[](int pos);
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list);
		void insert(int pos, T e);
		void append(T e);
		void prepend(T e);
		T remove(int pos);
		T get(int pos);
		int search(T e);
		bool empty();
		int size();
};
