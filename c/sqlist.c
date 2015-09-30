#include "stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

Status InitList(SqList *L)
{
    L->length = 0;
    return OK;
}

Status isEmptyList(SqList L)
{
    return L.length == 0 ? TRUE : FALSE;
}

int ListLength(SqList L)
{
    return L.length;
}

Status InsertListItem(SqList *L, int i, ElemType e)
{
    if (L->length == MAXSIZE) return ERROR;
    if (i < 1 || i > L->length + 1) return ERROR;

    if (i <= L->length) {
        for (int k = L->length - 1; k >= i - 1; k --) {
            L->data[k + 1] = L->data[k];
        }
    }
    L->data[i - 1] = e;
    L->length ++;

    return OK;
}

Status DeleteListItem(SqList *L, int i, ElemType *e)
{
    if (L->length == 0) return ERROR;
    if (i < 1 || i > L->length) return ERROR;

    *e = L->data[i - 1];

    if (i < L->length) {
        for (int k = i; k < L->length; k ++) {
            L->data[k - 1] = L->data[k];
        }
    }
    L->length --;

    return OK;
}

void Visit(ElemType e)
{
    printf("%d ", e);
}

Status ListTraverse(SqList L)
{
    for (int i = 0; i < L.length; i ++) {
        Visit(L.data[i]);
    }
    printf("\n");

    return OK;
}

Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length) return ERROR;
    *e = L.data[i - 1];

    return OK;
}

Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

int main()
{
    SqList L;
    InitList(&L);
    printf("is the list empty (0 false|1 true) ? %d\n", isEmptyList(L));

    for (int i = 0; i < 5; i ++) {
        InsertListItem(&L, i + 1, i);
    }

    ListTraverse(L);

    InsertListItem(&L, 3, 10);

    ListTraverse(L);

    ElemType e;
    DeleteListItem(&L, 1, &e);

    ListTraverse(L);

    GetElem(L, 3, &e);
    printf("the third item is %d\n", e);

    ClearList(&L);
    printf("is the list empty (0 false|1 true) ? %d\n", isEmptyList(L));



    return 0;
}



