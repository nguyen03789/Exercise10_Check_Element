/*
File: Find_Source.c
Author: Phan Trong Nguyen
Date: 06/05/2023
Description:
*/
#include"..\Header/Find_Header.h"
/*
Function: new_Node
Description: Create Node
Input: data of Node
Output: new Node
*/
NODE *new_Node(uint8_t data){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
     return newNode;
}
/*
Function: Init
Description: Create list of Node
Input: Pointer of LIST
Output: None
*/
void Init(LIST *list){
    list->index = 0;
    list->list = NULL;
    list->ptr = NULL;
}
/*
Function: Isempty
Description: Check list is empty or not
Input: Pointer of LIST
Output: 
0: list is empty
1: list isn't empty
*/
bool Isempty(LIST * list){
    return list->index == 0; 
}
/*
Function: Add
Description: Add new Node and Arrange them
Input: 
 + Pointer of LIST
 + number of Node which want to add
 + Data of Node
Output: a list of Node
*/
void Add(LIST *list, int number,...){
    va_list ptr_data;
    va_start(ptr_data,number);
    for(int i = 0; i <number; i++){
        uint8_t temp;
        //Add fist, Arrange later
        NODE *addNode = new_Node(va_arg(ptr_data, int));
        NODE *tempNode;
        if(Isempty(list)){
            list->list = addNode;
        }
        else list->ptr->next = addNode;
        list->ptr = addNode;
        currentNode = addNode;
        list->index++;
        //Arrange
        if(list->index >= 2){
            if(list->ptr->data < list->list->data){
                temp = list->list->data;
                list->list->data = list->ptr->data;
                list->ptr->data = temp;
            }
        }
        if(list->index >= 3) {
            checkNode = list->list->next;
            while (currentNode->data > checkNode->data) checkNode = checkNode->next;
            while(checkNode->data > currentNode->data){
                temp = checkNode->data;
                checkNode->data = currentNode->data;
                currentNode->data = temp;
                checkNode = checkNode->next;
            }
        }
    }
}
/*
Function: Find
Description: Check data is in the list or not
Input: 
 + Pointer of LIST
 + Data of Node
Output: a list of Node
*/
void find(LIST *list, uint8_t data){
    int Start = 0;
    int Center;
    int End = list->index;
    int Find = 3;
    int Button = 1;
    Center = Start + abs(Start - End) / 2 + abs(Start - End) % 2;
    if(Isempty(list)) printf("Notthing to Check\n");
    while(Find == 3){
    int Scan = 1; //  Create Variable Scan to help Pointer checkNode point to the centerNode;
    checkNode = list->list;
    //Split (Scan go from Start to Center to put CheckNode->data is CenterNode)
        while (Scan < Center){
            checkNode = checkNode->next;
            Scan++;
        }
    //check
        if(Center != End){
            if(checkNode->data == data) Find = 1;
            else if (checkNode->data > data){ 
                End = Center;
                Center = Start + abs(Start - End)/2 + abs(Start - End) % 2;
            }
            else if(checkNode->data < data){
                Start = Center;
                Center = Start + abs(Start - End)/2 + abs(Start - End) % 2;
            }
        }
        else{ // The remaining Case 3 Nodes 
        // Case data > CheckNode->data
            if(checkNode->data == data) Find = 1;
            else Find = 0;
            if(checkNode->data < data){
                checkNode = list->list;
            while (Scan < Center - 1){
                checkNode = checkNode->next;
                Scan++;
            }
            if(checkNode->data == data) Find = 1;
            else Find = 0;
            }
        } 
    }
    if(Find == 1) printf("Element %d is in the List\n",data);
    else {
        printf("Element %d isn't in the List\n",data);
        printf("Would you like to add newdata to the list\n");
        printf("1: Yes\n");
        printf("0: No\n");
        scanf("%d",&Button);
        switch (Button){
        case 0:
            break;
        case 1:
        Add(list,data);
        printf("Element %d has been added to the list\n",data);
            break;
        default:
            break;
        }
    }
}
