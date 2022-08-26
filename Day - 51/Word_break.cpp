class Trie{
    public:
    Trie *child[26];
    bool leaf;
    Trie(){
        for(int i=0;i<26;i++)
            child[i]=NULL;
        leaf=false;
    }
    void insert(string s){
        int i=0;
        Trie *x=this;
        while(i<s.length() && x->child[s[i]-'a'])
            x=x->child[s[i++]-'a'];
        while(i<s.length()){
            Trie *t=new Trie();
            x->child[s[i]-'a']=t;
            x=x->child[s[i++]-'a'];
        }
        x->leaf=true;
    }
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
        int fn(string s,int i,Trie *curr,Trie *root){
        if(i==s.length() && curr==root)
            return 1;
        if(!curr->child[s[i]-'a'])
            return 0;
        curr=curr->child[s[i]-'a'];
        if(curr->leaf && fn(s,i+1,root,root))
                return 1;
        return fn(s,i+1,curr,root);
    }
    int wordBreak(string A, vector<string> &B) {
        Trie *trie = new Trie();
        for(int i=0;i<B.size();i++)
            trie->insert(B[i]);
        Trie *x=trie;
        return fn(A,0,x,trie);
    }
};