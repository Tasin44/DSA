
///approach: 1st

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* nextnode=node->next;// Step 1: Save reference to the next node
        node->val=node->next->val;// Step 2: Copy value from the next node to the current node
        node->next=node->next->next;
        // Step 3: Adjust the next node's next pointer to skip the next node
        delete nextnode; // Step 4: Delete the next node from memory
    }
};

/*
Step 1: Save Reference to the Next Node
ListNode* nextNode = node->next;
This line saves a pointer to the node that comes after the node to be "deleted."

Step 4: Delete the Next Node from Memory
delete nextNode;
Finally, the delete statement frees the memory of the node that originally followed node,
which we now no longer need since its value has been copied over to node
and it's been skipped in the list.


Complexity
Time complexity:O(1), as we're only modifying the current node
Space complexity:O(1), no extra space is used.

*/






///approach : 2

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* nextnode=node->next;// Step 1: Save reference to the next node
        node->val=node->next->val;// Step 2: Copy value from the next node to the current node
        node->next=node->next->next;
        // Step 3: Adjust the next node's next pointer to skip the next node
        delete nextnode; // Step 4: Delete the next node from memory
    }
};

/*
Step 1: Save Reference to the Next Node
ListNode* nextNode = node->next;
This line saves a pointer to the node that comes after the node to be "deleted."

Step 4: Delete the Next Node from Memory
delete nextNode;
Finally, the delete statement frees the memory of the node that originally followed node,
which we now no longer need since its value has been copied over to node
and it's been skipped in the list.


Complexity
Time complexity:O(1), as we're only modifying the current node
Space complexity:O(1), no extra space is used.

*/



//approach : 3
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next;// Step 1: Save reference to the next node
        *node = *node->next;
        // Step 2: Copy the contents of the next node to the current node
        delete temp;// Step 3: Delete the next node
    }
};
/*
Step 1: Save Reference to the Next Node
This line creates a pointer temp that points to the next node (node->next).
This is done to temporarily store the reference of the next node so that it can be deleted later.


Step 2: Copy the Contents of the Next Node to the Current Node

The expression *node = *node->next copies all the contents (both the value and the next pointer) of the next node into the current node.

Essentially, this operation overwrites the current node (node) with the data and next pointer of the next node (node->next).

After this operation, the current node (node) effectively becomes the next node. The value of the node has been changed to the value of the next node, and its next pointer is updated to point to node->next->next.

Step 3: Delete the Next Node

The delete statement releases the memory of the original next node (temp), which we copied over.
This operation is crucial to avoid a memory leak since we have already copied the data from the next node to the current node.


*/















