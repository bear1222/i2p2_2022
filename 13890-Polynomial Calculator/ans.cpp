#include "function.h"

double eps = 1e-6;
class Constant : public Function{
	public:
	static Constant *create(double x){
        Constant *now = new Constant;
        now -> val = x;
        return now;
    }
	double eval(double x) override{
        return val;
    }
    private:
    double val;
};

class Variable : public Function{
	public:
	static Variable *create(string){
        Variable *now = new Variable;
        return now;
    }
	double eval(double x) override{
        return x;
    }
};

class Polynomial : public Function{
	public:
	static Polynomial *create(Function *_a, Function *_b){
        Polynomial *now = new Polynomial;
        now -> a = _a, now -> b = _b;
        return now;
    }
	double eval(double x) override{
        double aa = a -> eval(x), bb = b -> eval(x);
        return pow(aa, bb);
    }
    private:
    Function *a, *b;
};

class Arithmetic : public Function{
	public:
	static Arithmetic *create(Function *_a, char c, Function *_b){
        Arithmetic *now = new Arithmetic;
        now -> a = _a, now -> op = c, now -> b = _b;
        return now;
    }
	double eval(double x) override{
        double aa = a -> eval(x), bb = b -> eval(x);
        if(abs(bb) < eps && op == '/'){
            cout << "gg\n";
            exit(0);
        }
        if(op == '+') return aa + bb;
        else if(op == '-') return aa - bb;
        else if(op == '*') return aa * bb;
        else return aa / bb;
    }
    private:
    Function *a, *b;
    char op;
};

class Sin : public Function{
    public:
    static Sin *create(Function *_a){
        Sin *now = new Sin;
        now -> a = _a;
        return now;
    }
    double eval(double x) override{
        double aa = a -> eval(x);
        return sin(aa);
    }
    private:
    Function *a;
};

class Cos : public Function{
    public:
    static Cos *create(Function *_a){
        Cos *now = new Cos;
        now -> a = _a;
        return now;
    }
    double eval(double x) override{
        double aa = a -> eval(x);
        return cos(aa);
    }
    private:
    Function *a;
};

Function* Function::parse(stringstream &ss){
    string s;
    ss >> s;
    if(s == "+" || s == "-" || s == "*" || s == "/"){
        Function *a = parse(ss), *b = parse(ss);
        Function *now = Arithmetic::create(a, s[0], b);
        return now;
    }else if(s[0] == 'x'){
        Function *now = Variable::create(s);
        return now;
    }else if(s == "**"){
        Function *a = parse(ss), *b = parse(ss);
        Function *now = Polynomial::create(a, b);
        return now;
    }else if(s == "sin"){
        Function *a = parse(ss);
        Function *now = Sin::create(a);
        return now;
    }else if(s == "cos"){
        Function *a = parse(ss);
        Function *now = Cos::create(a);
        return now;
    }else{
        Function *now = Constant::create(atoi(s.c_str()));
        return now;
    }
}

