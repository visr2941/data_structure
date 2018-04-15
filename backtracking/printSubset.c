/* To print all the subsets of the given character set using "backtracking" algorithm*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int chsCnt = 0;

void printSubset(char * MainArr, int size);
void printSubsetHelper( char * arr, char * chosen, int size );
void InsertAndArrageElement(char * inputArr, char ts, int pos, int size);
void RemoveAndArrageElement(char * inputArr, int pos, int size);
void PrintArrayElement(char * ipArr, int size);


int main()
{
    char MainArr[5] = {'M', 'Y', 'Z', 'W', 'X'};

    printSubset(MainArr, 5);

    return 0;
}


void PrintArrayElement(char * ipArr, int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%c, ", ipArr[i]);
        //printf("ipArr[%d] %c, size %d\n", i, ipArr[i], size);
    }
    if(size==0)
        printf("}\n");
    else
        printf("\b\b}\n");
}


void RemoveAndArrageElement(char * inputArr, int pos, int size)
{
    int temp = pos;
    bool flag;
    
    while(temp < size)
    {
        //printf("check\n");
        inputArr[temp] = inputArr[temp+1];
        temp++;
        flag = 1;
    }
    if(flag)
        inputArr[temp] = 0;
}

void InsertAndArrageElement(char * inputArr, char ts, int pos, int size)
{
    int temp = size;
    bool flag;
    
    while(temp > pos)
    {
        inputArr[temp] = inputArr[temp-1];
        temp--;
        flag = 1;
    }
    
    inputArr[temp] = ts;    
}


void printSubsetHelper( char * arr, char * chosen, int size )
{    
    if (arr[0]==0)
    {
        PrintArrayElement(chosen, size);
    }
    else
    {
        char ts = arr[0];
        RemoveAndArrageElement(arr, 0, size);
        
        printSubsetHelper(arr, chosen, size-1);
        
        chosen[chsCnt] = ts;
        chsCnt++;

        printSubsetHelper(arr, chosen, size);

        InsertAndArrageElement(arr, ts, 0, size+1);
        size = size+ 1;

        RemoveAndArrageElement(chosen, chsCnt-1, size);
        chsCnt--;
    }

}

void printSubset(char * MainArr, int size)
{
    char arrMod[size];
    char chosenNew[size];
    
    for(int i = 0; i < size; i++)
        arrMod[i] = MainArr[i];
        
    printSubsetHelper(arrMod, chosenNew, size);
    
}