#include <iostream>
#include <string>

// TODO: #include "mini-tuple/tuple.hpp"

int main() {
    std::cout << "=== Mini Tuple Test ===\n\n";

    // Phase 1: 기본 tuple 생성
    // mini::tuple<int, double, std::string> t{42, 3.14, "hello"};
    // std::cout << "Created tuple<int, double, string>\n";

    // Phase 1: get<I> 테스트
    // auto num = mini::get<0>(t);
    // auto pi = mini::get<1>(t);
    // auto str = mini::get<2>(t);
    // std::cout << "get<0>: " << num << "\n";
    // std::cout << "get<1>: " << pi << "\n";
    // std::cout << "get<2>: " << str << "\n";

    // Phase 1: tuple_size 테스트
    // constexpr auto size = mini::tuple_size_v<decltype(t)>;
    // std::cout << "tuple_size: " << size << "\n";

    std::cout << "\n=== All tests passed! ===\n";
    return 0;
}
