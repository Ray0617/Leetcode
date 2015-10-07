/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return;
        vector<ListNode*> stack;
        ListNode* node = head;
        while (node != nullptr) {
            stack.push_back(node);
            node = node->next;
        }
        for (unsigned i = 0; i < stack.size(); i++) {
            if (i < stack.size() / 2)
                stack[i]->next = stack[stack.size() - 1 - i];
            else
                stack[i]->next = stack[stack.size() - i];
        }
        stack[stack.size()/2]->next = nullptr;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head)
			return;
		ListNode* fast = head;
		ListNode* mid = head;
		while (fast != nullptr) {
			fast = fast->next;
			if (fast) {
				fast = fast->next;
				mid = mid->next;
			}
		}
		
		ListNode superhead(0);
		superhead.next = mid->next;
		mid->next = nullptr;
		ListNode* prev = &superhead;
        ListNode* node = prev->next;
		while (node) {
			ListNode* next = node->next;
			node->next = prev;
			prev = node;
			node = next;
		}
		if (superhead.next)
			superhead.next->next = nullptr;
		else
		    prev = nullptr;

		// merge head & prev
		ListNode* tail = &superhead;
		while (head || prev) {
			if (head) {
				tail->next = head;
				tail = tail->next;
				head = head->next;
			}
			if (prev) {
				tail->next = prev;a
				tail = tail->next;
				prev = prev->next;
			}
		}
		tail->next = nullptr;
	}
};


