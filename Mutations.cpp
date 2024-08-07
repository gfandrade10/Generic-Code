/*
Problem solution - Mutations
https://www.codewars.com/kata/5cb5eb1f03c3ff4778402099/train/cpp
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <optional>
#include <unordered_set>
#include <string>
#include <vector>

#ifndef MAGIC_NUMBER_
    #define MAGIC_NUMBER_ 4
#endif // this represents the number of letters on each word for this game

void clean_word(std::vector<std::string>& word_list, const std::string& word)
{
    for(auto it = word_list.begin(); it != word_list.end();)
    {
        if(*it == word)
            it = word_list.erase(it);
        else 
            it++;
    }
}

std::vector<std::string> sanitize_input(std::vector<std::string> word_list, const std::string& word)
{
    clean_word(word_list, word);

    for(auto it = word_list.begin(); it != word_list.end();)
    {
        std::unordered_set<char> four_letter_set {};
        std::copy((*it).begin(), (*it).end(), std::inserter(four_letter_set, four_letter_set.begin()));

        if(four_letter_set.size() != MAGIC_NUMBER_)
            it = word_list.erase(it);
        else
            it++;
    }

    return word_list;
}

std::optional<std::string> find_next_word(const std::vector<std::string>& word_list, const std::string& word)
{
    auto comp_words = [](const std::string& word1, const std::string& word2) ->bool
    {
        int diff_count {0};

        for(size_t i = 0; i < MAGIC_NUMBER_; i ++)
            diff_count += static_cast<int>((word1[i] != word2[i]));

        if(diff_count == 1)
            return true;
        else 
            return false;
    };    

    for(auto it = word_list.begin(); it != word_list.end(); it++)
    {
        if(comp_words(*it, word))
            return (*it);
    }
    return std::nullopt;
}

int mutations(const std::vector<std::string> &alice, const std::vector<std::string> &bob, std::string word, int turn)
{
    std::vector<std::string>  alice_copy  {sanitize_input(alice, word)};
    std::vector<std::string>  bob_copy    {sanitize_input(bob, word)};
    std::vector<std::string>* loop_list   {(turn == 0) ? &alice_copy : &bob_copy};
    std::vector<std::string>  used_words  {};

    bool alice_success    {false};
    bool bob_success      {false};
    bool first_round_flag {true};

    do
    {
        loop_start:
        std::optional<std::string> next {find_next_word(*loop_list, word)};

        if(next)
        {
            word = *next;
            clean_word(*loop_list, word);
            clean_word((loop_list == &alice_copy ? bob_copy : alice_copy), word);

            used_words.push_back(word);

            if(loop_list == &alice_copy)
                alice_success = true;
            else 
                bob_success = true;
        }
        else
        {
            if(loop_list == &alice_copy)
                alice_success = false;
            else 
                bob_success = false;
        }

        loop_list = (loop_list == &alice_copy ? &bob_copy : &alice_copy);

        if(first_round_flag)
        {
            first_round_flag = false;
            goto loop_start;
        }
    } 
    while (alice_success && bob_success);

    if(!alice_success && !bob_success)
        return -1;
    else 
        return (alice_success) ? 0 : 1;
}

int main()
{
    const std::vector<std::string> alice {"plat", "rend", "bear", "soar", "mare", "pare", "flap", "neat", "clan", "pore"};
    const std::vector<std::string> bob   {"boar", "clap", "mere", "lend", "near", "peat", "pure", "more", "plan", "soap"};
    int result = mutations(alice, bob, "next", 1);
    std::cout << result << "\n\n";
}

#undef MAGIC_NUMBER_
