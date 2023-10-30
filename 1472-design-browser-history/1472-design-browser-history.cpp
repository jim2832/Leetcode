
class BrowserHistory {
    public:
        class Node{
            public:
                Node* prev; // the previous node
                Node* next; // the next node
                string url; // the url

                // Constructor that sets the URL for this node
                Node(string url){
                    this->url = url;
                    prev = NULL;
                    next = NULL;
                }
        };
        
        Node* current;

        BrowserHistory(string homepage) {
            current = new Node(homepage);
        }
        
        void visit(string url) {
            Node* temp = new Node(url);
            current->next = temp;
            temp->prev = current;
            current = current->next;
        }
        
        string back(int steps) {
            while(current->prev){
                if(!steps) break;
                steps--;
                current = current->prev;
            }
            return current->url;
        }
        
        string forward(int steps) {
            while(current->next){
                if(!steps) break;
                steps--;
                current = current->next;
            }
            return current->url;
        }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */