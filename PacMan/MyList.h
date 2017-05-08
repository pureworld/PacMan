#pragma once

template<typename T>
struct ListNode {
    ListNode<T>* next;
    T data;
    ListNode() { next = NULL; }
    ListNode(T _data) { data = _data; next = NULL; }
};

template<typename T>
class CMyList {
public:
    class iterator {
    public:
        friend class CMyList<T>;

        iterator(ListNode<T>* pNode) {
            node = pNode;
        }

        bool operator==(iterator it) {
            return node == it.node;
        }
        bool operator!=(iterator it) {
            return node != it.node;
        }
        iterator operator++() {
            node = node->next;
            return *this;
        }
        iterator operator++(int) {
            ListNode<T>* pTmp = node;
            node = node->next;
            return pTmp;
        }
        T operator*() {
            return node->data;
        }

    private:
        ListNode<T>* node;
    };

    CMyList() {
        head = NULL;
    }

    ~CMyList() {
        while(head) {
            pop_front();
        }
    }

    T& front() {
 //       ASSERT(head != NULL);
        return head->data;
    }

    T& back() {
     //   ASSERT(head != NULL);
        int nCnt = size();
        ListNode<T>* pTmp = head;
        while (nCnt-- > 1) {
            pTmp = pTmp->next;
        }
        return pTmp->data;
    }

    void push_front(T data) {
        if (head == NULL) {
            ListNode<T>* pTmp = new ListNode<T>(data);
            head = pTmp;
            return;
        }
        ListNode<T>* pTmp = new ListNode<T>(data);
        pTmp->next = head;
        head = pTmp;
        return;
    }

    void push_back(T data) {
        insert(data, size());
    }

    bool pop_front() {
        if (head == NULL) {
            return false;
        }
        head = head->next;
        return true;
    }

    bool pop_back() {
        return erase(size() - 1);
    }

    iterator begin() {
        return head;
    }

    iterator end() {
        return NULL;
    }

    int insert(T data, int nIndex) {
        if (nIndex > size()) {
            return -1;
        }
        if (size() == 0) {
            push_front(data);
            return 0;
        }
        ListNode<T>* pTmpHead = head;
        nIndex--;
        while(nIndex--) {
            pTmpHead = pTmpHead->next;
        }
        ListNode<T>* pTmp = new ListNode<T>(data);
        pTmp->next = pTmpHead->next;
        pTmpHead->next = pTmp;
        return nIndex + 1;
    }

    bool erase(int nIndex) {
        if (nIndex >= size() || nIndex < 0) {
            return false;
        }
        if (size() == 1) {
            head = NULL;
            return true;
        }
        if (nIndex == 0) {
            pop_front();
            return true;
        }
        ListNode<T>* pTmpHead = head;
        while(nIndex-- > 1) {
            pTmpHead = pTmpHead->next;
        }
        pTmpHead->next = pTmpHead->next->next;
//         ListNode<T>* pTmp = new ListNode<T>();
//         pTmp->next = pTmpHead->next->next;
//         pTmpHead->next = pTmp->next;
        return true;
    }

    int size() {
        int nCnt = 0;
        ListNode<T>* pTmp = head;
        while(pTmp != NULL) {
            pTmp = pTmp->next;
            nCnt++;
        }
        return nCnt;
    }

    int print() {
        int nCnt = 0;
        ListNode<T>* pTmp = head;
        while(pTmp != NULL) {
            cout << pTmp->data << endl;
            pTmp = pTmp->next;
            nCnt++;
        }
        return nCnt;
    }

private:
    ListNode<T>* head;
};

