#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v1;   //Our vector class
   
	 v1.push_back(1);
		
	try {	
		cout << v1.at(2) << endl;
	}
	catch(std::out_of_range e) {
		cout << "out of bounds!" << endl;
	}


//std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   //v.push_back(23);
   //stdv.push_back(23);
   
  // cout << "Our vector size: " << v.size() << endl;
   //cout << "STL vector size: " << stdv.size() << endl;

   return 0;
}

