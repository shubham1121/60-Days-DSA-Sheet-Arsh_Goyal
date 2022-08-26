void insert(struct TrieNode *root, string key)
{
    // code here
    for(int i = 0; i < key.length(); i++)
    {
        char ch = key[i];
        
        if(root->children[ch-'a'] == NULL)
            root->children[ch-'a'] = getNode();
        
        root = root->children[ch-'a'];
    }
    
    root->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    // code here
    for(int i = 0; i < key.length(); i++)
    {
        char ch = key[i];
        
        if(root->children[ch-'a'] == NULL)
            return false;
    
        root = root->children[ch-'a'];
    }
    
    return (root->isLeaf);
}