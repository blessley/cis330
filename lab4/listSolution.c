/*
 * CIS 330: Lab 4
 * Pointers & Copying Structs
 *
 * This file has a struct that implements a List (similar to the list datatype
 * in Python). You should solve as much of problems 1, 2, and 3 as you
 * have time to do. The problems are given in the code below.
 */
#include <stdio.h>
#include <stdlib.h>


// custom List type
typedef struct{
    int  length;
    int *array;
} List;


// load a binary file containing l ints into a List
List* load(char *filename, int l)
{
    FILE *infile = fopen(filename, "rb");

    List* res = malloc(sizeof(List));
    res->array = malloc(sizeof(int) * l);
    res->length = l;

    fread(res->array, sizeof(int), l, infile);
    
    fclose(infile);
    return res;
}


// print List
void print(List *list)
{
    printf("LIST HAS %d INTS:\n", list->length);
    printf("-----------------\n");
    for(int i = 0; i < list->length; i++)
	{
        printf("%d: %d\n", i, (list->array)[i]);
    }
    printf("\n");
}


// adds two Lists, returning a new List
List* plus_list(List *t1, List *t2)
{
    List *res = malloc(sizeof(List));
    res->length = t1->length;
    res->array = malloc(sizeof(int) * res->length);
    for(int i = 0; i < res->length; i++)
    	(res->array)[i] = (t1->array)[i] + (t2->array)[i];
    return res;
}


// add one to every element of a list, returns new list
// FIXME (modifies input list)
List* plus_one(List *list)
{
    List *res = malloc(sizeof(List));
    res->length = list->length;
    //res->array = list->array;
	memcpy(res->array, list->array, sizeof(int)*list->length);
    for(int i = 0; i < res->length; i++)
    	(res->array)[i]++;
    return res;
}


// double every element of a list, returns new list
// FIXME (modifies the input list)
List* times_two(List *list){
    List res;
    res.length = list->length;
    res.array = list->array;
    for(int i = 0; i < res.length; i++){
        (res.array)[i] *= 2;
    }
    return &res;
}


// push_back: puts an int on the end of a List (in place)
void push_back(List *list, int n){
    /*TODO*/
	int newSize = list->length + 1;
	int *newBuffer = malloc(sizeof(int)*newSize);
	memcpy(newBuffer, list->array, sizeof(int)*list->length);
	newBuffer[list->length] = n;	
	list->array = newBuffer;
	list->length = newSize;
}


// pop: removes, and returns, the last element of a List
int pop(List *list){
    /*TODO*/
    return 0;
}


// reverse: reverses a List in place
void reverse(List *list){
    /*TODO*/
}


// reversed: returns a reversed copy of a List
List* reversed(List *list){
    /*TODO*/
    List *res;
    return res;
}


// problem1: using only the functions plus_list, plus_one, and times_two, write
//           a function that calculates 256*list + (list+10) ... that is, it multiplies
//           each element of the input list by 256, adds 10 to each element of the input list,
//           and combines those resulting lists ... you should not alter the input list
//
//           the first three entries of the correct answer are: [524 1295 1295 ...]
List* problem1(List *list){
    List *res;
    return res;
}


// problem2: complete the functions push_back, pop, reverse, and reversed ... you don't
//           have to modify this function
//
//           the first three entries of the correct answer are: [11 5 18 ...]
//           the correct answer has length 12
List* problem2(List *list){
    reverse(list);
    int end = pop(list);
    int l1 = list->length;
    push_back(list, end * l1);
    push_back(list, 5);
    int l2 = list->length;
    push_back(list, l2);
    return reversed(reversed(reversed(list)));
}


int main(int argc, char **argv){
    if(argc != 3){
        printf("Usage: %s <filename> <length>\n", argv[0]);
        exit(1);
    }

    List *t = load(argv[1], atoi(argv[2]));
    printf("loaded list\n");
    print(t);

    List *problem1_result = problem1(t);
    printf("problem1 result");
    print(problem1_result);

    List *problem2_result = problem2(t);
    printf("problem2 result");
    print(problem2_result);

    // problem3: is it possible to make the program memory leak free?
    free(t->array);
    free(t);
    return 0;
}
