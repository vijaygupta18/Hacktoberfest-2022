class Trie {

    private Node root;
    /** Initialize your data structure here. */
    public Trie() {
        root = new Node('\0');
        
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Node curr = root;
        for(int i=0 ; i<word.length(); i++){
            char c = word.charAt(i);
            if(curr.children[c-'a'] == null) curr.children[c-'a'] = new Node(c);
            curr = curr.children[c-'a'];
        }
        curr.isWord =true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Node node = getNode(word);
        if(node == null){
            return false;
        }
        else{
            return node.isWord;
        }
    }
    private Node getNode(String word){
        Node curr = root;
        for(int i=0; i<word.length() ; i++){
            char c = word.charAt(i);
            if(curr.children[c-'a'] == null) return null;
            curr = curr.children[c-'a'];
        }
        return curr;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Node node = getNode(prefix);
        if(node == null){
            return false;
        }
        return true;
        
    }
    class Node{
        public char c;
        public boolean isWord;
        public Node[] children;
        
        public Node(char c){
            this.c = c;
            isWord = false;
            children = new Node[26];
        }
    }
}