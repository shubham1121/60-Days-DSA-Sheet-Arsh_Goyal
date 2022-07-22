// T.C -: O(1) & S.C -: O(1)
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {  Node *temp=del->next;
        del->data=del->next->data;
        del->next=del->next->next;
        delete(temp);
    }

};