#include <iostream>
#include <vector>

typedef struct{
    char letter;
    int count = 0;
}Map;

std::vector<Map> LetterPool(std::string input){
    Map buffer;
    std::vector<Map> Pool;
    bool flag;
    for(int i=0; i<(int)input.length(); i++){
        flag = true;
        for(int j=0; j<(int)Pool.size(); j++){
            if(Pool[j].letter == input[i] && input[i] != ' '){
                Pool[j].count++;
                flag = false;
            }
        }
        if(flag && input[i] != ' '){
            buffer.letter = input[i];
            buffer.count = 1;
            Pool.push_back(buffer);
        }
    }
    return Pool;
}

bool canBuild(std::string str1, std::string str2) {
    std::vector<Map> M1, M2;
    M1 = LetterPool(str1);
    M2 = LetterPool(str2);
    for(int i=0; i<(int)M1.size(); i++){
        for (int j=0; j<(int)M2.size(); j++){
            if(M1[i].letter == M2[j].letter){
                if(M1[i].count > M2[j].count)
                    return false;
            }
        }
    }
	return true;
}

int main(){
   
    bool flag = canBuild("skin man i", "man in mask");
    std::cout<< flag << std::endl;

    std::cin.get();
    return 0;
}