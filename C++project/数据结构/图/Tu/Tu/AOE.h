#pragma once
#include<stdio.h>
#include<iostream>
#include<stack>
#include<deque>
#include"Tu1.h"

//Õÿ∆À≈≈–Ú1£®À≥–Ú∂—’ª£©
void TopSort(AdjGraph* G);
//Õÿ∆À≈≈–Ú2£®À≥–Ú∂”¡–£©
deque<int> TopSort2(AdjGraph* G);
//πÿº¸¬∑æ∂
void CriticalPath(AdjGraph* G, deque<int> qu);