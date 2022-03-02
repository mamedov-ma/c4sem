include "class_T.h"


//test the DynamicArray class
int main() {
   DynamicArray<int> da(15);
   for(int i = 0; i<20; ++i)
      da.add(i+1);
   da.print();
   
   DynamicArray<int> da2(da);
   DynamicArray<int> da3 = da + da2;
   da3.print();

   cout<<"Press any key..."<<endl;
   getch();
   return 0;
}
   
      