#include <iostream>
#include <vector>

typedef struct{
    char letter;
    int count = 0;
}Map;

std::vector<Map> LetterPool(std::vector<std::string> input){
    Map buffer;
    std::vector<Map> Pool;
    bool flag;
    for(int i=0; i<(int)input.size(); i++){
        flag = true;
        for(int j=0; j<(int)Pool.size(); j++){
            if(Pool[j].letter == input[i][0] && input[i][0] != ' '){
                Pool[j].count++;
                flag = false;
            }
        }
        if(flag && input[i][0] != ' '){
            buffer.letter = input[i][0];
            buffer.count = 1;
            Pool.push_back(buffer);
        }
    }
    for (const auto& a:Pool)
        std::cout << a.letter << " " << a.count << std::endl;
    return Pool;
}

std::string majorityVote(std::vector<std::string> arr) {
    std::vector<Map> Pool = LetterPool(arr);
    char buffer = 'Z';
    int max = 0;
    for(const auto& a:Pool){
        if(a.count > max){
            max = a.count;
            buffer = a.letter;
        }
    }
    int count = 0;
    for(const auto& a:Pool){
        if(max == a.count)
            count++;
    }
    if(count == 1)
          return std::string(1,buffer);
    else
        return "None";	
}

int main(){
    std::vector<Map> Pool;
    std::vector<std::string> input = {"A", "A", "A", "B", "C", "A"};
    std::string Res = majorityVote(input);
    std::cout << Res << std::endl;

    std::cin.get();
    return 0;
}