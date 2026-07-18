class Solution {
public:
    bool isValid(string s) {

        // stack banaya hai jisme opening brackets store karenge
        stack<char> st;

        // string ke har character ko ek-ek karke traverse karenge
        for (char ch : s) {

            // agar opening bracket mila to stack me push kar do
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // warna closing bracket hai
            else {

                // agar stack empty hai matlab opening bracket mila hi nahi
                if (st.empty()) {
                    return false;
                }

                // stack ke top element ko check karenge
                char top = st.top();

                // agar matching pair hai to opening bracket hata do
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {

                    st.pop();   // matched pair remove kar diya
                }

                // agar matching nahi hui to string invalid hai
                else {
                    return false;
                }
            }
        }

        // agar saare brackets match ho gaye honge to stack empty hoga
        // empty -> true
        // nahi empty -> false
        return st.empty();
    }
};