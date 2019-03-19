//
//  main.cpp
//  Test_CPP
//
//  Created by Felix on 2019/3/13.
//  Copyright © 2019 Felix. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool complare(int a,int b){
    
    return a>b;
}

class Solution {
public:
    
    /**
     反转链表
     
     @param head node
     @return head
     */
    ListNode* reverseList(ListNode* head) {
        
        if(NULL == head || NULL == head->next)
            return head;
        ListNode * p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return p;
    }
    
    /**
     反转链表
     
     @param head node
     @return head
     */
    ListNode* reverseList2(ListNode* head) {
        
        
        ListNode *newHead = NULL;
        
        while (head) {
            
            ListNode *next = head -> next;
            head -> next = newHead;
            newHead = head;
            head = next;
        }
        
        return newHead;
    }
    
    
    /**
     是否有环
     
     @param head node
     @return bool
     */
    bool hasCycle(ListNode *head) {
        
        if (nullptr == head || nullptr == head -> next) {
            return  false;
        }
        
        ListNode *slow = head, *fast = head -> next;
        
        while (fast && fast -> next) {
            
            if (slow == fast) {
                
                return  true;
            }
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return false;
    }
    
    
    /**
     入环口
     
     @param head node
     @return node
     */
    ListNode *detectCycle(ListNode *head) {
        
        if (nullptr == head || nullptr == head -> next) {
            return nullptr;
        }
        
        ListNode *slow = head, *fast = head;
        
        while (fast && fast -> next) {
            
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (slow == fast) {
                
                fast = head;
                
                while (fast != slow) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return fast;
            }
        }
        
        
        return nullptr;
    }
    
    
    /**
     长度
     
     @param node node
     @return len
     */
    int getLinkListLength(ListNode *node) {
        
        if (node == nullptr) {
            return 0;
        }
        
        if (node -> next == nullptr) {
            return 1;
        }
        
        int length = 0;
        
        while (node != nullptr) {
            node = node -> next;
            length ++;
        }
        
        return length;
    }
    
    
    /**
     单链表交点

     @param headA 1
     @param headB 2
     @return head
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int aLength = getLinkListLength(headA);
        int bLength = getLinkListLength(headB);
        
        int distance = abs(aLength - bLength);
        
        if (aLength > bLength) {
            std::swap(headA, headB);
        }
        
        ListNode *p1 = headA,*p2 = headB;
        
        while (distance --) {
            p2 = p2 -> next;
        }
        
        while (p1 != nullptr && p2 != nullptr) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        return nullptr;
    }
    
    
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {

        ListNode *pA = headA, *pB = headB;

        while (pA != pB) {
            
            pA = pA != nullptr ? pA -> next : headB;
            pB = pB != nullptr ? pB -> next : headA;
        }
        
        return pA;
    }
    
    
    /**
     反转二叉树

     @param root node
     @return node
     */
    TreeNode* invertTree(TreeNode* root) {
        
        if (nullptr == root) {
            return root;
        }
        std::swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
    
    TreeNode* invertTree2(TreeNode* root) {
        
        if (nullptr == root) {
            return root;
        }
        
        std::vector<TreeNode *> nodeList;
        
        nodeList.push_back(root);
        
        while (nodeList.size() > 0) {
            
            TreeNode *current = nodeList.back();
            nodeList.pop_back();
            std::swap(current -> left, current -> right);
            if (current -> left) {
                nodeList.push_back(current -> left);
            }
            if (current -> right) {
                nodeList.push_back(current -> right);
            }
        }
        
        return root;
    }
    
    
    /**
     中间节点

     @param head node
     @return node
     */
    ListNode* middleNode(ListNode* head) {
        if (nullptr == head) {
            return head;
        }
        
        if (nullptr == head -> next) {
            return head;
        }
        
        ListNode *slow = head, *fast = head;
        
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        if (fast && fast -> next) {
            return slow -> next;
        }
        
        return slow;
    }
    
    
    /**
     合并有序链表

     @param l1 head
     @param l2 head
     @return head
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *left = l1;
        ListNode *right = l2;
        
        if (left == nullptr) {
            return right;
        }
        
        if (right == nullptr) {
            return left;
        }
        
        if (left -> val > right -> val) {
            std::swap(left, right);
        }
        
        ListNode *head = left;
        left = left -> next;
        ListNode *res = head;
        
        while (left && right) {
            
            if (left -> val > right -> val) {

                head -> next = right;
                right = right -> next;
                
            }else {
                
                head -> next = left;
                left = left -> next;

            }
            
            head = head -> next;
        }
        
        if (left != nullptr) {
            head -> next = left;
        }
        
        if (right != nullptr) {
            head -> next = right;
        }
        
        return res;
    }
    
    
    /**
     层次遍历二叉树

     @param root node
     @return list
     */
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        
        std::vector<std::vector<int>> result;
        
        if (nullptr == root) {
            return result;
        }
        
        std::queue<TreeNode *> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            
            std::vector<int> tmp;
            auto queueSize = queue.size();
            
            while (queueSize--) {
                
                TreeNode *node = queue.front();
                queue.pop();
                if (node -> left) {
                    queue.push(node -> left);
                }
                if (node -> right) {
                    queue.push(node -> right);
                }
                tmp.push_back(node->val);
            }
            
            result.push_back(tmp);
        }
        
        return result;
    }
    
    
    /**
     前序遍历二叉树

     @param root root
     @return node
     */
    std::vector<int> preorderTraversal(TreeNode* root) {
        
        std::vector<int> list;
        
        if (nullptr == root) return list;
        
        list.push_back(root -> val);
        
        std::vector<int> left = preorderTraversal(root -> left);
        
        std::vector<int> right = preorderTraversal(root -> right);
        
        list.insert(list.end(), left.begin(), left.end());
        list.insert(list.end(), right.begin(), right.end());
        
        return list;
    }
    
    
    std::vector<int> preorderTraversal2(TreeNode* root) {
        
        std::vector<int> rest;
        
        if (nullptr == root) return rest;
        
        std::vector<TreeNode *> queue;
        
        queue.push_back(root);
        
        while (!queue.empty()) {
            
            TreeNode *node = queue.back();
            queue.pop_back();
            rest.push_back(node -> val);
            if (node -> right) queue.push_back(node -> right);
            if (node -> left) queue.push_back(node -> left);
        }
        
        return rest;
    }
    
    
    /**
     一棵树是否为子树

     @param s s
     @param t t
     @return bool
     */
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if(isSame(s,t)) return true;
        return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    bool isSame(TreeNode* s,TreeNode* t){
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val!=t->val) return false;
        return isSame(s->left,t->left) && isSame(s->right,t->right);
    }
    
    
    /**
     冒泡
     时间复杂度 O(n^2)
     空间复杂度 O(n)

     @param nums array
     */
    void bubbleSort(std::vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                }
            }
        }
    }
    
    
    /**
     插入排序
     时间复杂度 O(n^2)
     空间复杂度 O(n)

     @param nums array
     */
    void insertSort(std::vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j > 0; j--) {
                if (nums[j - 1] > nums[j]) {
                    int tmp = nums[j];
                    nums[j] = nums[j - 1];
                    nums[j - 1] = tmp;
                }
            }
        }
    }
    
    
    /**
     选择排序
     时间复杂度 O(n^2)
     空间复杂度 O(n)
     
     @param nums array
     */
    void selectSort(std::vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            int min = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            int tmp = nums[i];
            nums[i] = nums[min];
            nums[min] = tmp;
        }
    }
    
    
    /**
     希尔排序（递减增量排序）
     时间复杂度 平均 O(nlogn)
     空间复杂度 O(n)
     
     @param nums array
     */
    void shellSort(std::vector<int>& nums) {
        
        unsigned int gap = (unsigned int)nums.size() / 2;
        
        for (; gap > 0; gap = gap / 2) {

            for (int i = gap; i < nums.size(); i++) {

                for (int j = i - gap; j >= 0; j -= gap) {
                    
                    if (nums[j] > nums[j + gap]) {
                        
                        int tmp = nums[j];
                        nums[j] = nums[j + gap];
                        nums[j + gap] = tmp;
                    }
                }
            }
        }
    }
    
    
    /**
     归并排序

     @param nums array
     */
    void mergeSort(std::vector<int>& nums) {
        
    }
    
    /**
     找到第k大的值

     @param nums nums
     @param k k
     @return value
     */
    int findKthLargest(std::vector<int>& nums, int k) {
        
        
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        
        return nums[k-1];
    }
    
//    int findKthLargest1(std::vector<int>& nums, int k) {
//
//        std::vector<int> array;
//
//        for (int i : nums) {
//            if (array.size() > k) {
//
//            }
//        }
//
//        return 1;
//    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<int> list = {5, 8, 12, 3, 256, 918, 99, 3, 7};
    
//    Solution().bubbleSort(list);

    Solution().shellSort(list);
    
    for (auto i : list) {
        std::cout<< i << ", ";
    }
    
    std::cout<<std::endl;
    std::cout<<"CorrectAnswerIs :"<<std::endl;
    std::cout<<"3, 3, 5, 7, 8, 12, 99, 256, 918, "<<std::endl;
    
    return 0;
}
