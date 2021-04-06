#include <iostream>
#include <vector>
#include <string>
#include <string.h>

typedef std::string String;
typedef std::vector<String> VectorS;

String Splitter(const String& name){
    const int n = name.length();
    char buffer[n];
    for (int i=0; i<n; i++)        
        buffer[i] = name[i];
    char* TokPtr;
    std::vector<const char*> _buffer;
    TokPtr = strtok(buffer, " ");
    while (TokPtr != NULL){
        _buffer.push_back(TokPtr);
        TokPtr = strtok(NULL, " ");
    }
    std::vector<char> final(5);
    final[0] = _buffer[0][0];
    final[1] = '.';
    final[2] = ' ';
    final[3] = _buffer[1][0];
    final[4] = '.';
    String result(final.begin(),final.end());
    return result;
}

VectorS Initialize(const VectorS& names){
    const int n = names.size();
    VectorS result;
    for(int i=0; i<n; i++)
        result.push_back(Splitter(names[i]));
    return result;
}

int main(){
    const VectorS Names = {"Szabela Daylê", "Guilherme Andrade", "Pedro Ferraz", "Anthony Toks"};
    VectorS Result = Initialize(Names);
    for(int i=0; i<(int)Result.size(); i++)
        std::cout<<Result[i]<<"\n";
    std::cout<<std::endl;
    std::cin.get();
    return 0;
}


