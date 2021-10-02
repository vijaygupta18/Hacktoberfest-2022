ListNode *mergetwolists(ListNode *l1, ListNode *l2) {

	if (l1 == NULL)  return l2;
	if (l2 == NULL)  return l1;

	if (l1->val > l2->val)  swap(l1, l2);
//as the individual lists are sorted so  smallest one of the first node will be the first node of merged list 
	ListNode *res = l1;

	while (l1 && l2) {

		ListNode *temp = NULL;

		while (l1 && l1->val < l2->val) {
			temp = l1;
			l1 = l1->next;
		}

		temp->next = l2;    //we will attach the next link with l2 as it is less in value
		swap(l1, l2);   //as we always doing through l1,so l1 should be smallest
	}
}
