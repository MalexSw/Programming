#include "unity.h"
#include "lib.h"

void setUp() {}

void tearDown() {}

void test_func1() {
    TEST_ASSERT_EQUAL_INT(0, func1(0, 0, 0, 0, 1));   
    TEST_ASSERT_EQUAL_INT(0, func1(0, -1, 0, 0, 1));    
    TEST_ASSERT_EQUAL_INT(0, func1(0, 0, 3, 0, 1));   
    TEST_ASSERT_EQUAL_INT(0, func1(0, 0, 1, 0, 1)); 
    TEST_ASSERT_EQUAL_INT(0, func1(1, -1, 1, 0, 1));
    TEST_ASSERT_EQUAL_INT(0, func1(1, 0, -1, 0, 1));
    TEST_ASSERT_EQUAL_INT(2, func1(1, 1, 1, 1, 1));
}  

void test_func2() {
    TEST_ASSERT_EQUAL_INT(-1, func2(0, 1, 0, 0, 1));  
    TEST_ASSERT_EQUAL_INT(0, func2(0, 0, 0, 1, 1));    
    TEST_ASSERT_EQUAL_INT(0, func2(0, 0, 0, 0, 1));    
    TEST_ASSERT_EQUAL_INT(-3, func2(0, 2, 0, 1, 1));  
    TEST_ASSERT_EQUAL_INT(-1, func2(0, -1, 0, 0, 1)); 
    TEST_ASSERT_EQUAL_INT(0, func2(-1, 0, 0, 11, 1)); 
    TEST_ASSERT_EQUAL_INT(-2, func2(-1, 1, 1, 0, -1));  
}

void test_func3() {
    TEST_ASSERT_EQUAL_INT(1, func3(1, 0, 0, 0));      
    TEST_ASSERT_EQUAL_INT(-1, func3(0, 1, 0, 0));      
    TEST_ASSERT_EQUAL_INT(-3, func3(0, 1, 1, 2));   
    TEST_ASSERT_EQUAL_INT(-1, func3(1, 1, 1, 0));
    TEST_ASSERT_EQUAL_INT(-1, func3(-1, 0, -1, -2));
    TEST_ASSERT_EQUAL_INT(0, func3(1, 1, 1, -1));   
}

void test_func4() {
    TEST_ASSERT_EQUAL_INT(0, func4(1, 0, 0, 1));       
    TEST_ASSERT_EQUAL_INT(0, func4(0, 0, 0, 0));     
    TEST_ASSERT_EQUAL_INT(2, func4(1, 1, 1, 1));   
    TEST_ASSERT_EQUAL_INT(0, func4(-1, 1, 1, 1));
    TEST_ASSERT_EQUAL_INT(0, func4(0, -1, 1, 0));
    TEST_ASSERT_EQUAL_INT(2, func4(0, 1, 1, 0));   
}