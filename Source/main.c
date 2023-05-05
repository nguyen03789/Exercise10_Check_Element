/*
File: main.c
Author: Phan Trong Nguyen
Date: 06/05/2023
Description:
*/
#include"Find_Source.c"

int main(int argc, char const *argv[]){
    LIST a;
    Init(&a);
    Add(&a,12,1,2,7,6,4,15,12,16,3,5,9,8);
    find(&a,8);
    find(&a,10);
    find(&a,10);
    return 0;
}






