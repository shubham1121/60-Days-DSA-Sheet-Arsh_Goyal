// T.C -: O(N*N) & S.C -: O(1) Try every petrol pump and if found return that index else return -1

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    { 
        int i=0,ans=-1;
        bool check=false;
        while(i<n)
        { int rem=0,cnt=0;
            for(int k = i;;)
            {   
                if(k==i && cnt==1)
                {
                    check=true;
                    ans=i;
                    break;
                }
                else if(p[k%n].petrol+rem>=p[k%n].distance)
                {
                    rem = p[k%n].petrol+rem - p[k%n].distance;
                    k++;
                    cnt=1;
                    k=k%n;
                }
                else
                {
                    break;
                }
                
            }
            if(check)break;
            i++;
        }
        if(check) return ans;
        return -1;
    }
};

// T.C -: O(N) & S.C -: O(1) Calculated required fuel when extra fuel becomes negative and move the start to next posn of current posn

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    { 
        int start = 0,reqF=0,extraF=0;
        for(int i=0;i<n;i++)
        {
            extraF+=(p[i].petrol-p[i].distance);
            if(extraF<0)
            {
                start = i+1;
                reqF+=extraF;
                extraF=0;
            }
            
        }
        
        return (reqF+extraF)>=0 ? start : -1 ;
    }
};