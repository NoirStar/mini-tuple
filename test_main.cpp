#include <iostream>
#include <string>

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

    std::cout << "\n=== All tests passed! ===\n";
    return 0;
}
