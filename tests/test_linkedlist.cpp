#include <gtest/gtest.h>
#include "../LinkedList.h"

const float TOLERANCE = 0.001f; 
const double DOUBLE_TOLERANCE = 1e-7;

TEST(LinkedListTest, testLengthInt) {
    LinkedList<int> ll;
    EXPECT_EQ(ll.length(), 0);
    ll.append(5);
    ll.append(5);
    ll.append(5);
    ll.append(5);
    EXPECT_EQ(ll.length(), 4);
    ll.remove(5);
    EXPECT_EQ(ll.length(), 3);

}

TEST(LinkedListTest, testPrependInt) {
    LinkedList<int> ll;
    ll.append(5);
    EXPECT_EQ(ll.getHeadData(), 5);
    ll.prepend(4);
    EXPECT_EQ(ll.getHeadData(), 4);
    ll.prepend(3);
    EXPECT_EQ(ll.getHeadData(), 3);
    ll.append(4);
    EXPECT_EQ(ll.getHeadData(), 3);
    LinkedList<int> ll2(11);
    ll2.append(5);
    EXPECT_EQ(ll2.getHeadData(), 11);
}

TEST(LinkedListTest, testContainsInt) {
    LinkedList<int> ll;
    ll.append(5);
    EXPECT_EQ(ll.contains(5), true);
    ll.prepend(4);
    EXPECT_EQ(ll.contains(7), false);
    ll.remove(5);
    EXPECT_EQ(ll.contains(5), false);
    ll.prepend(3);
    EXPECT_EQ(ll.contains(3), true);
}

TEST(LinkedListTest, testEmptyInt) {
    LinkedList<int> ll;
    EXPECT_EQ(ll.isEmpty(), true);
    ll.append(5);
    EXPECT_EQ(ll.isEmpty(), false);
    ll.clear();
    EXPECT_EQ(ll.isEmpty(), true);
    ll.prepend(6);
    ll.append(7);
    EXPECT_EQ(ll.isEmpty(), false);
}

TEST(LinkedListTest, testIndexingInt) {
    LinkedList<int> ll;
    ll.append(1);
    ll.append(3);
    ll.append(4);
    EXPECT_EQ(ll[0], 1);
    EXPECT_EQ(ll[1], 3);
    EXPECT_EQ(ll[2], 4);
    EXPECT_THROW(ll[3], std::out_of_range);
    ll.clear();
    EXPECT_THROW(ll[0], std::out_of_range);
}

TEST(LinkedListTest, testIsEqualInt) {
    LinkedList<int> ll;
    LinkedList<int> ll2;
    EXPECT_EQ(ll == ll2, true);

    ll.append(1);
    ll2.append(2);
    EXPECT_EQ(ll == ll2, false);
    ll.clear();
    ll2.clear();
    
    ll.append(1);
    ll.append(3);
    ll.append(4);

    ll2.append(1);
    ll2.append(3);
    ll2.append(4);

    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);

    ll.append(7);
    EXPECT_EQ(ll == ll2, false);
    EXPECT_EQ(ll != ll2, true);

    ll2.append(7);
    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);
}

TEST(LinkedListTest, testCopyConstructorInt) {
    LinkedList<int> original;
    original.append(1);
    original.append(2);
    original.append(3);

    LinkedList<int> copy = original;  //calls copy constructor
    EXPECT_EQ(copy, original);

    original.append(4);
    EXPECT_NE(copy, original);
}

TEST(LinkedListTest, testCopyAssignmentOperatorInt) {
    LinkedList<int> original;
    original.append(1);
    original.append(2);

    LinkedList<int> copy;
    copy = original; //calls copy assign. operator
    EXPECT_EQ(copy, original);

    original.append(3);
    EXPECT_NE(copy, original);
}

TEST(LinkedListTest, testMoveConstructorInt) {
    LinkedList<int> original;
    original.append(1);
    original.append(2);

    LinkedList<int> moved = std::move(original);  // calls move constructor

    EXPECT_EQ(moved.length(), 2);
    EXPECT_EQ(moved[0], 1);
    EXPECT_EQ(moved[1], 2);

    EXPECT_TRUE(original.isEmpty());
}

