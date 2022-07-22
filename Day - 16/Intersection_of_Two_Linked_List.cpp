// T.C -: O(N*M) & S.C -: O(1) Brute force

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *l1=headA,*l2=headB;
        while(l1)
        {  l2=headB;
            while(l2)
            {
                if(l1==l2)
                {return l1;}
                l2=l2->next;
            }
            l1=l1->next;
        }
        return NULL;
    }
};

// T.C -: O(N*M) & S.C -: O(1) Better idea with hashing

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *l1=headA,*l2=headB;
        unordered_set<ListNode*>uset;
        while(l1)
        {  uset.insert(l1);
            l1=l1->next;
        }
        while(l2)
            {
                if(uset.find(l2)!=uset.end())
                {
                    return l2;
                }
            l2=l2->next;
            }
        return NULL;
    }
};

// T.C -: O(N*M) & S.C -: O(1) Optimised Idea

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode *l1=headA,*l2=headB;
        while(l1!=l2)
        {
            l1 = l1==NULL ? headB:l1->next;
            l2 = l2==NULL ? headA:l2->next;
        }
        return l1;
    }
};