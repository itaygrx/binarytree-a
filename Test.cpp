#include "doctest.h"
#include "sources/BinaryTree.hpp"
using namespace ariel;

TEST_CASE("Int Binary Tree Checks"){
    BinaryTree<int> MyTree;
    CHECK_NOTHROW(MyTree.add_root(2));
    CHECK_THROWS(MyTree.add_right(3,4)); // Should Throw Exception no Father node "3"
    CHECK_EQ(MyTree.get_root()->node_data,2);
    CHECK_NOTHROW(MyTree.add_root(3)); //Should Switch Root; 
    CHECK_EQ(MyTree.get_root()->node_data,3);
    CHECK_THROWS(MyTree.add_left(4,1));// Should Throw Exception no Father node "3"
    CHECK_NOTHROW(MyTree.add_right(3,4));//root has been changed no parent with value 2
    CHECK_NOTHROW(MyTree.add_left(4,8));//Should add 8 as the left son of 4
    CHECK_THROWS(MyTree.add_right(2,5)); // No Node with value 2 in the tree should throw exception.
    CHECK_THROWS(MyTree.add_left(6,2)); // No node with value 6
    

}

TEST_CASE("String Binary Tree Checks"){
    BinaryTree<string> MyTree;

    CHECK_THROWS(MyTree.add_left("abc","acd"));// no root
    CHECK_NOTHROW(MyTree.add_root("a"));
    CHECK_NOTHROW(MyTree.add_left("a","al"));
    CHECK_NOTHROW(MyTree.add_right("a","ar"));
    CHECK_NOTHROW(MyTree.add_root("b"));
    CHECK_THROWS(MyTree.add_right("a","ar"));


}

TEST_CASE("ordinary checks"){
    BinaryTree<char> MyTree;
    CHECK_NOTHROW(cout << MyTree << endl;);
    CHECK_NOTHROW(MyTree.add_root('a'));
    CHECK_NOTHROW(MyTree.add_right('a','b'));
    CHECK_NOTHROW(MyTree.add_root('c'));
    CHECK_THROWS(MyTree.add_right(3,4));


}