/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' denotes the number of elements in the array 'ARR'.
*/


pair<int, int> countGoodBadPathsHelper(TreeNode<int> *root, int &good, int &bad) {

    // If the root is NULL, then no good or bad path.
    if (root == NULL) {
        return {0, 0};
    }

    // Call the function for both the left and right child.
    // first go till the last and then come backward

    pair<int, int> left = countGoodBadPathsHelper(root->left, good, bad);
    pair<int, int> right = countGoodBadPathsHelper(root->right, good, bad);

    //  Initialize 'g' and 'b' to 1
    //  because we also count each individual node as good and bad 

    int g = 1, b = 1;

    // If the left child is not NULL.
    if (root->left != NULL) {

        // Check if the value is increasing from parent to child.
        if (root->data < root->left->data) {

            // Add the count of good paths of child to parent.
            g += left.first;
        }
        // we can also put an else statement  here
        // Check if the value is decreasing from parent to child.
        if (root->data > root->left->data) {

            // Add the count of bad paths of child to parent.
            // we are keeping bad paths on second
            b += left.second;
        }
    }
    if (root->right != NULL) {

        // Check if the value is increasing from parent to child.
        if (root->data < root->right->data) {

            // Add the count of good paths of child to parent.
            g += right.first;
        }

        // Check if the value is decreasing from parent to child.
        if (root->data > root->right->data) {

            // Add the count of bad paths of child to parent.
            b += right.second;
        }
    }

    // Add the total count of good paths to the global good paths counter.
    good += g;

    // Add the total count of bad paths to the global bad paths counter.
    bad += b;

    return {g, b};
}

pair<int, int> countGoodBadPaths(TreeNode<int> *root){

    // 'good' stores the total good paths.
    int good = 0;
    // 'bad' stores the total bad paths.
    int bad = 0;

    countGoodBadPathsHelper(root, good, bad);
    return {good, bad};
}