TEST(LinkedListTest, testMoveAssignmentOperatorInt) {
    LinkedList<int> original;
    original.append(1);
    original.append(2);

    LinkedList<int> moved;
    moved = std::move(original);  // calls move assignment operator

    EXPECT_EQ(moved.length(), 2);
    EXPECT_EQ(moved[0], 1);
    EXPECT_EQ(moved[1], 2);

    EXPECT_TRUE(original.isEmpty());
}

// =================================================================

TEST(LinkedListTest, testLengthChar) {
    LinkedList<char> ll;
    EXPECT_EQ(ll.length(), 0);
    ll.append('e');
    ll.append('e');
    ll.append('e');
    ll.append('e');
    EXPECT_EQ(ll.length(), 4);
    ll.remove('e');
    EXPECT_EQ(ll.length(), 3);

}

TEST(LinkedListTest, testPrependChar) {
    LinkedList<char> ll;
    ll.append('e');
    EXPECT_EQ(ll.getHeadData(), 'e');
    ll.prepend('d');
    EXPECT_EQ(ll.getHeadData(), 'd');
    ll.prepend('c');
    EXPECT_EQ(ll.getHeadData(), 'c');
    ll.append('d');
    EXPECT_EQ(ll.getHeadData(), 'c');
    LinkedList<char> ll2('m');
    ll2.append('e');
    EXPECT_EQ(ll2.getHeadData(), 'm');
}

TEST(LinkedListTest, testContainsChar) {
    LinkedList<char> ll;
    ll.append('e');
    EXPECT_EQ(ll.contains('e'), true);
    ll.prepend('d');
    EXPECT_EQ(ll.contains('g'), false);
    ll.remove('e');
    EXPECT_EQ(ll.contains('e'), false);
    ll.prepend('c');
    EXPECT_EQ(ll.contains('c'), true);
}

TEST(LinkedListTest, testEmptyChar) {
    LinkedList<char> ll;
    EXPECT_EQ(ll.isEmpty(), true);
    ll.append('e');
    EXPECT_EQ(ll.isEmpty(), false);
    ll.clear();
    EXPECT_EQ(ll.isEmpty(), true);
    ll.prepend('f');
    ll.append('g');
    EXPECT_EQ(ll.isEmpty(), false);
}

TEST(LinkedListTest, testIndexingChar) {
    LinkedList<char> ll;
    ll.append('a');
    ll.append('b');
    ll.append('c');
    EXPECT_EQ(ll[0], 'a');
    EXPECT_EQ(ll[1], 'b');
    EXPECT_EQ(ll[2], 'c');
    EXPECT_THROW(ll[3], std::out_of_range);
    ll.clear();
    EXPECT_THROW(ll[0], std::out_of_range);
}

TEST(LinkedListTest, testIsEqualChar) {
    LinkedList<char> ll;
    LinkedList<char> ll2;
    EXPECT_EQ(ll == ll2, true);

    ll.append('a');
    ll2.append('b');
    EXPECT_EQ(ll == ll2, false);
    ll.clear();
    ll2.clear();
    
    ll.append('a');
    ll.append('c');
    ll.append('d');

    ll2.append('a');
    ll2.append('c');
    ll2.append('d');

    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);

    ll.append('x');
    EXPECT_EQ(ll == ll2, false);
    EXPECT_EQ(ll != ll2, true);

    ll2.append('x');
    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);
}

TEST(LinkedListTest, testCopyConstructorChar) {
    LinkedList<int> original;
    original.append('a');
    original.append('b');
    original.append('c');

    LinkedList<int> copy = original;  //calls copy constructor

    EXPECT_EQ(copy, original);

    original.append('d');
    EXPECT_NE(copy, original);
}

TEST(LinkedListTest, testCopyAssignmentOperatorChar) {
    LinkedList<char> original;
    original.append('a');
    original.append('b');

    LinkedList<char> copy;
    copy = original;  //calls copy assign. operator

    EXPECT_EQ(copy, original);
    original.append('c');
    EXPECT_NE(copy, original);
}

