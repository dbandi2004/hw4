#ifndef RECCHECK
// You can include additional headers here if needed
#include <algorithm>
#endif


#include "equal-paths.h"
using namespace std;


bool checkEqualPaths(Node *node, int &pathLength, bool &equal) {
    if (node == nullptr) {
        pathLength = 0;
        return true;
    }


    int leftLength, rightLength;
    bool leftEqual = checkEqualPaths(node->left, leftLength, equal);
    bool rightEqual = checkEqualPaths(node->right, rightLength, equal);


    if (node->left != nullptr && node->right != nullptr) {
        equal = equal && (leftLength == rightLength);
    }


    pathLength = 1 + max(leftLength, rightLength);
    return equal && leftEqual && rightEqual;
}


bool equalPaths(Node *root) {
    int pathLength = 0;
    bool equal = true;
    checkEqualPaths(root, pathLength, equal);
    return equal;
}
