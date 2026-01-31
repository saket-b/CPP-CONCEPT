add_test([=[MathTest.Add]=]  [==[/Users/saketbharti/CPP Concept/GTEST/build/math_test]==] [==[--gtest_filter=MathTest.Add]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[MathTest.Add]=]  PROPERTIES DEF_SOURCE_LINE [==[/Users/saketbharti/CPP Concept/GTEST/tests/test_math.cpp:4]==] WORKING_DIRECTORY [==[/Users/saketbharti/CPP Concept/GTEST/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  math_test_TESTS MathTest.Add)
