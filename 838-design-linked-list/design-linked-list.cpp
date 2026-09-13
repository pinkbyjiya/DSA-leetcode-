class MyLinkedList {
    
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = NULL;
        }
    };

    ListNode* head;
    int size;

public:

    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        ListNode* curr = head;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == NULL) {
            head = newNode;
            size++;
            return;
        }

        ListNode* curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* newNode = new ListNode(val);
        ListNode* curr = head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        if (index == 0) {
            head = head->next;
            size--;
            return;
        }

        ListNode* curr = head;

        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        curr->next = curr->next->next;

        size--;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */