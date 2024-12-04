#include <optional>
#include <functional>
#include <stack>

template <typename TKey, typename TData>
class binary_search_tree{
    struct node{
        TKey key;
        TData data;
        node* left = nullptr;
        node* right = nullptr;
    }*root = nullptr;

    size_t count = 0;

    node* _find(const TKey& key) const{
        node* current = root;
        while (current && current->key != key)
            current = current->key < key ? current->right : current->left;
        return current;
    }

    node* _findMin(node* n) const{
        while (n && n->left)
            n = n->left;
        return n;
    }

    node* _findMax(node* n) const{
        while (n && n->right)
            n = n->right;
        return n;
    }

    node* _findNext(node* n) const{
        if (n->right)
            return _findMin(n->right);

        node* successor = nullptr;
        node* current = root;
        while (current){
            if (n->key < current->key){
                successor = current;
                current = current->left;
            }
            else if (n->key > current->key){
                current = current->right;
            }
            else{
                break;
            }
        }
        return successor;
    }

public:
    binary_search_tree() {}

    ~binary_search_tree() {
        std::stack<node*> s;
        node* current = this.root;

        while (!s.empty() || current) {
            if (current) {
                s.push(current);
                current = current->left;
            }
            else {
                current = s.top()->right;
                delete s.top();
                s.pop();
            }
        }
    }

    std::optional<TData> find(const TKey& key){
        node* n = _find(key);
        return n ? std::optional<TData>(n->data) : std::nullopt;
    }

    void insert(const TKey& key, const TData& data){
        node** current = &root;
        while (*current){
            if ((*current)->key == key){
                (*current)->data = data;
                return;
            }
            current = (*current)->key < key ? &(*current)->right : &(*current)->left;
        }
        *current = new node{ key, data, nullptr, nullptr };
        count++;
    }

    std::optional<TKey> findnext(const TKey& key){
        node* n = _find(key);
        if (!n) {
            return std::nullopt;
        }
        node* nextNode = _findNext(n);
        return nextNode ? std::optional<TKey>(nextNode->key) : std::nullopt;
    }

    void remove(const TKey& key) {
        node** current = &root;
        while (*current) {
            if ((*current)->key == key){
                if ((*current)->left && (*current)->right){
                    node* minRight = _findMin((*current)->right);
                    (*current)->key = minRight->key;
                    (*current)->data = minRight->data;
                    current = &(*current)->right;
                    key = minRight->key;
                }
                else{
                    node* temp = *current;
                    *current = (*current)->left ? (*current)->left : (*current)->right;
                    delete temp;
                    count--;
                    return;
                }
            }
            else {
                current = (*current)->key < key ? &(*current)->right : &(*current)->left;
            }
        }
    }
};

int main() {

    return 0;
}