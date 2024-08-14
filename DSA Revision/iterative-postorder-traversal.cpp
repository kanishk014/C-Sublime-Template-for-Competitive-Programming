vector < int > postOrder(Node * root) {
   // Your code here
   vector < int > ans;
   stack < Node * > st;

   while (root != NULL or st.empty() == false) {
      if (root != NULL) {
         st.push(root);
         root = root -> left;
      } else {
         Node * temp = st.top() -> right;

         if (temp == NULL) {
            temp = st.top();
            st.pop();

            ans.push_back(temp -> data);

            while (st.empty() == false and st.top() -> right == temp) {
               temp = st.top();
               st.pop();

               ans.push_back(temp -> data);
            }
         } else root = temp;
      }
   }

   return ans;
}