#include <stdio.h>

#define MAX_TBL 100

enum SlotStatus { EMPTY, DELETED, INUSE };

typedef int HashFunc(Key k);

typedef struct _STable
{
    Slot tbl[MAX_TBL];
    HashFunc* hf;
} Table;

typedef struct _SPerson
{
    int ssn;
    char* name;
    char* phone;
} Person;
typedef int Key;
typedef Person* Value;

typedef struct _SSlot
{
    Key key;
    Value value;
    enum SlotStatus status;
} Slot;

void tbl_init(Table* tbl, HashFunc* f)
{
    int i;

    for(int i = 0; i < MAX_TBL; i++)
    {
        (tbl->tbl[i]).status = EMPTY;
    }

    tbl->hf = f;
}

void tbl_insert(Table* tbl, Key k, Value v)
{
    int hv = tbl->hf(k);
    tbl->tbl[hv].key = k;
    tbl->tbl[hv].value = v;
    tbl->tbl[hv].status = INUSE;
}