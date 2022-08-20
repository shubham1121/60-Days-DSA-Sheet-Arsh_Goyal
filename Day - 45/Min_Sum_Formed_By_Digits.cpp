// Greedily select min digit for higher place value.
class Solution{
    public:
    long long int minSum(int a[], int n)
    { long long num1=0,num2=0;
     sort(a,a+n);
      for(int i=0;i<n;i++)
      {
          if(i%2==0)
          {
              num1 = num1*10 + a[i];
          }
          else
          {
              num2 = num2*10 + a[i];
          }
      }
      return num1+num2;
    }
};