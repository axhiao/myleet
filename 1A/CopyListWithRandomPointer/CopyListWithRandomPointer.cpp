#include <iostream>
#include <cassert>

using namespace std;


struct RandomListNode;
class Solution;

int main()
{
	return 0;
}



/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL){}
};


class Solution
{
public:
	Solution(){}
	~Solution(){}
	RandomListNode* copyRandomList(RandomListNode* head);
};


/**
 * @param head: The head of linked list with a random pointer.
 * @return: A new head of a deep copy of the list.
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head)
{
	if (head == NULL)
		return NULL;

	RandomListNode* cur = head;
	// 1st traverse
	while(cur)
	{
		RandomListNode* rln = new RandomListNode(cur->label);
		rln->next = cur->next;
		cur->next = rln;
		cur = cur->next->next;
	}
	// 2nd traverse, set the random pointer of the copied node
	cur = head;
	while(cur)
	{
		if (cur->random)
		{
			cur->next->random = cur->random->next;			
		}
		else
		{
			cur->next->random = NULL;
		}
		cur = cur->next->next;
	}
	// 3rd traverse, separate the linkedlist

	RandomListNode *resHead, *res;
	cur = head;
	resHead = cur->next;
	res = resHead;
	while (cur && res->next)
	{
		cur->next = res->next;
		res->next = res->next->next;

		cur = cur->next;
		res = res->next;
	}

	cur->next = NULL;
	res->next = NULL;

	return resHead;
}
