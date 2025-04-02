#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(MultiplyDecimalTest, Sample1) {
    // Sample Input 1
    // -2.191956222 * -0.683960516 = 1.499211508648530552
    EXPECT_EQ(multiplyDecimal("-2.191956222", "-0.683960516"), "1.499211508648530552");
    
    // -1.291834802 * 3.782364395 = -4.886189959306674790
    EXPECT_EQ(multiplyDecimal("-1.291834802", "3.782364395"), "-4.886189959306674790");
    
    // -1.598010574 * -2.335316422 = 3.731860335991846228
    EXPECT_EQ(multiplyDecimal("-1.598010574", "-2.335316422"), "3.731860335991846228");
}

TEST(MultiplyDecimalTest, Sample2) {
    // Sample Input 2
    EXPECT_EQ(multiplyDecimal("-2.172553565", "-1.244524445"), "2.703796019714396425");
    EXPECT_EQ(multiplyDecimal("-1.657717583", "-1.359125652"), "2.253046490826739116");
    EXPECT_EQ(multiplyDecimal("2.966396874", "-0.280475498"), "-0.832001640500793252");
    EXPECT_EQ(multiplyDecimal("-2.418245262", "-1.999745225"), "4.835874415563373950");
    EXPECT_EQ(multiplyDecimal("2.754341475", "-1.176239263"), "-3.239764586604332925");
    EXPECT_EQ(multiplyDecimal("-1.354440277", "-0.737219668"), "0.998520011335768036");
    EXPECT_EQ(multiplyDecimal("3.677042302", "-0.840169475"), "-3.089338700424131450");
    EXPECT_EQ(multiplyDecimal("-1.401401708", "1.772821560"), "-2.484435162163224480");
    EXPECT_EQ(multiplyDecimal("0.408919935", "-0.554763559"), "-0.226853878486648665");
    EXPECT_EQ(multiplyDecimal("3.867584500", "2.556471486"), "9.887369493945567000");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
