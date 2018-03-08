#include "DynArray.hh"

int main() 
{
	 DynArray full  =DynArray::DynArray(9,10);
	 DynArray empty = DynArray::DynArray();

	 
	 std::cout << "Esta vacio?: " << full.capacity() << std::endl;	
	 std::cout << "Primer numero es: " << full.front() << std::endl;
	 full.print();
	 full.clear();
	 std::cout << "Esta vacio ahora?: " << full.capacity() << std::endl;
	 
}