TEST(LinkedListTest, testMoveConstructorChar) {
    LinkedList<char> original;
    original.append('a');
    original.append('b');

    LinkedList<char> moved = std::move(original);  // calls move constructor

    EXPECT_EQ(moved.length(), 2);
    EXPECT_EQ(moved[0], 'a');
    EXPECT_EQ(moved[1], 'b');

    EXPECT_TRUE(original.isEmpty());
}

TEST(LinkedListTest, testMoveAssignmentOperatorChar) {
    LinkedList<char> original;
    original.append('a');
    original.append('b');

    LinkedList<char> moved;
    moved = std::move(original);  // calls move assignment operator

    EXPECT_EQ(moved.length(), 2);
    EXPECT_EQ(moved[0], 'a');
    EXPECT_EQ(moved[1], 'b');

    EXPECT_TRUE(original.isEmpty());
}

// =================================================================

TEST(LinkedListTest, testLengthBool) {
    LinkedList<bool> ll1;
    EXPECT_EQ(ll1.length(), 0);
    ll1.append(true);
    EXPECT_EQ(ll1.length(), 1);
    ll1.append(true);
    EXPECT_EQ(ll1.length(), 2);
    ll1.append(false);
    EXPECT_EQ(ll1.length(), 3);
    ll1.remove(true);
    EXPECT_EQ(ll1.length(), 2);
}

TEST(LinkedListTest, testPrependBool) {
    LinkedList<bool> ll;
    ll.append(true);
    EXPECT_EQ(ll.getHeadData(), true);
    ll.prepend(false);
    EXPECT_EQ(ll.getHeadData(), false);
    ll.prepend(true);
    EXPECT_EQ(ll.getHeadData(), true);
    ll.append(false);
    EXPECT_EQ(ll.getHeadData(), true);
    LinkedList<bool> ll2(true);
    ll2.append(false);
    EXPECT_EQ(ll2.getHeadData(), true);
}

TEST(LinkedListTest, testContainsBool) {
    LinkedList<bool> ll;
    ll.append(true);
    EXPECT_EQ(ll.contains(true), true);
    ll.prepend(false);
    EXPECT_EQ(ll.contains(false), true);
    ll.remove(true);
    EXPECT_EQ(ll.contains(true), false);
    ll.prepend(true);
    EXPECT_EQ(ll.contains(true), true);
}

TEST(LinkedListTest, testEmptyBool) {
    LinkedList<bool> ll;
    EXPECT_EQ(ll.isEmpty(), true);
    ll.append(true);
    EXPECT_EQ(ll.isEmpty(), false);
    ll.clear();
    EXPECT_EQ(ll.isEmpty(), true);
    ll.prepend(false);
    ll.append(true);
    EXPECT_EQ(ll.isEmpty(), false);
}

TEST(LinkedListTest, testIndexingBool) {
    LinkedList<bool> ll;
    ll.append(true);
    ll.append(false);
    ll.append(true);
    EXPECT_EQ(ll[0], true);
    EXPECT_EQ(ll[1], false);
    EXPECT_EQ(ll[2], true);
    EXPECT_THROW(ll[3], std::out_of_range);
    ll.clear();
    EXPECT_THROW(ll[0], std::out_of_range);
}

TEST(LinkedListTest, testIsEqualBool) {
    LinkedList<bool> ll;
    LinkedList<bool> ll2;
    EXPECT_EQ(ll == ll2, true);

    ll.append(true);
    ll2.append(false);
    EXPECT_EQ(ll == ll2, false);
    ll.clear();
    ll2.clear();
    
    ll.append(true);
    ll.append(false);
    ll.append(true);

    ll2.append(true);
    ll2.append(false);
    ll2.append(true);

    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);

    ll.append(false);
    EXPECT_EQ(ll == ll2, false);
    EXPECT_EQ(ll != ll2, true);

    ll2.append(false);
    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);
}

TEST(LinkedListTest, testCopyConstructorBool) {
    LinkedList<bool> original;
    original.append(true);
    original.append(false);
    original.append(true);

    LinkedList<bool> copy = original;  //calls copy constructor
    EXPECT_EQ(copy, original);

    original.append(false);
    EXPECT_NE(copy, original);
}

TEST(LinkedListTest, testCopyAssignmentOperatorBool) {
    LinkedList<bool> original;
    original.append(true);
    original.append(false);

    LinkedList<bool> copy;
    copy = original; //calls copy assign. operator
    EXPECT_EQ(copy, original);

    original.append(true);
    EXPECT_NE(copy, original);
}

