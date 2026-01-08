#pragma once

namespace mini {

// 기본 템플릿 (variadic)
template<typename... Ts>
class tuple;

// get 함수 전방 선언
template<size_t I, typename Head, typename... Tail>
auto& get(tuple<Head, Tail...>& t);

// 재귀 케이스: Head + Tail...
template<typename Head, typename... Tail>
class tuple<Head, Tail...> : public tuple<Tail...> {
private:
    Head value_;

public:
    tuple(Head h, Tail... t) 
        : tuple<Tail...>(t...), value_(h)
    {}
    
    // friend 선언 (다른 이름 사용)
    template<size_t I, typename H, typename... T>
    friend auto& get(tuple<H, T...>& t);
};

// 종료 조건: 빈 tuple
template<>
class tuple<> {};

// get 구현
template<size_t I, typename Head, typename... Tail>
auto& get(tuple<Head, Tail...>& t) {
    if constexpr (I == 0) {
        return t.value_;
    } else {
        return get<I-1>(static_cast<tuple<Tail...>&>(t));
    }
}

// tuple_size
template<typename T>
struct tuple_size;

template<typename... Ts>
struct tuple_size<tuple<Ts...>> {
    static constexpr size_t value = sizeof...(Ts);
};

template<typename T>
inline constexpr size_t tuple_size_v = tuple_size<T>::value;

}  // namespace mini
