#include "function.h"

bool xxx;
double eps = 1e-6;
class Constant : public Function{
	public:
	static Constant *create(double x){
        Constant *now = new Constant;
        now -> val = x;
        return now;
    }
    Function *differential() override{
        return Constant::create(0);
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
    Function *differential() override{
        return Constant::create(1);
    }
	double eval(double x) override{
        xxx = 1;
        return x;
    }
};

class Arithmetic : public Function{
	public:
	static Arithmetic *create(Function *_a, char c, Function *_b){
        Arithmetic *now = new Arithmetic;
        now -> a = _a, now -> op = c, now -> b = _b;
        return now;
    }
    Function *differential() override{
        Function *aa = a -> differential(), *bb = b -> differential();
        if(op == '+' || op == '-') return Arithmetic::create(aa, op, bb); 
        else if(op == '*') return Arithmetic::create(Arithmetic::create(aa, '*', b), '+', Arithmetic::create(a, '*', bb));
        else{
            Function *b2 = Arithmetic::create(b, '*', b), 
                     *on = Arithmetic::create(Arithmetic::create(aa, '*', b), '-', Arithmetic::create(a, '*', bb));
            return Arithmetic::create(on, '/', b2);
        }
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

class Polynomial : public Function{
	public:
	static Polynomial *create(Function *_a, Function *_b){
        Polynomial *now = new Polynomial;
        now -> a = _a, now -> b = _b;
        return now;
    }
    Function *differential() override{
        // b * a^(b - 1) * a'(x)
        Function *aa = a -> differential(), *b_1 = Arithmetic::create(b, '-', Constant::create(1));
        return Arithmetic::create(b, '*', Arithmetic::create(Polynomial::create(a, b_1), '*', aa));
    }
	double eval(double x) override{
        double aa = a -> eval(x);
        xxx = 0;
        double bb = b -> eval(x);
        if(xxx){
            cout << "gg\n";
            exit(0);
        }
        return pow(aa, bb);
    }
    private:
    Function *a, *b;
};

class Sin : public Function{
    public:
    static Sin *create(Function *_a){
        Sin *now = new Sin;
        now -> a = _a;
        return now;
    }
    Function *differential() override;
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
    Function *differential() override{
        Function *aa = this -> a -> differential();
        return Arithmetic::create(Arithmetic::create(Constant::create(0), '-', Sin::create(this -> a)), '*', aa);
    }
    double eval(double x) override{
        double aa = a -> eval(x);
        return cos(aa);
    }
    private:
    Function *a;
};

Function* Sin::differential(){
    Function *aa = this -> a -> differential();
    return Arithmetic::create(Cos::create(this -> a), '*', aa);
}

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
