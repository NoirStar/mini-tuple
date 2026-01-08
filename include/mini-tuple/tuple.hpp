#pragma once
#include <type_traits>
#include <utility>

namespace mini {

// 기본 템플릿 (variadic)
template<typename... Ts>
class tuple;

// get 함수 전방 선언
template<size_t I, typename Head, typename... Tail>
auto& get(tuple<Head, Tail...>& t);

template<size_t I, typename Head, typename... Tail>
const auto& get(const tuple<Head, Tail...>& t);

// 재귀 케이스: Head + Tail...
template<typename Head, typename... Tail>
class tuple<Head, Tail...> : public tuple<Tail...> {
private:
    Head value_;

    // 재귀적으로 대입하는 헬퍼
    template<size_t... Is, typename... Us>
    void assign_impl(std::index_sequence<Is...>, const tuple<Us...>& other) {
        ((get<Is>(*this) = get<Is>(other)), ...);
    }

public:
    tuple(Head h, Tail... t) 
        : tuple<Tail...>(t...), value_(h)
    {}

    // 다른 tuple 대입
    template<typename... Us>
    tuple& operator=(const tuple<Us...>& other) {
        assign_impl(std::index_sequence_for<Head, Tail...>{}, other);
        return *this;
    }

    // friend 선언 (다른 이름 사용)
    template<size_t I, typename H, typename... T>
    friend auto& get(tuple<H, T...>& t);
    
    template<size_t I, typename H, typename... T>
    friend const auto& get(const tuple<H, T...>& t);
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

// get const 버전
template<size_t I, typename Head, typename... Tail>
const auto& get(const tuple<Head, Tail...>& t) {
    if constexpr (I == 0) {
        return t.value_;
    } else {
        return get<I-1>(static_cast<const tuple<Tail...>&>(t));
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

// tuple_element
template<size_t I, typename T>
struct tuple_element;

template<size_t I, typename Head, typename... Tail>
struct tuple_element<I, tuple<Head, Tail...>> {
    using type = typename tuple_element<I-1, tuple<Tail...>>::type;
};

template<typename Head, typename... Tail>
struct tuple_element<0, tuple<Head, Tail...>> {
    using type = Head;
};

template<size_t I, typename T>
using tuple_element_t = typename tuple_element<I, T>::type;

template<typename... Args>
auto make_tuple(Args&&... args) {
    return tuple<std::decay_t<Args>...>(std::forward<Args>(args)...);
};

template<typename... Args>
auto tie(Args&... args) {      // 참조로 받음!
    return tuple<Args&...>(args...);  // 참조 tuple 반환!
}

}  // namespace mini
