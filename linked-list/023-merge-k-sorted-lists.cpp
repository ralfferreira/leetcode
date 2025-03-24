/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.empty())
                return nullptr;
    
            while(lists.size()>1)
            {
                vector<ListNode*> mergedList;
                for(int i=0; i<lists.size(); i+=2)
                {
                    ListNode* l1 = lists[i];
                    ListNode* l2 = nullptr;
                    if(i+1<lists.size()) {
                        l2=lists[i + 1];
                    }
                    mergedList.push_back(mergeLists(l1,l2));
                }
                lists=move(mergedList);
            }
            return lists[0];
        }
    
    private:
        ListNode* mergeLists(ListNode* list1, ListNode* list2) {
                ListNode *dummy = new ListNode(0);
                ListNode *tail = dummy;
        
                while(list1 && list2)
                {
                    if(list1->val > list2->val)
                    {
                        tail->next=list2;
                        list2=list2->next;
                    }
                    else
                    {
                        tail->next=list1;
                        list1=list1->next;
                    }
                    tail=tail->next;
                }
                if (list1!=nullptr)
                    tail->next = list1;
                else
                    tail->next = list2;
        
                ListNode *head=dummy->next;
                delete dummy;
                return head;
            }
    };