TEST(LinkedListTest, testMoveConstructorBool) {
    LinkedList<bool> original;
    original.append(true);
    original.append(false);

    LinkedList<bool> moved = std::move(original);  // calls move constructor

    EXPECT_EQ(moved.length(), 2);
    EXPECT_EQ(moved[0], true);
    EXPECT_EQ(moved[1], false);

    EXPECT_TRUE(original.isEmpty());
}

TEST(LinkedListTest, testMoveAssignmentOperatorBool) {
    LinkedList<bool> original;
    original.append(true);
    original.append(false);

    LinkedList<bool> moved;
    moved = std::move(original);  // calls move assignment operator

    EXPECT_EQ(moved.length(), 2);
    EXPECT_EQ(moved[0], true);
    EXPECT_EQ(moved[1], false);

    EXPECT_TRUE(original.isEmpty());
}

// =================================================================

TEST(LinkedListTest, testLengthFloat) {
    LinkedList<float> ll;
    EXPECT_EQ(ll.length(), 0);
    ll.append(5.0f);
    ll.append(5.0f);
    ll.append(5.0f);
    ll.append(5.0f);
    EXPECT_EQ(ll.length(), 4);
    ll.remove(5.0f);
    EXPECT_EQ(ll.length(), 3);
}

TEST(LinkedListTest, testPrependFloat) {
    LinkedList<float> ll;
    ll.append(5.0f);
    EXPECT_NEAR(ll.getHeadData(), 5.0f, TOLERANCE);
    ll.prepend(4.0f);
    EXPECT_NEAR(ll.getHeadData(), 4.0f, TOLERANCE);
    ll.prepend(3.0f);
    EXPECT_NEAR(ll.getHeadData(), 3.0f, TOLERANCE);
    ll.append(4.0f);
    EXPECT_NEAR(ll.getHeadData(), 3.0f, TOLERANCE);
    LinkedList<float> ll2(11.0f);
    ll2.append(5.0f);
    EXPECT_NEAR(ll2.getHeadData(), 11.0f, TOLERANCE);
}

//FUTURE UPDATE, THE CONTAINS METHOD FOR FLOAT SHOULD HANDLE THE TOLERANCE
TEST(LinkedListTest, testContainsFloat) {
    LinkedList<float> ll;
    ll.append(5.0f);
    EXPECT_TRUE(ll.contains(5.0f));
    ll.prepend(4.0f);
    EXPECT_FALSE(ll.contains(7.0f));
    ll.remove(5.0f);
    EXPECT_FALSE(ll.contains(5.0f));
    ll.prepend(3.0f);
    EXPECT_TRUE(ll.contains(3.0f));
}

TEST(LinkedListTest, testEmptyFloat) {
    LinkedList<float> ll;
    EXPECT_TRUE(ll.isEmpty());
    ll.append(5.0f);
    EXPECT_FALSE(ll.isEmpty());
    ll.clear();
    EXPECT_TRUE(ll.isEmpty());
    ll.prepend(6.0f);
    ll.append(7.0f);
    EXPECT_FALSE(ll.isEmpty());
}

TEST(LinkedListTest, testIndexingFloat) {
    LinkedList<float> ll;
    ll.append(1.0f);
    ll.append(3.0f);
    ll.append(4.0f);
    EXPECT_NEAR(ll[0], 1.0f, TOLERANCE);
    EXPECT_NEAR(ll[1], 3.0f, TOLERANCE);
    EXPECT_NEAR(ll[2], 4.0f, TOLERANCE);
    EXPECT_THROW(ll[3], std::out_of_range);
    ll.clear();
    EXPECT_THROW(ll[0], std::out_of_range);
}

