#include "std_lib_facilities.h"

double expression();

class Token{
    public:
    double value;
    char kind;
    Token (char ch): kind(ch), value(0) {}
    Token (char ch, double val): kind(ch), value(val) {}
};

class Token_stream{
public:
    Token_stream(); //make a Token_stream that reads from cin
    Token get();  // get a Token
    void putback(Token t);  // put a token back
private:
    bool full ; // is there a token in the buffer?
    Token buffer; // here is where we keep a Token using putback
};
Token_stream::Token_stream(): full(false), buffer(0) {}

void Token_stream::putback(Token t){
    if(full) error("putback() into a full buffer");
    buffer = t; //copy t to the buffer
    full = true; // buffer is now full
}
Token Token_stream::get(){
    if(full){// if we already have a token in the buffer!
        full = false; // remove that Token from the buffer
        return buffer;
    }
    char ch;
    cin>>ch;
    switch(ch){
        case'=':
        case'x':
        case'(': case')': case'*': case'/': case'+': case'-':
            return Token{ch}; // let each character represent itself
        case'.':
        case'0': case'1': case'2': case'3': case'4':
        case'5': case'6': case'7': case'8': case'9':
        {
            cin.putback(ch); //put digit back into the input stream
            double val;
            cin>>val;   //read a floating point number
            return Token{'8', val};
        }
        default:
            error("Bad Token");
    }
}
Token_stream ts;  // a token stream called ts


double primary(){
    Token t = ts.get();
    switch(t.kind){
        case'(': //handle '(' expression ')'
        {
            double d = expression();
            t=ts.get();
            if (t.kind!='(') error(" '(' expected");
        }
        case'8':
            return t.value; //return the number's value
        default:
            error ("primary expected");
    }
}
double term(){
    double left = primary();
    Token t = ts.get();  //get the next Token from the Token stream

    while (true){
        switch(t.kind){
            case'*':
                left*= primary();
                t= ts.get();
                break;
            case'/':
            {
                double d = primary();
                if (d==0) error("divide by zero");
                left/=d;
                t=ts.get();
                break;
            }
            default:
                ts.putback(t);  //put t back into Token stream
                return left;
        }
    }
}
double expression(){
    double left = term();
    Token t = ts.get();
    while (true){
        switch(t.kind){
            case'+':
                left += term();
                t=ts.get();
                break;
            case'-':
                left-=term();
                t=ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}
int main() {
    try {
        double val = 0;
        cout << "Welcome to our simple calculator(:\nPlease enter expression using floating-point numbers.\nYou can use (+,-,* and/) use '=' to print the value and 'x' to Exit" <<'\n';
        while (cin) {
            Token t = ts.get();
            if (t.kind == 'x') break;
            if (t.kind == '=')
                cout  << val << endl;
            else
                ts.putback(t);

            val = expression();
        }
        return 0;
    } catch (exception &e) {
        cerr << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "exception\n";
        return 2;
    }
}
