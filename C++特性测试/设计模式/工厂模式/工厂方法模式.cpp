#include <iostream>
#include <vector>
using namespace std;

// Here is the product class
class Operation
{
public:
    int var1, var2;
    virtual double GetResult()
    {
        double res = 0;
        return res;
    }
};

class Add_Operation : public Operation
{
public:
    virtual double GetResult()
    {
        return var1 + var2;
    }
};

class Sub_Operation : public Operation
{
public:
    virtual double GetResult()
    {
        return var1 - var2;
    }
};

class Mul_Operation : public Operation
{
public:
    virtual double GetResult()
    {
        return var1 * var2;
    }
};

class Div_Operation : public Operation
{
public:
    virtual double GetResult()
    {
        return var1 / var2;
    }
};

class Factory
{
public:
    virtual Operation *CreateProduct() = 0; // 纯虚函数
};

class Add_Factory : public Factory
{
public:
    Operation *CreateProduct()
    {
        return new Add_Operation();
    }
};

class Sub_Factory : public Factory
{
public:
    Operation *CreateProduct()
    {
        return new Sub_Operation();
    }
};

class Mul_Factory : public Factory
{
public:
    Operation *CreateProduct()
    {
        return new Mul_Operation();
    }
};

class Div_Factory : public Factory
{
public:
    Operation *CreateProduct()
    {
        return new Div_Operation();
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Add_Factory *p_fac = new Add_Factory();
    Operation *p_pro = p_fac->CreateProduct();
    p_pro->var1 = a;
    p_pro->var2 = b;
    cout << p_pro->GetResult() << endl;

    Mul_Factory *p_fac1 = new Mul_Factory();
    Operation *p_pro1 = p_fac1->CreateProduct();
    p_pro1->var1 = a;
    p_pro1->var2 = b;
    cout << p_pro1->GetResult() << endl;

    return 0;
}

// 作者：力扣 (LeetCode)
// 链接：https://leetcode.cn/leetbook/read/cmian-shi-tu-po/v05n1e/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。