//FUTURE UPDATE, THE == OPERATOR FOR FLOAT SHOULD HANDLE THE TOLERANCE
TEST(LinkedListTest, testIsEqualFloat) {
    LinkedList<float> ll;
    LinkedList<float> ll2;
    // Note: You may need to modify the == operator for LinkedList to compare floating-point data with tolerance
    EXPECT_EQ(ll == ll2, true);

    ll.append(1.0f);
    ll2.append(2.0f);
    EXPECT_EQ(ll == ll2, false);
    ll.clear();
    ll2.clear();
    
    ll.append(1.0f);
    ll.append(3.0f);
    ll.append(4.0f);

    ll2.append(1.0f);
    ll2.append(3.0f);
    ll2.append(4.0f);

    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);

    ll.append(7.0f);
    EXPECT_EQ(ll == ll2, false);
    EXPECT_EQ(ll != ll2, true);

    ll2.append(7.0f);
    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);
}

//FUTURE UPDATE, THE COPY CONSTRUCTOR FOR FLOAT SHOULD HANDLE THE TOLERANCE
TEST(LinkedListTest, testCopyConstructorFloat) {
    LinkedList<float> original;
    original.append(1.0f);
    original.append(2.0f);
    original.append(3.0f);

    LinkedList<float> copy = original;  //calls copy constructor
    EXPECT_EQ(copy, original);

    original.append(4.0f);
    EXPECT_NE(copy, original);
}

//FUTURE UPDATE, THE COPY OPERATOR FOR FLOAT SHOULD HANDLE THE TOLERANCE
TEST(LinkedListTest, testCopyAssignmentOperatorFloat) {
    LinkedList<float> original;
    original.append(1.0f);
    original.append(2.0f);

    LinkedList<float> copy;
    copy = original; //calls copy assign. operator
    EXPECT_EQ(copy, original);

    original.append(3.0f);
    EXPECT_NE(copy, original);
}

//FUTURE UPDATE, THE MOVE CONSTRUCTOR FOR FLOAT SHOULD HANDLE THE TOLERANCE
TEST(LinkedListTest, testMoveConstructorFloat) {
    LinkedList<float> original;
    original.append(1.0f);
    original.append(2.0f);

    LinkedList<float> moved = std::move(original);  // calls move constructor

    EXPECT_EQ(moved.length(), 2);
    EXPECT_NEAR(moved[0], 1.0f, TOLERANCE);
    EXPECT_NEAR(moved[1], 2.0f, TOLERANCE);

    EXPECT_TRUE(original.isEmpty());
}

//FUTURE UPDATE, THE MOVE OPERATOR FOR FLOAT SHOULD HANDLE THE TOLERANCE
TEST(LinkedListTest, testMoveAssignmentOperatorFloat) {
    LinkedList<float> original;
    original.append(1.0f);
    original.append(2.0f);

    LinkedList<float> moved;
    moved = std::move(original);  // calls move assignment operator

    EXPECT_EQ(moved.length(), 2);
    EXPECT_NEAR(moved[0], 1.0f, TOLERANCE);
    EXPECT_NEAR(moved[1], 2.0f, TOLERANCE);

    EXPECT_TRUE(original.isEmpty());
}


// =================================================================

TEST(LinkedListTest, testLengthDouble) {
    LinkedList<double> ll;
    EXPECT_EQ(ll.length(), 0);
    ll.append(5.0);
    ll.append(5.0);
    ll.append(5.0);
    ll.append(5.0);
    EXPECT_EQ(ll.length(), 4);
    ll.remove(5.0);
    EXPECT_EQ(ll.length(), 3);
}

TEST(LinkedListTest, testPrependDouble) {
    LinkedList<double> ll;
    ll.append(5.0);
    EXPECT_NEAR(ll.getHeadData(), 5.0, DOUBLE_TOLERANCE);
    ll.prepend(4.0);
    EXPECT_NEAR(ll.getHeadData(), 4.0, DOUBLE_TOLERANCE);
    ll.prepend(3.0);
    EXPECT_NEAR(ll.getHeadData(), 3.0, DOUBLE_TOLERANCE);
    ll.append(4.0);
    EXPECT_NEAR(ll.getHeadData(), 3.0, DOUBLE_TOLERANCE);
    LinkedList<double> ll2(11.0);
    ll2.append(5.0);
    EXPECT_NEAR(ll2.getHeadData(), 11.0, DOUBLE_TOLERANCE);
}

