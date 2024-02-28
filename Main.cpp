#include <rt/Convert.hpp>
#include <rt/FixedString.hpp>
#include <rt/MemberCount.hpp>
#include <rt/Name.hpp>
#include <rt/TConvert.hpp>
#include <rt/Traits.hpp>
#include <rt/Tuple.hpp>
#include <rt/Util.hpp>
#include <rt/Visit.hpp>

#include <iostream>

struct Foo { int i; float f; char c; };

struct Bar { int is[3]; float f; };

struct S10a { int a; int b; int c; int d; int e; int f; int g; int h; int i; int j; };

struct S10b { int _0; int _1; int _2; int _3; int _4; int _5; int _6; int _7; int _8; int _9; };

enum Enum { A = 1, BB = 3, CCC = 5, DDDD = 7, MIN = A, MAX = DDDD };

template <auto>
using Swallow = void const*;

template <size_t vIdx>
struct Getter
{
    template <typename... Args>
    constexpr decltype(auto) operator()(Args&&... args)
    {
        return [&] <size_t... Is> (std::index_sequence<Is...>) -> decltype(auto) {
            return [](Swallow<Is>..., auto element, ...) -> decltype(auto) {
                return *element;
            }(&args...);
        }(std::make_index_sequence<vIdx>{});
    }
};

template <typename T>
constexpr void print_members(T&& t)
{
    [&] <size_t... Is> (std::index_sequence<Is...>) {
        ((std::cout << rt::get_nth_member_name<std::remove_reference_t<T>, Is>() << '=' << rt::visit(Getter<Is>{}, t) << ' '), ...);
    }(std::make_index_sequence<rt::get_member_count<std::remove_reference_t<T>>()>{});
    std::cout << '\n';
}

int main()
{
    S10a s10a{};

    auto tuple = rt::tconvert<rt::Tuple>(s10a);
    auto s10b = rt::convert<S10b>(s10a);

    print_members(s10a); // a=0 b=0 c=0 d=0 e=0 f=0 g=0 h=0 i=0 j=0
    print_members(s10b); // _0=0 _1=0 _2=0 _3=0 _4=0 _5=0 _6=0 _7=0 _8=0 _9=0
    print_members(tuple); // t0=0 t1=0 t2=0 t3=0 t4=0 t5=0 t6=0 t7=0 t8=0 t9=0
    std::cout << '\n';
    std::cout << rt::get_type_name<decltype(rt::tconvert<rt::Tuple>(Foo{}))>() << '\n'; // Tuple<int, float, char>
    std::cout << rt::get_type_name<decltype(rt::tconvert<rt::Tuple>(Bar{}))>() << '\n'; // Tuple<int[3], float>
    std::cout << rt::get_type_name<decltype(rt::tconvert<rt::Tuple>(S10a{}))>() << '\n'; // Tuple<int, int, int, int, int, int, int, int, int, int>
    std::cout << rt::get_type_name<decltype(rt::tconvert<rt::Tuple>(S10b{}))>() << '\n'; // Tuple<int, int, int, int, int, int, int, int, int, int>
    std::cout << '\n';
    std::cout << rt::get_enum_name<Enum, Enum::MIN, Enum::MAX>(Enum::A) << '\n'; // A
    std::cout << rt::get_enum_name<Enum, Enum::MIN, Enum::MAX>(Enum::BB) << '\n'; // BB
    std::cout << rt::get_enum_name<Enum, Enum::MIN, Enum::MAX>(Enum::CCC) << '\n'; // CCC
    std::cout << rt::get_enum_name<Enum, Enum::MIN, Enum::MAX>(Enum::DDDD) << '\n'; // DDDD
}
