#include "./RPN.hpp"

int is_operator(std::string str, int& op)
{
    if(str == "*" || str == "/" || str == "+" || str == "-" )
    {
            op++;
            return 1;
    }
    return 0;
}

void push_stack(std::string str)
{
    int count_digit = 0;
    int count_op = 0;
    std::stack<float> st;
    std::stringstream os(str);
    std::string  word;
    while(os >> word)
    {
        if(word.length() != 1 || (isdigit(word[0]) == 0 && is_operator(word, count_op) != 1))
            printerror();
        else if((isdigit(word[0]) != 1 && st.size() == 0))
            printerror();
        else if(isdigit(word[0]))
        {
            st.push(atol(word.c_str()));
            count_digit++;
        }
        else if(st.size() >= 2 &&  isdigit(word[0]) != 1)
            reverse_polishNotation(&st, word);     
    }
    if(count_digit - count_op != 1 || st.size() != 1)
    {
        printerror();
    }
    std::cout << st.top() << std::endl;

}
void printerror()
{
    std::cout << "Error: " << " bad input" << std::endl;
    exit(0);
}

int reverse_polishNotation(std::stack<float> *st, std::string  op)
{
    float a = st->top();
    st->pop();
    float b = st->top();
    st->pop();
    switch (op[0])
    {
    case '+':
        st->push(b + a);
        break;
    case '-':
         st->push(b - a);
        break;
    case '*':
         st->push(b * a);
        break;
    case '/':
        if(a == 0)
            printerror();
        st->push(b / a);
        break;
    default:
        break;
    }
    return 0;
}
