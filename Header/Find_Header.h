/*
File: Find_Header.h
Author: Phan Trong Nguyen
Date: 06/05/2023
Description: 
*/
#ifndef _Find_
#define _Find_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct NODE
{
    uint8_t data;
    struct NODE *next;
}NODE;

typedef struct 
{
    NODE *list;
    NODE *ptr;
    int index;
}LIST;

NODE *currentNode;
NODE *checkNode;
NODE *centerNode;

//Create Node
NODE *new_Node(uint8_t data);
//Create List
void Init(LIST *list);
//Bool Empty
bool Isempty(LIST * list);

//Function to add newNode and Arrange
void Add(LIST *list, int number, ...);

void find(LIST *list, uint8_t data);


#endif