TEST(LinkedListTest, testContainsDouble) {
    LinkedList<double> ll;
    ll.append(5.0);
    EXPECT_TRUE(ll.contains(5.0));
    ll.prepend(4.0);
    EXPECT_FALSE(ll.contains(7.0));
    ll.remove(5.0);
    EXPECT_FALSE(ll.contains(5.0));
    ll.prepend(3.0);
    EXPECT_TRUE(ll.contains(3.0));
}

TEST(LinkedListTest, testEmptyDouble) {
    LinkedList<double> ll;
    EXPECT_TRUE(ll.isEmpty());
    ll.append(5.0);
    EXPECT_FALSE(ll.isEmpty());
    ll.clear();
    EXPECT_TRUE(ll.isEmpty());
    ll.prepend(6.0);
    ll.append(7.0);
    EXPECT_FALSE(ll.isEmpty());
}

TEST(LinkedListTest, testIndexingDouble) {
    LinkedList<double> ll;
    ll.append(1.0);
    ll.append(3.0);
    ll.append(4.0);
    EXPECT_NEAR(ll[0], 1.0, DOUBLE_TOLERANCE);
    EXPECT_NEAR(ll[1], 3.0, DOUBLE_TOLERANCE);
    EXPECT_NEAR(ll[2], 4.0, DOUBLE_TOLERANCE);
    EXPECT_THROW(ll[3], std::out_of_range);
    ll.clear();
    EXPECT_THROW(ll[0], std::out_of_range);
}

TEST(LinkedListTest, testIsEqualDouble) {
    LinkedList<double> ll;
    LinkedList<double> ll2;
    EXPECT_EQ(ll == ll2, true);

    ll.append(1.0);
    ll2.append(2.0);
    EXPECT_EQ(ll == ll2, false);
    ll.clear();
    ll2.clear();
    
    ll.append(1.0);
    ll.append(3.0);
    ll.append(4.0);

    ll2.append(1.0);
    ll2.append(3.0);
    ll2.append(4.0);

    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);

    ll.append(7.0);
    EXPECT_EQ(ll == ll2, false);
    EXPECT_EQ(ll != ll2, true);

    ll2.append(7.0);
    EXPECT_EQ(ll == ll2, true);
    EXPECT_EQ(ll != ll2, false);
}

TEST(LinkedListTest, testCopyConstructorDouble) {
    LinkedList<double> original;
    original.append(1.0);
    original.append(2.0);
    original.append(3.0);

    LinkedList<double> copy = original;  //calls copy constructor
    EXPECT_EQ(copy, original);

    original.append(4.0);
    EXPECT_NE(copy, original);
}

TEST(LinkedListTest, testCopyAssignmentOperatorDouble) {
    LinkedList<double> original;
    original.append(1.0);
    original.append(2.0);

    LinkedList<double> copy;
    copy = original; //calls copy assign. operator
    EXPECT_EQ(copy, original);

    original.append(3.0);
    EXPECT_NE(copy, original);
}

//FUTURE UPDATE, THE MOVE CONSTRUCTOR FOR DOUBLE SHOULD HANDLE THE TOLERANCE
TEST(LinkedListTest, testMoveConstructorDouble) {
    LinkedList<double> original;
    original.append(1.0);
    original.append(2.0);

    LinkedList<double> moved = std::move(original);  // calls move constructor

    EXPECT_EQ(moved.length(), 2);
    EXPECT_NEAR(moved[0], 1.0, DOUBLE_TOLERANCE);
    EXPECT_NEAR(moved[1], 2.0, DOUBLE_TOLERANCE);

    EXPECT_TRUE(original.isEmpty());
}

//FUTURE UPDATE, THE MOVE OPERATOR FOR DOUBLE SHOULD HANDLE THE TOLERANCE
TEST(LinkedListTest, testMoveAssignmentOperatorDouble) {
    LinkedList<double> original;
    original.append(1.0);
    original.append(2.0);

    LinkedList<double> moved;
    moved = std::move(original);  // calls move assignment operator

    EXPECT_EQ(moved.length(), 2);
    EXPECT_NEAR(moved[0], 1.0, DOUBLE_TOLERANCE);
    EXPECT_NEAR(moved[1], 2.0, DOUBLE_TOLERANCE);

    EXPECT_TRUE(original.isEmpty());
}


// =================================================================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}