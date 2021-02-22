#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stdlib.h"
#include <stdint.h>

typedef struct PolyEl PolyEl;
typedef struct PolyArr PolyArr;

PolyArr CreatePolyArr();


struct PolyEl {
    int8_t* data;
    size_t size;
};

struct PolyArr {
    PolyEl* data;
    size_t len;
    void (*Add)(PolyEl, PolyArr*);
    PolyArr(*Concat)(PolyArr, PolyArr);
};



void CopyEl(PolyEl from, PolyEl* to)
{
    (*to).data = (int8_t*)malloc(from.size);
    for (size_t i = 0; i < from.size; ++i)
        (*to).data[i] = from.data[i];

}
void Add(PolyEl elm,PolyArr* this) {
    (*this).data = (PolyEl*)realloc((*this).data, ((*this).len + 1) * sizeof(PolyEl));
    CopyEl(elm, &((*this).data[++(*this).len]));
    printf("%f\n", *(float*)(*this).data->data);
}
PolyEl InitEl(void* data, const size_t size)
{
    int8_t* res = (int8_t*)malloc(size);
    for (size_t i = 0; i < size; ++i)
        res[i] = ((int8_t*)data)[i];
    return (PolyEl) { res, size };
}
PolyArr ArrConcat(PolyArr arr1, PolyArr arr2) {
    PolyArr res = CreatePolyArr();
    for (int i = 0; i < arr1.len; ++i) {
        res.Add(*arr1.data, &res);
    }
    for (int i = 0; i < arr2.len; ++i) {
        res.Add(*arr2.data, &res);
    }
    return res;
}

PolyArr CreatePolyArr() {
    PolyArr res = (PolyArr){ (PolyEl*)malloc(sizeof(PolyEl)), 0, Add, ArrConcat };
    return res;
}

//void AddMul(PolyEl * elm, PolyArr * arr) {
//    (*arr).data = (PolyEl *)realloc((*arr).data, ((*arr).len + 1) * sizeof(PolyEl));
//    while
//    ((*arr).data + (*arr).len) -> data = elm.data;
//    ((*arr).data + ++(*arr).len) -> Concat = elm.Concat;
//}

//plain old data = POD



int main() {
    float a[] = { 0.5f, 2.0f };
    //    malloc(2*sizeof(PolyEl))
    //{((PolyEl) {&a[0], FlConcat}), ((PolyEl) {&a[0], FlConcat})}
    PolyArr arr = { (PolyEl*)malloc(1 * sizeof(PolyEl)) , 0,  Add };
    arr.Add(InitEl(&a[0], sizeof(float)), &arr);
    arr.Add(InitEl(&a[1], sizeof(float)), &arr);
    printf("%d\n", arr.len);
    printf("%f\n", *(float*)(arr.data[0].data));
    //    printf("%f", *(float *) (el1.Concat(el1, el2).data));
    return 0;
}



