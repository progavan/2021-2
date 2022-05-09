#ifndef VECTORCONT_H_INCLUDED
#define VECTORCONT_H_INCLUDED
#include <vector>
#define LENGTH(A)   (sizeof(A)/sizeof(A[0]))
#ifdef CONFIG_MAIN_MODULE
 int myArr[] = {2,4,6};
 //int myArr[] = {2,4,6,8};
#define SIZE_INTS_ARR    LENGTH(myArr)
typedef struct NyArr {
 short N;
#ifndef CONFIG_USE_INCOMPLETE_ARRAY
 int Arr[SIZE_INTS_ARR];
#else
static int Arr[];
#endif // CONFIG_USE_INCOMPLETE_ARRAY
} NyArr;
#endif
class VectorCont {
private:
 std::vector<int> int_vec;
public:
static short size;
 void add(int);
};


#endif // VECTORCONT_H_INCLUDED
