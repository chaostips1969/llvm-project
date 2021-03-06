// RUN: %clang_cc1 -std=c++14 -fconcepts-ts -x c++ %s -verify

// Test parsing of constraint-expressions in cases where the grammar is
// ambiguous with the expectation that the longest token sequence which matches
// the syntax is consumed without backtracking.

// type-specifier-seq in conversion-type-id
template <typename T> requires T::operator short
unsigned int foo(); // expected-error {{C++ requires a type specifier for all declarations}}