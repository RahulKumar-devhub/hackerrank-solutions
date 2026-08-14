// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem?isFullScreen=true
// Problem     Abstract Classes - Polymorphism
// Difficulty  Hard
// Subdomain   Classes
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-14, 09:00 p.m.
// ──────────────────────────────────────────────────


class LRUCache : public Cache {
public:
    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }

    void set(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            // Remove node from current position
            if (node->prev)
                node->prev->next = node->next;
            else
                head = node->next;

            if (node->next)
                node->next->prev = node->prev;
            else
                tail = node->prev;

            // Move to front
            node->next = head;
            node->prev = NULL;

            if (head)
                head->prev = node;
            else
                tail = node;

            head = node;
            return;
        }

        // Cache is full
        if (mp.size() == cp) {
            Node* temp = tail;

            mp.erase(temp->key);

            tail = temp->prev;

            if (tail)
                tail->next = NULL;
            else
                head = NULL;

            delete temp;
        }

        // Create new node at front
        Node* node = new Node(key, value);

        node->next = head;
        node->prev = NULL;

        if (head)
            head->prev = node;
        else
            tail = node;

        head = node;

        mp[key] = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        // Move accessed node to front
        if (node != head) {
            if (node->prev)
                node->prev->next = node->next;

            if (node->next)
                node->next->prev = node->prev;
            else
                tail = node->prev;

            node->prev = NULL;
            node->next = head;

            head->prev = node;
            head = node;
        }

        return node->value;
    }
};
