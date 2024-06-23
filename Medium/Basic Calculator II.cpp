#include<bits/stdc++.h>

// Link to the Problem : https://leetcode.com/problems/basic-calculator-ii/
// Difficulty : Medium

/* Quick Solution - Coder's Solution */
class Solution {
public:
    int calculate(std::string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
};

/* Standard Extendable Design - Programmer's Approach */
class Solution {
public:
    
    std::stack<std::string> s;
    std::vector<std::string> expression;
    std::vector<std::string> postfixed;  
    std::stack<double> S;// Stack for Calculation
    std::unordered_map<std::string,char> operators;
    
    Solution () {
        operators["+"] = '+';
        operators["-"] = '-';
        operators["_"] = '_';
        operators["*"] = '*';
        operators["/"] = '/';
    }
    
    int calculate(std::string s) {
        parse_Exp(s);
        infix_To_Postfix();
        int ans = (int)evalpostfix();
        return ans;    
    }
    
    int string_To_Number (std::string num) {
           int r = 0, i = 0, radix = 10, n = num.length(); 
           bool is_less_than_1 = false;
           while (i<n) {
            if (num[i]=='.') { is_less_than_1 = true; radix = 1; }
            else if ( !is_less_than_1 ) { r = r*radix + (num[i]-'0'); }
            else { radix /= 10; r += (num[i]-'0')*radix; }
            i++;
           }
           return r;
    }
    
    void parse_Exp (std::string exp) {

         int i = 0, n = exp.length();
         std::string token;

         while (i<n) {
            if ( isalnum(exp[i]) || exp[i] == '.' ) { token += exp[i]; }
            else if (exp[i] != 32) { 
                if ( !token.empty() ) { 
                    expression.push_back(token);  
                    token.clear();
                }
                if (exp[i] == '-' && (i == 0 || !isalnum(exp[i-1]) && exp[i-1] != ')')) { token += '_'; }  // Check for Unary minus
                else { token += exp[i]; }
                expression.push_back(token);
                token.clear();
            }
            i++;
         }
         if (!token.empty() && token != " ") { expression.push_back(token); } 
         token.clear();
    }
    
    int order (std::string op) {
        // For Basic Operators
        if (op == "+" || op == "-") { return 1; }
        if (op == "/" || op == "*" || op == "%") { return 2; }
        if (op == "^" || op == "(") { return 3; }
        // For Numbers - 0
        if (isdigit(op[0])) { return 0; }
        // For Functions and Unary operators - 4+
        if (op == "_") { return 4; }
        if (isalpha(op[0])) { return 5; }
        if (op == ")") { return -1; } 
        return 0;
    }
    
    void infix_To_Postfix () {

        std::string temp; int n = expression.size();

        for (int i=0;i<n;i++) {
         if(order(expression[i]) == 0) { postfixed.push_back(expression[i]); }
         else if(order(expression[i]) == 1 || order(expression[i]) == 2) 
         { 
                 if(s.empty()){s.push(expression[i]); continue;}
                 if(order(s.top())>=order(expression[i]))
                 {
                  while ((!s.empty() && s.top() != "(") && order(expression[i]) <= order(s.top()))
                  {
                    temp = s.top(); s.pop();
                    postfixed.push_back(temp);
                  }
                   s.push(expression[i]);
                 }
                 else { s.push(expression[i]); }
         }
         else if (order(expression[i]) >= 3) { s.push(expression[i]); }
         else {
                while (s.top() != "(") {
                    temp = s.top(); s.pop();
                    postfixed.push_back(temp);
                  }
                s.pop();
         }  
        }
        while (!s.empty()) {
          temp = s.top(); s.pop();
          postfixed.push_back(temp);
        }
    }
    
    int evalpostfix () {

        int res, l, r; 
        int n = postfixed.size();

        for(int i=0;i<n;i++) {
            if(order(postfixed[i]) == 0) { 
                S.push(((string_To_Number(postfixed[i])))); 
            }
            else {
                if (order(postfixed[i]) < 4) {
                  r = S.top(); S.pop();
                  l = S.top(); S.pop();
                  switch (operators[postfixed[i]]) {
                        case '+' : {res = l+r; break;}
                        case '-' : {res = l-r; break;}
                        case '*' : {res = l*r; break;}
                        case '/' : {res = l/r; break;}
                        default : return 0;
                  }
                }
                else {
                    l = S.top(); S.pop();
                    switch (operators[postfixed[i]]) {
                        case '_' : { res = -l; break; }
                        default: return 0;
                    }
                }
                S.push(res);
            }
        }
        return S.top();
    }
};