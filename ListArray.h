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
			T* new_array = new ListArray<T>;
			for(int i = 0; i < max; i++){
				new_array[i] = arr[i];
			}
			std::destroy(arr);
			arr = new_array;
			max = new_size;
		}

	public:
		ListArray(){
			arr = new ListArray<T>;
			max = MINSIZE;
			n = 0;
		}

		~ListArray(){
			std::destroy(arr);
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
			out << "List [" << std::endl;
			while(i <= list.n){
				out << " " << list[i] << std::endl;
				i++;
			}
			out << "]" << std::endl;
			return out;
		}

		void insert(int pos, T e) override{
			if(pos >= 0 && pos < max){
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
			for(int i = n-1; i > 0; i--){
				insert(arr[i+1],get(arr[i]));
			}
			insert(0, e);
		}

		T remove(int pos) override{
			if(pos >= 0 && pos <= max-1){
				arr[pos] = 0;
				resize(n-1);
				n--;
			}else{
				throw std::out_of_range("La posición está fuera del array.");
			}
		}

		T get(int pos) override{
			return arr[pos];
		}

		int search(T e) override{
			int aux = -1;
			for(int i = 0; i < n; i++){
				if(e = arr[i]){
					aux = e;
					break;
				}
			}

			return aux;
		}

		bool empty() override{
			return n = 0;
		}

		int size() override{
			return n;
		}
};


