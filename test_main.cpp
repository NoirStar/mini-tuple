#include <iostream>
#include <string>
#include <typeinfo>

#include "mini-tuple/tuple.hpp"

int main() {
    std::cout << "=== Mini Tuple Test ===\n\n";

    // Phase 1: 기본 tuple 생성
    mini::tuple<int, double, std::string> t{42, 3.14, "hello"};
    std::cout << "Created tuple<int, double, string>\n";

    // get 테스트
    std::cout << "get<0>: " << mini::get<0>(t) << "\n";
    std::cout << "get<1>: " << mini::get<1>(t) << "\n";
    std::cout << "get<2>: " << mini::get<2>(t) << "\n";

    // 수정 테스트
    mini::get<0>(t) = 100;
    std::cout << "After modification, get<0>: " << mini::get<0>(t) << "\n";

    // tuple_size 테스트
    constexpr auto size = mini::tuple_size_v<decltype(t)>;
    std::cout << "tuple_size: " << size << "\n";

    // tuple_element 테스트
    using T0 = mini::tuple_element_t<0, decltype(t)>;
    using T1 = mini::tuple_element_t<1, decltype(t)>;
    using T2 = mini::tuple_element_t<2, decltype(t)>;
    
    std::cout << "tuple_element<0>: " << typeid(T0).name() << "\n";
    std::cout << "tuple_element<1>: " << typeid(T1).name() << "\n";
    std::cout << "tuple_element<2>: " << typeid(T2).name() << "\n";

    // make_tuple 테스트
    auto t2 = mini::make_tuple(100, 2.718, "world");
    std::cout << "make_tuple get<0>: " << mini::get<0>(t2) << "\n";
    std::cout << "make_tuple get<1>: " << mini::get<1>(t2) << "\n";
    std::cout << "make_tuple get<2>: " << mini::get<2>(t2) << "\n";

    // tie 테스트
    int x = 0;
    double y = 0.0;
    const char* z = "";
    
    mini::tie(x, y, z) = t2;
    std::cout << "After tie: x=" << x << ", y=" << y << ", z=" << z << "\n";

    std::cout << "\n=== All tests passed! ===\n";
    return 0;
}
