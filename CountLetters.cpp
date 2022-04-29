#include <iostream>
#include <map>
#include <utility>
#include <functional>
#include <cctype>

std::map<char, unsigned> count(const std::string& str) 
{	
	if (str.empty()) return {};
	std::map<char, unsigned> res;
	auto func = [](const std::string &str, std::map<char, unsigned> &input)
		-> std::map<char, unsigned> { for (const auto &e:str) 
		if (isalpha(e)) input[e]++; return input; };
	return func(str,res);
}

int main (int argc, char **argv)
{
	std::string input = "guilherme ferraz de andrade";
	std::map<char,unsigned> res = count(input);
	for (const auto &e:res)
		std::cout << e.first << ": " << e.second << "\n";
	std::cout << std::endl;
	return 0;
}