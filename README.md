# 🧩 Mini Tuple

**std::tuple 직접 구현하기 - C++ 템플릿 마스터 프로젝트**

`std::tuple`을 밑바닥부터 구현하며 C++ 템플릿의 가장 어려운 기법들을 마스터합니다.

---

## 🎯 프로젝트 목표

`std::tuple`이 어떻게 동작하는지 완벽히 이해하고, 직접 구현할 수 있게 되는 것.

---

## 🔥 배울 템플릿 기법들

| 기법 | 설명 | 난이도 |
|-----|------|--------|
| **재귀 템플릿** | 타입 리스트를 하나씩 처리 | ⭐⭐⭐⭐ |
| **부분 특수화** | 특정 조건에서 다른 구현 | ⭐⭐⭐⭐ |
| **std::index_sequence** | 컴파일 타임 인덱스 생성 | ⭐⭐⭐ |
| **SFINAE / enable_if** | 조건부 오버로드 | ⭐⭐⭐⭐ |
| **Type Traits 구현** | is_same, decay 등 직접 만들기 | ⭐⭐⭐⭐ |
| **EBO (Empty Base Optimization)** | 빈 클래스 최적화 | ⭐⭐⭐⭐⭐ |
| **Perfect Forwarding 심화** | make_tuple, forward_as_tuple | ⭐⭐⭐⭐ |

---

## 📂 프로젝트 구조

```
mini-tuple/
├── include/
│   └── mini-tuple/
│       ├── tuple.hpp           # 핵심 tuple 클래스
│       ├── tuple_element.hpp   # tuple_element, tuple_size
│       ├── get.hpp             # get<I> 구현
│       ├── make_tuple.hpp      # make_tuple, tie, forward_as_tuple
│       ├── tuple_cat.hpp       # tuple 연결
│       ├── apply.hpp           # apply (tuple을 함수 인자로)
│       └── type_traits.hpp     # 필요한 type traits
├── test_main.cpp
├── CMakeLists.txt
└── README.md
```

---

## 🎮 목표 사용법

```cpp
#include "mini-tuple/tuple.hpp"

// 기본 생성
mini::tuple<int, double, std::string> t{42, 3.14, "hello"};

// 요소 접근
auto num = mini::get<0>(t);     // 42
auto str = mini::get<2>(t);     // "hello"

// tuple 크기
constexpr auto size = mini::tuple_size_v<decltype(t)>;  // 3

// 요소 타입
using SecondType = mini::tuple_element_t<1, decltype(t)>;  // double

// make_tuple
auto t2 = mini::make_tuple(1, 2.0, "world");

// tie (참조로 묶기)
int a; double b; std::string c;
mini::tie(a, b, c) = t;

// apply (함수에 전달)
auto sum = mini::apply([](int x, double y, auto s) {
    return x + y;
}, t);

// tuple_cat (연결)
auto t3 = mini::tuple_cat(t, t2);
```

---

## 📖 구현 로드맵

### Phase 1: 기초
1. [ ] `tuple` 클래스 - 재귀 상속으로 저장
2. [ ] `get<I>` - 인덱스로 요소 접근
3. [ ] `tuple_size` - 요소 개수

### Phase 2: 핵심
4. [ ] `tuple_element` - I번째 타입 추출
5. [ ] `make_tuple` - 자동 타입 추론
6. [ ] `tie` - 참조 tuple

### Phase 3: 고급
7. [ ] `apply` - 함수에 언팩
8. [ ] `tuple_cat` - tuple 연결
9. [ ] 비교 연산자 (`==`, `<=>`)

### Phase 4: 최적화
10. [ ] EBO (Empty Base Optimization)
11. [ ] `forward_as_tuple`
12. [ ] `std::tuple`과 호환

---

## 🚀 빌드 및 실행

```bash
mkdir build && cd build
cmake ..
cmake --build .

# Windows
.\Debug\test_tuple.exe

# Linux/macOS
./test_tuple
```

**요구사항:** C++20 지원 컴파일러 (GCC 10+, Clang 13+, MSVC 2019+)

---

## 📜 License

MIT License

---

**Made with 🔥 by NoirStar - Template Metaprogramming Journey**
