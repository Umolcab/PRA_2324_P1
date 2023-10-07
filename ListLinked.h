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
					}else{
						aux = aux->next;
					}
				}
			}else{
				throw std::out_of_range("Posición fuera del array.");
			}
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			out << "List [";
			for(int i = 0; i < list.n; i++){
				out << "\n" << list.first[i];
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
				preaux->next = new Node(e);
				preaux = preaux->next;
				preaux->data = e;
				preaux->next = aux;
				n++;
			}else{
				throw std::out_of_range("Posición fuera del array.");
			}
		}

		void append(T e){
			insert(n, e);
		}

		void prepend(T e){
			insert(0, e);
		}

		T remove(int pos){
			Node<T>* aux = first;
			Node<T>* preaux = nullptr;
			if(pos >= 0 && pos <= n){
				for(int i = 0; i < pos; i++){
					preaux = aux;
					aux = aux->next;
				}
				preaux->next = aux->next;
				aux->next = nullptr;
				n--;
				return aux->data;
			}else{
				throw std::out_of_range("Posición fuera del array.");
			}
		}

		T get(int pos){
                    	if(pos >= 0 && pos <= n){
				return first[pos];
			}else{
				throw std::out_of_range("Posición fuera del array.");
			}
		}

		int search(T e){
			Node<T>* aux = first;
			int pos = -1;
			T x;
                        for(int i = 0; i < n; i++){
				x = aux[i];
				if(e == x){
					pos = i;
					break;
				}
			}
			return pos;
		}

		bool empty(){
			return n == 0;
		}

		int size(){
			return n;
		}
};
