#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::string get_order(const std::string &order) 
{
    if(order.empty()) return "";

    const std::vector<std::string> menu { "burger", "fries", "chicken", "pizza", 
        "sandwich", "onionrings", "milkshake", "coke" 
    };

    auto to_camel_case = [](std::string s) -> std::string { 
        if(s. empty()) return "";
        else {
            s[0] = ::toupper(s[0]);
            return s;
        }
    };

    struct ItemCount {
        std::string item {};
        unsigned count = 0;
    };

    auto listings = [&]() -> std::vector<ItemCount> {
        std::vector<ItemCount> items;
        items.reserve(menu.size());
        for(const auto& it: menu) { items.push_back(ItemCount{to_camel_case(it), 0}); }
        return items;
    }();

    std::string::const_iterator it1 = order.begin();
    std::string::const_iterator it2 = order.begin();
    std::string result{};

    for(; ; ++it2)
    {
        std::string temp(it1, it2);
        if(std::find(menu.begin(), menu.end(), temp) != menu.end()) {
            auto pos = std::find_if(listings.begin(), listings.end(), 
                [&](const ItemCount& i) { return to_camel_case(temp) == i.item; }
            );
            pos->count++;
            it1 = it2;
        }
        if(it2 == order.end()) break;
    }

    for(auto& it: listings) {
        while (it.count) {
            result += it.item + " ";
            it.count--;
        }
    }
    
    result.pop_back();
    return result;
}

int main()
{
    std::string faulty_imput = "milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza";
    std::string order = get_order(faulty_imput);
    std::cout << "Fauly order: " << faulty_imput << "\nProper Order: " << order << "\n\n";
}
