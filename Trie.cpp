class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        string line = "";
        for( int i = 0 ; i < dictionary.size() ; i ++ ){
            t.insert(dictionary[i]);
        }
        for( int l = 0 , i = 0 ; i < sentence.size() ; i ++ ){
                if((char)sentence[i] == ' ' ||  i == sentence.size()-1){
                    string str;
                   (i == sentence.size() -1) ?  str = sentence.substr(l , i-l+1) :  str = sentence.substr(l ,i - l);
                    l = i+1;
                    string res = t.findSim(str);
                    if(res == "#")
                        line +=str + " ";
                    else
                        line += res + " ";
            }
        }
        return line.substr(0 ,line.size()-1);
    }
    
    
    
    struct Node{
    char c;
    bool isWord;
    Node* children[26];
    Node(char c){
        for( int i = 0 ; i < 26; i ++ ){
            children[i] = NULL;
        }
        this->c = c;
        isWord = false;
    }
};

class Trie{
private :
    Node* root;
public :
    Trie(){
        root =new Node('\0');
        root->isWord = false;
    }
       void insert(string word){
           Node* curr = root;        // start from the root
           for( int i = 0 ; i < word.size() ; i ++ ){
               char letter = (char)word[i];
               if(curr->children[letter - 'a'] == NULL){
                   curr->children[letter - 'a'] =new Node(letter);
               }
               curr = curr->children[letter -'a'];
           }
           curr->isWord = true;
       }
       string findSim(string word){
           Node* curr = root;
           string ret = "";
           for( int i = 0 ; i < word.size() ; i ++ ){
               char letter = (char)word[i];
               if(curr->children[letter - 'a'] != NULL){
                   ret += letter;
                   if(curr->children[letter - 'a']->isWord == true){
                       return ret;
                   }
                   curr = curr->children[letter-'a'];
               }
               else{
                   return "#";
               }
           }
           return "#";
       }

};
};
