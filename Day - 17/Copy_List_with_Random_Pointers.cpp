// T.C -: O(N) & S.C -: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
          Node *front = head;
          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
          }
          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }
          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *newHead = new Node(0);
          Node *copy = newHead;
          while (iter != NULL) {
            front = iter->next->next;
            // extract the copy
            copy->next = iter->next;
            // restore the original list
            iter->next = front;
            copy = copy -> next; 
            iter = front;
          }
          return newHead->next;
    }
};