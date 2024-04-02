#pragma once

#include <variant>

#define STRINGIFY(name) #name

template <typename T, typename VARIANT_T>
struct isVariantMember;

template <typename T, typename... ALL_T>
struct isVariantMember<T, std::variant<ALL_T...>> : public std::disjunction<std::is_same<T, ALL_T>...>
{
};