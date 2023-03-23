#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    string val;
    TreeNode* l, * r;
    TreeNode(string c)
        : val(c) {
        l = NULL;
        r = NULL;
    }
};

void read(vector<string>& in);
vector<string> change(const vector<string>& infix);
TreeNode* CreatTree(const vector<string>& sufix);
int subOrderTraverse(TreeNode* node);
bool isNum(char c);

void read(vector<string>& in) {
    char c;
    string s;  // 存数字
    while (scanf("%c", &c) != EOF) {
        if (c != '=') {
            if (isNum(c)) {
                s += c;
            }
            else {
                if (s.length() != 0) {
                    in.emplace_back(s);
                    s.clear();
                }
                if (c != ' ')
                    in.emplace_back(1, c);
            }
        }
        else {
            break;
        }
    }
}

int priority(char c) //运算符的优先级
{
    switch (c) {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}
bool isNum(char c) 
{
    return c >= '0' && c <= '9';
}
vector<string> change(const vector<string>& infix) {
    int len = infix.size();
    vector<string> sufix;
    stack<char> st;
 
    for (int i = 0; i < len; i++) {
        if (isNum(infix[i][0])) 
            sufix.emplace_back(infix[i]);
        else if (infix[i][0] == '(')
            st.emplace(infix[i][0]);
        else if (infix[i][0] == ')') {
            while (!st.empty() && st.top() != '(') {
                sufix.emplace_back(string(1, st.top()));  // char转string
                st.pop();
            }
            st.pop();
        }
        else {  
            while (!st.empty() && priority(infix[i][0]) <= priority(st.top())) {
                sufix.emplace_back(string(1, st.top()));
                st.pop();
            }
            st.emplace(infix[i][0]);
        }
    }
    while (!st.empty()) {
        sufix.emplace_back(string(1, st.top()));
        st.pop();
    }
    return sufix;
}

TreeNode* CreatTree(const vector<string>& sufix) {
    stack<TreeNode*> st;

    for (auto c : sufix) {
        if (isNum(c[0]))
            st.emplace(new TreeNode(c));
        else {
            TreeNode* tmp = new TreeNode(c);
            tmp->r = st.top();
            st.pop();
            tmp->l = st.top();
            st.pop();
            st.emplace(tmp);
        }
    }
    return st.top();
}

int subOrderTraverse(TreeNode* node) {
    if (isNum(node->val[0]))
        return stoi(node->val);
    int num1 = subOrderTraverse(node->l);
    int num2 = subOrderTraverse(node->r);
    switch (node->val[0]) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default:
        return 0;
    }
}

int main() {
    vector<string> infix;
    read(infix);
    auto sufix = change(infix);
    TreeNode* tree = CreatTree(sufix);
    printf("%c %c %c\n", tree->val[0], tree->l->val[0], tree->r->val[0]);
    printf("%d", subOrderTraverse(tree));
    system("pause");
    return 0;
}