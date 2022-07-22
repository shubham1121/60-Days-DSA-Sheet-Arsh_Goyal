// T.C -: O(max(list1.size(),list2.size())) S.C -: O(1)
long long  multiplyTwoLists (Node* l1, Node* l2)
{ long long n1,n2;
  long long mod = 1e9 + 7;
  n1=0,n2=0;
  Node*temp=l1;
  while(l1)
  {
      n1 = (n1*10)%mod + l1->data;
      l1=l1->next;
  }
  while(l2)
  {
      n2 = (n2*10)%mod + l2->data;
      l2=l2->next;
  }
  return ((n1%mod)*(n2%mod))%mod;
}