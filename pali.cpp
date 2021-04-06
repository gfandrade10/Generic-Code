#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define GetLine(x) (std::getline(std::cin,x))

typedef std::string String;

void AssignString(String Ref, String& Destiny){
    Destiny = Ref;
    std::reverse(Destiny.begin(), Destiny.end());
}

bool StrCompare(String S1, String S2){
    int n = S1.length();
    char Name1[n], Name2[n];
    for (int i=0; i<n; i++){
        Name1[i] = S1[i];
        Name2[i] = S2[i];
    }
    if(strcasecmp(Name1,Name2)==0)
        return TRUE;
    else
        return FALSE;
}

void Palindrome(String name, bool flag){
    if(flag)
        std::cout<<"The word '"<<name<<"' is palindrome.\n";
    else
        std::cout<<"The word '"<<name<<"' is not palindrome.\n";
}

int main(){
    String name, rev;
    std::cout<<"Enter a word: ";
    GetLine(name);
    AssignString(name, rev);
    std::cout<<"\nOriginal word: "<<name;
    std::cout<<"\nReversed word: "<<rev<<"\n\n";
    Palindrome(name,StrCompare(name, rev));
    getch();

    return 0;
}

