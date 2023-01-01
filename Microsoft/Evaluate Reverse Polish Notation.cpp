//Leetcode 150
class Solution {
public:
  //Evaluating postfix expression
    long long evalRPN(vector<string>& tokens) {
        stack<long long> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
          //atleast two numbers should be there to evaluate the expression
            if(st.size()>1 && (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")){
              //operand order 
                long long op2=st.top(); st.pop();
                long long op1=st.top(); st.pop();
                if(tokens[i]=="+"){
                    long long res=op1+op2;
                    st.push(res);
                }
                else if(tokens[i]=="-"){
                    long long res=op1-op2;
                    st.push(res);
                }
                else if(tokens[i]=="*"){
                    long long res=op1*op2;
                    st.push(res);
                }
                else if(tokens[i]=="/"){
                    long long res=op1/op2;
                    st.push(res);
                }
            }
            else{
              //numbers push in stack
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
