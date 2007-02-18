#include "Charcter.h"

using namespace util;
using namespace monash;

Charcter::Charcter(const String& value, uint32_t lineno /* = 0 */) : lineno_(lineno)
{
    if (value == "#\\space")
    {
        value_ = ' ';
    }
    else if (value == "#\\newline")
    {
        value_ = '\n';
    }
    else
    {
        value_ = value[2];
    }
}

Charcter::Charcter(char value, uint32_t lineno /* = 0 */) : value_(value), lineno_(lineno)
{
}

Charcter::~Charcter()
{
}

String Charcter::toString()
{
    String ret = "char:";
    ret += value_;
    return ret;
}

String Charcter::toStringValue()
{
    String ret;
    ret += value_;
    return ret;
}

int Charcter::type() const
{
    return Object::CHARCTER;
}

Object* Charcter::eval(Environment* env)
{
    return this;
}

bool Charcter::eqv(Object* o)
{
    if (!o->isCharcter()) return false;
    Charcter* s = (Charcter*)o;
    return value() == s->value();
}

bool Charcter::eq(Object* o)
{
    return false;
}

bool Charcter::gt(Object* o)
{
    if (!o->isCharcter()) return false;
    Charcter* s = (Charcter*)o;
    return value() > s->value();
}

bool Charcter::lt(Object* o)
{
    if (!o->isCharcter()) return false;
    Charcter* s = (Charcter*)o;
    return value() < s->value();
}

bool Charcter::ge(Object* o)
{
    if (!o->isCharcter()) return false;
    Charcter* s = (Charcter*)o;
    return value() >= s->value();
}

bool Charcter::le(Object* o)
{
    if (!o->isCharcter()) return false;
    Charcter* s = (Charcter*)o;
    return value() <= s->value();
}

Number* Charcter::toNumber()
{
    return new Number((int)value(), lineno());

}

Charcter* Charcter::fromNumber(Number* n)
{
    String tmp = "#\\";
    tmp += (char)n->value();
    return new Charcter(tmp, n->lineno());
}
