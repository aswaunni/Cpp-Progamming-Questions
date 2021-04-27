#include <bits/stdc++.h>

using namespace std;

template <class T>
class uniquePointer {
	private:
		T* ptr;

		void cleanup()
		{
			if (ptr)
				delete ptr;
		}

	public:
		uniquePointer()
			: ptr(nullptr)
		{
		}

		uniquePointer(T* ptr)
			: ptr(ptr)
		{
		}

		~uniquePointer()
		{
			cleanup();
		}

		uniquePointer(const uniquePointer& obj) = delete; // deleting copy constructor
		uniquePointer& operator = (const uniquePointer& obj) = delete; // deleting copy assignment

		uniquePointer(uniquePointer&& oldObj) // move constructor 
		{
			this->ptr = oldObj.ptr;
			oldObj.ptr = nullptr;
		}

		void operator = (uniquePointer&& oldObj) // move assignment
		{
			cleanup();
			this->ptr = oldObj.ptr;
			oldObj.ptr = nullptr;
		}

		T* operator -> ()
		{
			return this->ptr;
		}

		T& operator * ()
		{
			return *(this->ptr);
		}
};

class Box {
	private:
		int x;
		int y;

	public:
		Box() 
			: x(0)
			, y(0)
	{
	}
};

int main()
{
	uniquePointer<Box> p(new Box);
	uniquePointer<Box> p2(std::move(p));
	return 0;
}

