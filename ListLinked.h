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

		T operator[](int pos){
			Node<T>* aux = first;
			if(pos >= 0 && pos <= n){
				for(int i = 0; i < n; i++){
					if(i = pos){
						return aux->data;
					}
					aux = aux->next;
				}
			}else{
				throw std::out_of_range("Posición fuera del array.");
			}
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
				out << "List [";
				for(int i = 0; i < list.n; i++){
					out << "\n" << list[i];
				}
				out << "]";
				return out;
		}

		void insert(int pos, T e){
			Node<T>* aux = first;
			Node<T>* preaux = nullptr;
			if(pos >= 0 && pos <= n){
				for(int i = 0; i < pos; i++){
					preaux = aux;
					aux = aux->next;
				}
				preaux->next = new Node<T>;
				preaux = preaux->next;
				preaux->data = e;
				preaux->next = aux;
			}else{
				throw std::out_of_range("Posición fuera del array.");
			}
		}

		void append(T e);
		void prepend(T e);
		T remove(int pos);
		T get(int pos);
		int search(T e);
		bool empty();
		int size();
};
