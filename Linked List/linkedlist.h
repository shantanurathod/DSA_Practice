#pragma once
#include <cstdlib>
#include <iostream>
constexpr char ENDL = '\n';


struct Node
{
    int data;
    Node* next;
};

void insertFront(Node** myhead, int newData);
void insert(Node** headref, int newData);
void insert(Node* temp, int newData, int pos, Node** myhead);
void printList(Node * temp);
void deleteNode(Node ** myhead, int pos);
void overwrite(Node * temp,int poa, int newData);
Node * build(int n);