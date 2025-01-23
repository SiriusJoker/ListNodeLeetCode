// ListNodeApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ListNode* find(int value)
    {
        ListNode* currentNode = this;
        while (currentNode->next != nullptr)
        {
            if (currentNode->val == value)
                return currentNode;
            else
                currentNode = currentNode->next;
        }
        if (currentNode->val == value)
            return currentNode;
        else
            return nullptr;
    }
    
};
ListNode* depthSearchRec(ListNode* root, int value)
{
    if (root->val == value)
        return root;
    else
    {
        if (root->next != nullptr)
            return depthSearchRec(root->next, value);
        else
            return nullptr;
    }
}

 class Solution {
public:

    // https://leetcode.com/problems/add-two-numbers/description/

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Defining the 1st place number in the result list as the sum of 1st place numbers of both input lists
        int num1 = l1->val;
        int num2 = l2->val;
        int sum = num1 + num2;
        ListNode* l3 = new ListNode(sum % 10);
        sum /= 10;  // the sum of numbers may exceed 9, so we carry over 1 to add to the next place if needed
        ListNode* l4 = l3;
        while (l1->next != nullptr || l2->next != nullptr || sum > 0) {

            // First case: when both lists have a number at the n-th place, we sum these numbers.

            if (l1->next != nullptr && l2->next != nullptr) {
                l1 = l1->next;
                l2 = l2->next;
                sum += l1->val + l2->val;
                l3->next = new ListNode(sum % 10);
            }
            else {

                // Second and third case: if only one list has a number at the n-th place, we add it along with any carry-over of 1 from the previous sum.

                if (l2->next != nullptr) {
                    l2 = l2->next;
                    sum += l2->val;
                    l3->next = new ListNode(sum % 10);
                }
                else if (l1->next != nullptr) {
                    l1 = l1->next;
                    sum += l1->val;
                    l3->next = new ListNode(sum % 10);
                }
                else {

                    // last case: if neither list has a number at the n-th place but we have a carry-over of 1, we write 1 to the result list.

                    l3->next = new ListNode(sum % 10);
                }
            }
            l3 = l3->next;
            sum /= 10;
        }
        return l4;
    }
};
int main()
{
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = l1;
    l1->next = new ListNode(4);
    l1 = l1->next;
    l1->next = new ListNode(3);

    ListNode* l3 = new ListNode(5);
    ListNode* l4 = l3;
    l3->next = new ListNode(6);
    l3 = l3->next;
    l3->next = new ListNode(4);
    l3 = l3->next;
    l3->next = new ListNode(9);

    Solution s;
    ListNode* res=s.addTwoNumbers(l2, l4);
    int num1 = res->val;
    for (int i = 10; res->next != nullptr; i *= 10) {
        res = res->next;
        num1 += res->val * i;
    }
    std::cout << "=" << "\n";
    std::cout << num1 << "\n";

    if (l2->find(2) != nullptr)
        std::cout << "l2->find(2) != nullptr" << std::endl;
    if (l2->find(4) != nullptr)
        std::cout << "l2->find(4) != nullptr" << std::endl;
    if (l2->find(3) != nullptr)
        std::cout << "l2->find(3) != nullptr" << std::endl;
    if (l2->find(21) == nullptr)
        std::cout << "l2->find(21) = nullptr" << std::endl;

    if (depthSearchRec(l2,2) != nullptr)
        std::cout << "depthSearchRec(l2,2) != nullptr" << std::endl;
    if (depthSearchRec(l2, 4) != nullptr)
        std::cout << "depthSearchRec(l2, 4) != nullptr" << std::endl;
    if (depthSearchRec(l2, 3) != nullptr)
        std::cout << "depthSearchRec(l2, 3) != nullptr" << std::endl;
    if (depthSearchRec(l2, 1) == nullptr)
        std::cout << "depthSearchRec(l2, 1) == nullptr" << std::endl;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
