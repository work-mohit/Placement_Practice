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
    pair<int, int> p1 = countGoodBadPathsHelper(root->left, good, bad);
    pair<int, int> p2 = countGoodBadPathsHelper(root->right, good, bad);

    // Initialize 'g' and 'b' to 1
    int g = 1, b = 1;

    // If the left child is not NULL.
    if (root->left != NULL) {

        // Check if the value is increasing from parent to child.
        if (root->data < root->left->data) {

            // Add the count of good paths of child to parent.
            g += p1.first;
        }

        // Check if the value is decreasing from parent to child.
        if (root->data > root->left->data) {

            // Add the count of bad paths of child to parent.
            b += p1.second;
        }
    }
    if (root->right != NULL) {

        // Check if the value is increasing from parent to child.
        if (root->data < root->right->data) {

            // Add the count of good paths of child to parent.
            g += p2.first;
        }

        // Check if the value is decreasing from parent to child.
        if (root->data > root->right->data) {

            // Add the count of bad paths of child to parent.
            b += p2.second;
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
    // 'good' stores the total good paths.
    int bad = 0;

    countGoodBadPathsHelper(root, good, bad);
    return {good, bad};
}