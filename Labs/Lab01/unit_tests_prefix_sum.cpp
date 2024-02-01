#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


#include "prefix_sum.h"


int test_ary_0[] = {};
int test_ary_1[] = {1,-2};
int test_ary_2[] = {16};
int test_ary_3[] = {-1};
int test_ary_4[] = {5,19,-18,1,2,4};
int test_ary_5[] = {23,4,-25,1,3,-8,-2}; 
int test_ary_6[] = {5,6,4,-10,-5};



TEST_CASE("prefix sum")
{
    CHECK_EQ(prefix_sum(test_ary_0,0),0);  
    CHECK_EQ(prefix_sum(test_ary_1,sizeof(test_ary_1)/sizeof(test_ary_1[0])),-1);

    CHECK_EQ(prefix_sum(test_ary_6,5),0); 
    CHECK_EQ(prefix_sum(test_ary_6,5),0); 

};


TEST_CASE("bool")
{
    SUBCASE("non-negative"){ //test case checks edge case 
        CHECK_FALSE(non_neg_prefix_sum(test_ary_0,0));
    };

    SUBCASE("non-positive"){  //test case checks edge case
        CHECK_FALSE(non_positive_prefix_sum(test_ary_0,0));
    };
}


TEST_CASE("length==1")
{

    CHECK_EQ(prefix_sum(test_ary_2,1),16);
    SUBCASE("length==1"){ //test case checks edge case 
        CHECK_FALSE(non_neg_prefix_sum(test_ary_2,1));   //16
    };

    CHECK_EQ(prefix_sum(test_ary_3,1),-1);
    SUBCASE("length==1"){ //test case checks edge case 
        CHECK_FALSE(non_positive_prefix_sum(test_ary_3,1));  //-1
    };

}

TEST_CASE("testing value")
{
    CHECK_EQ(prefix_sum(test_ary_4,6),13);
    CHECK_EQ(prefix_sum(test_ary_5,7),-4);
    
    SUBCASE("non-negative"){ 
        CHECK_FALSE(non_neg_prefix_sum(test_ary_4,6));
    };
    
}
