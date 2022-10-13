#include<iostream>
using namespace std;
class Debug
{
public:

    constexpr Debug(bool b=true) : hw(b), io(b), other(b){}
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o){}
    constexpr bool any(){return hw || io || other;}
    void set_io(bool b){io=b;}
    void set_hw(bool b){hw=b;}
private:
    bool hw;
    bool io;
    bool other;
};
class Account
{
public:
    void calculate()
    {
        amount+=amount*interestRate;
    }
    static double rate()
    {
        return interestRate;
    }
    static void rate(double);
private:
    std :: string owner;
    double amount;
    static double interestRate;
    static double initRate;
};