#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "backtracking.h"


/*****************************************************************************************
 ************************** Local Functions **********************************************
******************************************************************************************/

static void printSubsetHelper( char * arr, char * chosen, int size );
static void InsertAndArrageElement(char * inputArr, char ts, int pos, int size);
static void RemoveAndArrageElement(char * inputArr, int pos, int size);
static void PrintArrayElement(char * ipArr, int size);

static void PrintAllBinaryHelper(char * str, int digit);


/*****************************************************************************************
 ************************** GLOBAL VARIABLES *********************************************
******************************************************************************************/



/******************************************************************************************/


/*****************************************************************************************
 ************************** Global Functions *********************************************
******************************************************************************************/

void printSubset(char * MainArr, int size)
{
    char arrMod[size];
    char chosenNew[size];
    
    for(int i = 0; i < size; i++)
        arrMod[i] = MainArr[i];
        
    printSubsetHelper(arrMod, chosenNew, size);
    
}

void PrintAllBinary(int digit)
{
    char str[digit+1];
    str[digit] = '\0';
    PrintAllBinaryHelper(str, digit);
}



/*****************************************************************************************
 ************************** Local Functions *********************************************
******************************************************************************************/

static void PrintArrayElement(char * ipArr, int size)
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


static void RemoveAndArrageElement(char * inputArr, int pos, int size)
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

static void InsertAndArrageElement(char * inputArr, char ts, int pos, int size)
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


static void printSubsetHelper( char * arr, char * chosen, int size )
{    
    
    static int chsCnt = 0;
    
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


static void PrintAllBinaryHelper(char * str, int digit)
{
    static int cnt = digit;
    
    if(digit == 0)
        printf("%s\n", str);
    else
    {
        str[cnt-digit] = '0';    
        PrintAllBinaryHelper(str, digit-1);
        str[cnt-digit] = '1';    
        PrintAllBinaryHelper(str, digit-1);   
    }
}
