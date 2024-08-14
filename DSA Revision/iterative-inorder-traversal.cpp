vector < int > inOrder(Node * root) {
   // Your code here
   vector < int > ans;
   stack < Node * > st;

   while (true) {
      if (root != NULL) {
         st.push(root);
         root = root -> left;
      } else {
         if (st.empty()) break;
         root = st.top();
         st.pop();

         ans.push_back(root -> data);
         root = root -> right;
      }
   }

   return ans;
}