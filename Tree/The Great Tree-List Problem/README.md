

#Convert BST to Circular Linked List

Example

input:
       
       
       4->left=2
       4->right=6
       
       2->left=1
       2->right=3
       
       6->left=5
       6->right=7
       
       1->left=1->right=NULL
       3->left=3->right=NULL
       5->left=5->right=NULL
       7->left=7->right=NULL
       
       
    
  
Expected output:

HEAD should point to (1)

(head-> prev should point to 7) <-1<->2<->3<->4<->5<->6<->7->(tail next should point to 1)                                    


For further details follow this link
http://cslibrary.stanford.edu/109/TreeListRecursion.html
