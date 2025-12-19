#include <cstddef>
#include <fmt/base.h>

template<size_t N>
class SomeStorage
{
    public:
    constexpr SomeStorage()
    {
        for(size_t i = 1; i<= N; ++i)
            arr[i-1] = (int)i;
    }

    ~SomeStorage() { fmt::println("Object deleted.\n"); }

    int& operator[](size_t pos) { return arr[pos]; }
    
    struct iterator
    {
        using value_type = int;
        using pointer = int*;
        using reference = int&;
        
        pointer ptr = nullptr;

        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }
        iterator& operator++() { ptr += 1; return *this; }
        iterator& operator--() { ptr -= 1; return *this; }
        bool operator!=(const iterator& it) const { return ptr != it.ptr; }
        bool operator==(const iterator& it) const { return ptr == it.ptr; }

        iterator(pointer p) : ptr(p) {}
        iterator(const iterator& it) = default;
        iterator(iterator&& it) = default;
        iterator& operator=(const iterator& it) = default;
        iterator& operator=(iterator&& it) = default;
        iterator() = default;
    };

    iterator begin() { return iterator(arr) ;}
    iterator end() { return iterator(arr + N) ;}

    int arr[N];
};

int main()
{
    constexpr size_t N = 10;
    SomeStorage<N> arr;

    for(auto it = arr.begin(); it != arr.end(); ++it)
        fmt::print("{}  ", *it);
    fmt::println("");
}
