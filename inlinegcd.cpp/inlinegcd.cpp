// inlinegcd.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>


using namespace std;
int ASMGCD(int x, int y);
int main()
{
    int x, y;
    cout << "Enter Two numbers:\n";
    cin >> x >> y;
 
    cout << "greatest common divisor is : " << ASMGCD(x,y);
    return 0;
}


int ASMGCD(int x, int y)
{
    
    int n;
    __asm {
    IF01:
        push eax
        push ebx
        mov eax, x;
        cmp eax, 0;
        jg ENDIF01;
        neg eax; // absolute value
        mov x, eax;
    ENDIF01:
    IF02:
        mov eax, y;
        cmp eax, 0;
        jg ENDIF02;
        neg eax; // absolute value
        mov y, eax;
    ENDIF02:
    DO01:
        mov eax, x; // numerator
        mov ebx, y; // a reg used for denom
        sub edx, edx; // zero dx
        idiv ebx; // signed integer divide
        mov n, edx; // remainder
        mov ebx, y;
        xchg ebx, x; // x = y
        mov ebx, n;
        xchg ebx, y; // y = n;
        mov ebx, y;
        cmp y, 0;
        jg DO01; // while (y > 0)
        
        pop eax
        pop ebx
    DOEND01:
        
        
    }
    return x;

    
}




