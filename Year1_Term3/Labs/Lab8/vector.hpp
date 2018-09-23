#include <stdlib.h>
#include <iostream>
#include <stdexcept>
using std::exception;
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
	  
      ~vector(){
	     delete [] v;
      }
			
			vector(vector<T> &other) {
				this->s = other.s;
			
				if (this->s == 0) {
					this->v = NULL;
				}			
				else {
					this->v = new T[this->s];
					for (int i = 0; i < this->s; i++) {
						this->v[i] = other.v[i];
					}
				}
			}

			void operator=(vector<T> &other) {
				this->s = other.s;
			

				if (this->v != NULL) {
					delete [] v;
				}
				if (this->s == 0) {
					this->v = NULL;
				}			
				else {
					this->v = new T[this->s];
					for (int i = 0; i < this->s; i++) {
						this->v[i] = other.v[i];
					}
				}
			}

			T operator[] (int i) {
				return v[i];	
			}
			
      int size() {
	     return s;
      }

      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
      }

			T at(int i) {
					if (i >= s) {
						throw std::out_of_range("out of my vector bounds");
					}
					else {
						return v[i];
					}		
				
			}

};
