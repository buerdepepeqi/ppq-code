/*************************************************************************
 * @File Name: merge_k_list.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Sun Apr 13 16:48:11 2025
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <functional>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){};
    ListNode(int x): val(x),next(nullptr){};
    ListNode(int x, ListNode* new_node): val(x),next(new_node){};
};

void PrintList(ListNode* head) {
    ListNode* cur = head;
    while(cur){
        cout << cur->val << endl;
        cur = cur->next;
    }
}

class Solution {
public:
    


    ListNode* merge(ListNode* list1, ListNode* list2) {
        
        ListNode ans{}; 
        ListNode* head = &ans;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        
        if(list1) head->next = list1;
        if(list2) head->next = list2;
        printf("test\n");
        PrintList(ans.next);
        printf("test_end\n");
        return ans.next;

    }

    ListNode* mergeK(vector<ListNode*>& lists, int l, int r){
        if(l>r) return nullptr;
        if(l==r) {
            return lists[l];
        }
        int mid = l+(r-l) / 2;
        cout << "l: " << l << ", r: "  << r << ", mid:" << mid <<endl;
        ListNode* left = mergeK(lists,l,mid);
        ListNode* right = mergeK(lists,mid+1,r);
        
        
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeK(lists, 0 , lists.size()-1);
    }


    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt = 0;
        ListNode* preA = list1;
        for(int i = 0;i < a - 1; i++) {
            preA = preA->next;
        }
        ListNode* preB = preA;
        for(int i = 0; i < b - a + 2; i++) {
            preB = preB->next;
        }
        preA->next = list2;
        while(list2->next != nullptr) {
            list2 = list2->next;
        }
        list2->next=preB;
        return list1;
    }
};


int main()
{

    Solution solve;
    vector<ListNode*> lists;
    
    ListNode* val1 = new ListNode(5);
    ListNode* val2 = new ListNode(4, val1);
    ListNode* val3 = new ListNode(1, val2);
    lists.push_back(val3);

    ListNode* val4 = new ListNode(4);
    ListNode* val5 = new ListNode(3,val4);
    ListNode* val6 = new ListNode(1,val5);
    lists.push_back(val6);

    

    ListNode* val7 = new ListNode(6);
    ListNode* val8 = new ListNode(2,val7);
    lists.push_back(val8);
    for(auto it: lists) {
        PrintList(it);
    }

    ListNode* ans = solve.mergeKLists(lists);
    PrintList(ans);

    return 0;
}

