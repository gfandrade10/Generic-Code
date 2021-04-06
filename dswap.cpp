#include <iostream>
#include <string>
#include <string.h>

class swapper{
    private:
        const std::string phrase;
        char c1;
        char c2;

    public:
        swapper(std::string A, char B, char C)
            : phrase(A), c1(B), c2(C) {};

        ~swapper(){
            std::cout<<"\nEnd of program\n\n";
            std::cin.get();
        }

        std::string doubleSwap(){
            int n = phrase.length();
            std::string buffer = phrase;
            for (int i=0; i<n; i++){
                if(buffer[i] == c1){
                    buffer[i] = c2;
                }
                else{
                    if(buffer[i] == c2){
                        buffer[i] = c1;
                    }
                }
            }
            return buffer;
        }

        void print(){
            std::cout<<"Source data:\n";
            std::cout<<phrase<<", "<<c1<<", "<<c2<<std::endl;
        }
};

int main(){
    swapper *obj = new swapper("BOM DIA SEUS PINOS", 'I', 'O');
    obj->print();
    std::string result = obj->doubleSwap();
    std::cout<<"\nResult:\n"<<result<<"\n";
    delete(obj);

    return 0;
}