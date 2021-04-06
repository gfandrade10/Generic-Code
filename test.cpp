#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define len 26

std::string Cripto(std::string S){
    std::vector<char> VEC(len);
    std::vector<char> vec(len);
    int index;
    int n = S.length();
    std::vector<char> buffer(n);

    for(int i=0; i<n; i++)
        buffer[i] = S[i];

    for(int i=0; i<len; i++){
        VEC.push_back(i+65);
        vec.push_back(i+97);
    }

    std::reverse(VEC.begin(), VEC.end());
    std::reverse(vec.begin(), vec.end());

    for(int i=0; i<n; i++){
        if(buffer[i] > 64 && buffer[i] < 91){
            index = abs(buffer[i]-65);
            buffer[i] = VEC[index];
        }
        else{
            if(buffer[i] > 96 && buffer[i] < 123){
                index = abs(buffer[i]-97);
                buffer[i] = vec[index];
            }
        }
    }
    std::string result(buffer.begin(), buffer.end());
    return result;
}

int main(){
    std::string word = "Para a direita ou seja para os liberais, tudo ocorreu como planejavam apos o trabalho que tiveram para retirar a esquerda do governo. Agora por um paradoxo do destino cabe a extrema direita, e seu tosco populismo ir levando o povão no bico. Vamos assistir enquanto os varios fatores, inclusive religiosos, mantiem o povo com postura de gado a ser conduzido de acordo com os interesses e circunstancias determinadas pelos donos do poder no Pais";
    std::cout<<word<<"\n"<<Cripto(word)<<"\n\n";

    std::cin.get();
    return 0;
}