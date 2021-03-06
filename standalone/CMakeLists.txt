cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("CppPlay")

add_library(
        patterns
        src/patterns/creational/builder/telescoping/Person.cpp
        src/patterns/creational/factory_method/AbstractPizza.cpp
        src/patterns/creational/factory_method/NyPizza.cpp
        src/patterns/creational/factory_method/ItalianPizza.cpp
        src/patterns/creational/factory_method/PizzaFactory.cpp
)

#set(CXXFLAGS ${CXXFLAGS} -std=c++2a)
add_compile_options(-std=c++2a)
message("Compiler ${CMAKE_CXX_COMPILER} version ${CMAKE_CXX_COMPILER_VERSION}")

add_executable(main1 src/basics/01_hello.cpp src/basics/20_vacabluary.cpp)
add_executable(main2 src/basics/02_type.cpp)
add_executable(main6 src/basics/06_struct.cpp)
add_executable(main7 src/basics/07_class.cpp)
add_executable(main9 src/basics/09_exceptions.cpp)
add_executable(main10 src/basics/10_asserts.cpp)
add_executable(main12 src/basics/12_binding.cpp)
add_executable(main13 src/basics/13_container.cpp)
add_executable(main14 src/basics/14_casting.cpp)
add_executable(main15 src/basics/15_inheritance.cpp)
add_executable(main16 src/basics/16_cstring.cpp)
add_executable(main17 src/basics/17_array_allocation.cpp)
add_executable(main18 src/basics/18_smart_pointers.cpp)
add_executable(main19 src/basics/19_strings.cpp)
add_executable(main21 src/basics/21_templates.cpp)
add_executable(main22 src/basics/22_lambdas.cpp)
add_executable(main23 src/basics/23_decltype.cpp)
add_executable(main24 src/basics/24_var_array.cpp)
add_executable(main25 src/basics/25_rvalue_reference.cpp)
add_executable(main26 src/basics/26_move.cpp)
add_executable(main28 src/basics/28_deduction.cpp)
add_executable(main29 src/basics/29_binding.cpp)
add_executable(main30 src/basics/30_constexp_if.cpp)
add_executable(main31 src/basics/31_filesystem.cpp)
add_executable(main32 src/basics/32_folding.cpp)
add_executable(main33 src/basics/33_inline.cpp)
add_executable(main34 src/basics/34_enable_shared_from_this.cpp)
add_executable(main35 src/basics/35_empty_base_optimization.cpp)
add_executable(main37 src/basics/37_virtual.cpp)

add_executable(exers1 src/exers/SharedPtr.cpp)

add_executable(builder src/patterns/creational/builder/BuildeTest.cpp)
add_executable(factory_method src/patterns/creational/factory_method/FactoryMethodTest.cpp)

add_executable(language_01 src/language/01_namespace.cpp)
add_executable(language_02 src/language/02_literals.cpp)
add_executable(language_03 src/language/03_enums.cpp)
add_executable(language_04 src/language/04_conditional.cpp)
add_executable(language_05 src/language/05_spaceship_comparison.cpp)
add_executable(language_06 src/language/06_attributes.cpp)
add_executable(language_07 src/language/07_c_arrays.cpp)
add_executable(language_08 src/language/08_arrays.cpp)
add_executable(language_09 src/language/09_vectors.cpp)
add_executable(language_10 src/language/10_pairs.cpp)
add_executable(language_11 src/language/11_optional.cpp)
add_executable(language_12 src/language/12_initializer_list.cpp)
add_executable(language_13 src/language/13_raw_pointers.cpp)
add_executable(language_14 src/language/14_const.cpp)
add_executable(language_15 src/language/15_constexpr.cpp)
add_executable(language_16 src/language/16_references.cpp)
add_executable(language_17 src/language/17_type_alias.cpp)

target_include_directories(
        patterns
        PUBLIC
        src/patterns/common
        src/patterns/creational/builder/telescoping
        src/patterns/creational/factory_method
)

target_link_libraries(
        builder
        patterns
)

target_link_libraries(
        factory_method
        patterns
)