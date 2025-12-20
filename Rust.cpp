#include <algorithm>
#include <cstddef>
#include <fmt/base.h>
#include <initializer_list>
#include <random>
#include <utility>
#include <vector>
#include <concepts>

template<typename T>
concept Natural = std::unsigned_integral<T>;

template <Natural T>
class Chainable
{
    public:
    //defaults
    Chainable() = default;
    Chainable(const Chainable&) = default;
    Chainable(Chainable&&) = default;
    Chainable& operator=(Chainable&&) = default;
    Chainable& operator=(const Chainable&) = default;

    //non-default constructors
    Chainable(const T& t) { v.reserve(t); }
    Chainable(std::vector<T>&& vec) : v(std::move(vec)) {}
    Chainable(std::initializer_list<T> ls)
    {
        v.reserve(ls.size());
        for(const auto& it: ls) { v.push_back(it); }
    }

    //destructor
    ~Chainable() = default;

    //funcs
    template<typename Func>
    requires std::invocable<Func&, T&>
    auto for_each(Func f) && -> Chainable<T>
    {
        for (auto& it : v) { f(it); }
        return std::move(*this);
    }

    template<typename Func>
    requires std::invocable<Func&, T&>
    auto map(Func f) && -> Chainable<std::invoke_result_t<Func&, T&>>
    {
        using U = std::invoke_result_t<Func&, T&>;

        Chainable<U> out(v.size());
        for (auto& it : v)
            out.get_v().push_back(f(it));

        return std::move(out);
    }

    template<typename Func>
    requires std::predicate<Func&, T&>
    auto filter(Func f) && -> Chainable<T>
    {
        std::vector<T> dummy;
        dummy.reserve(v.size());
        for(auto& it: v)
        {
            if(f(it)) { 
                dummy.push_back(std::move(it)); 
            }
        }
        v = std::move(dummy);
        return std::move(*this);
    }

    auto collect() && -> std::vector<T>
    {
        return std::move(this->v);        
    }

    private:
    std::vector<T>& get_v() & { return v; }
    std::vector<T> v{};
};

int main()
{
    static std::random_device rd{};
    static std::mt19937 seed{rd()};
    static std::uniform_int_distribution<> gen(1,100);

    auto random_vec_gen = [](size_t&& size) {
        std::vector<size_t> sz;
        sz.reserve(size);
        for(size_t i = 0; i < size; ++i) { sz.push_back(static_cast<size_t>(gen(seed))); }
        return sz;
    };

    auto v = Chainable{random_vec_gen(15)}
        .filter([](size_t& s) { return s%2 == 0; })
        .collect();

    for(const auto& it: v) 
        fmt::print("{} ", it);

    fmt::println("\n");
}
