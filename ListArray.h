#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T>{
	private:
		T* arr; //inicio array creado
		int max; //tamaño max
		int n; //numero de elementos
		static const int MINSIZE = 2; //tamaño mínimo
		void resize(int new_size){	//metodo para redimensionar
			T* new_array = new T[new_size];
			for(int i = 0; i < max; i++){
				new_array[i] = arr[i];
			}
			delete arr;
			arr = new_array;
			max = new_size;
		}

	public:
		ListArray(){
			arr = new T[MINSIZE];
			max = 2;
			n = 0;
		}

		~ListArray(){
			delete arr;
		}

		T operator[](int pos){
			if(pos >= 0 && pos <= max-1){
				return arr[pos];
			}else{
				throw std::out_of_range("La posición está fuera del array.");
			}
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			int i = 0;
			out << "List [";
				while(i < list.n){
				out << " " << list.arr[i] << std::endl;
				i++;
			}
			out << "]";
			return out;
		}

		void insert(int pos, T e) override{
			if(pos >= 0 && pos < max){
				for(int i=max; i>=pos; i--){
					arr[i] = arr[i-1];
				}
				arr[pos] = e;
				n++;
			}else{
				throw std::out_of_range("La posición está fuera del array.");
				resize(n+1);
			}
		}

		void append(T e) override{
			insert(n, e);
		}

		void prepend(T e) override{
			insert(0, e);
		}

		T remove(int pos) override{
			if(pos >= 0 && pos <= max-1){
				T aux = arr[pos];
				for(int i = pos; i<max; i++){
					arr[i] = arr[i+1];
				}
				resize(n-1);
				n--;
				return aux;
			}
			throw std::out_of_range("La posición está fuera del array.");
		}

		T get(int pos) override{
			if(pos >= 0 && pos < n)
				return arr[pos];
		}

		int search(T e) override{
			int aux = -1;
			for(int i = 0; i < n; i++){
				if(arr[i] == e){
					aux = e;
					break;
				}
			}
			return aux;
		}

		bool empty() override{
			return n == 0;
		}

		int size() override{
			return n;
		}
};


