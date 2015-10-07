class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode superhead(0);
		superhead.next = head;
		ListNode* prev = &superhead;
		// prev->node1->node2->next
		// prev->node2->node1->next
		//               prev
		while (prev) {
			ListNode* node1 = prev->next;
			if (!node1)
				break;
			ListNode* node2 = node1->next;
			if (!node2)
				break;
			ListNode* next = node2->next;
			prev->next = node2;
			node2->next = node1;
			node1->next = next;
			prev = node1;
		}
		return superhead.next;
	}
};


