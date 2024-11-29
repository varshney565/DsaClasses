class WordTree {
private:
    struct WordNode {
        string word;
        int count;
        WordNode* left;
        WordNode* right;
        WordNode(const string& w) : word(w), count(1), left(nullptr), right(nullptr) {}
    };
    
    WordNode* root;

    WordNode* add(WordNode*& root, const string& word) {
        if(root == nullptr) {
            WordNode* newNode = new WordNode(word);
            return newNode;
        }

        if(word < root->word) {
            root->left = add(root->left,word);
        }else if(word > root->word){
            root->right = add(root->right,word);
        }else {
            root->count++;
        }
        return root;
    }

    int countWords(WordNode* root) const {
       if(root == nullptr) return 0;
       return countWords(root->left) + countWords(root->right) + 1;
    }

    void printInOrder(WordNode* root, ostream& os) const {
        if(root == nullptr) return;
        printInOrder(root->left,os);
        os << root->word<<" "<<root->count<<" ";
        printInOrder(root->right,os);
    }

    void deleteTree(WordNode* root) {
        if(root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete(root);
    }

public:
    WordTree() : root(nullptr) {}

    ~WordTree() {
        deleteTree(root);
        // delete(root->left);
        // delete(root->right);
        // delete(root);
    }

    void add(const string& word) {
        root = add(root, word);
    }

    int numWords() const {
        return countWords(root);
    }

    friend ostream& operator<<(ostream& os, const WordTree* tree) {
        tree->printInOrder(tree->root, os);
        return os;
    }
};
