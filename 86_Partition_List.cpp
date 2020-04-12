#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * ps = NULL; //small
        ListNode * pl = NULL; //large or small
        ListNode * psf = NULL; //first
        ListNode * plf = NULL; //first
        ListNode * p = head;
        while(p){
            if(p->val < x){
                if(ps == NULL){
                    ps = p;
                    psf = p;
                }
                else{
                    ps->next = p;
                    ps = ps->next;
                }
            }
            else{
                if(plf == NULL){
                    plf = p;
                    if(p==head)
                        head= NULL;
                }
                if(pl == NULL)
                    pl = p;
                else{
                    pl->next = p;
                    pl = pl->next;
                }
            }
            p = p->next;
        }
        if(head == NULL){
            if(psf)
                head = psf;
            else
                head = plf;
        }
            
        if(psf && psf!= head)
            head->next = psf;
        if(pl)
            pl->next = NULL;
        if(plf && ps)
            ps->next = plf;
        return head; 
    }
};