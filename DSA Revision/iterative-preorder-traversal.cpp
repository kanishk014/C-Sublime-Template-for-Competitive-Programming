vector < int > preorder(Node * root) {
   // Your code here
   vector < int > ans;

   if (root == NULL) return ans;

   stack < Node * > st;
   st.push(root);

   while (st.empty() == false) {
      Node * node = st.top();
      st.pop();

      ans.push_back(node -> data);

      if (node -> right != NULL) {
         st.push(node -> right);
      }

      if (node -> left != NULL) {
         st.push(node -> left);
      }
   }

   return ans;
}