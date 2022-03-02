#include <iostream.h>
#include <conio.h>

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& arr) {
   size = arr.size;
   count = arr.count;
   p = new T[size];
   for(int i = 0; i<count; ++i)
      p[i] = arr.p[i];
}

template<class T>
DynamicArray<T>&
DynamicArray<T>::operator=(const DynamicArray& arr) {
   if(this != &arr) {                  //to avoid assignment to itself
      size = arr.size;
      count = arr.count;
      if(p) delete[] p;
      p = new T[size];
      for(int i = 0; i<count; ++i)
         p[i] = arr.p[i];
   }
   return *this;
}

template<class T>
T DynamicArray<T>::operator[](long i) const {
   if(i < size && i)
      return p[i-1];
   else
      return 0;
}

template<class T>
DynamicArray<T>&
DynamicArray<T>::operator+(const DynamicArray& arr) {
   DynamicArray temp(*this);
   if(p) delete[] p;
   size += arr.size;
   count += arr.count;
   p = new T[size];
   for(int i = 0; i<temp.count; ++i)
      p[i] = temp.p[i];
   for(int i = 0; i<arr.count; ++i)
      p[temp.count + i] = arr.p[i];
   return *this;
}

template<class T>
void DynamicArray<T>::print() const {
   cout<<"The array contains:"<<endl;
   for(int i = 0; i<count; ++i)
      cout<<p[i]<<' ';
   cout<<endl;
}

template<class T>
void DynamicArray<T>::add(T x) {
   if(count >= size) {
      DynamicArray temp(*this);
      if(p) delete[] p;
      size += 10;
      p = new T[size];
      for(int i = 0; i<temp.count; ++i)
      p[i] = temp.p[i];
   }
   p[count++] = x;
}

template<class T>
void DynamicArray<T>::remove() {
   if(count)
      p[--count] = 0;
}



