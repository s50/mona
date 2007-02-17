#include "Vector.h"

using namespace monash;
using namespace std;

Vector::Vector(uint32_t size, uint32_t lineno /* = 0 */) : size_(size), lineno_(lineno)
{
    values_ = new Objects(size);
}

Vector::Vector(uint32_t size, Object* o, uint32_t lineno /* = 0 */) : size_(size), lineno_(lineno)
{
    values_ = new Objects();
    for (int i = 0; i < size; i++)
    {
        values_->add(o);
    }

}

Vector::Vector(Objects* values, uint32_t lineno /* = 0 */) : values_(values), size_(values->size()), lineno_(lineno)
{
}

Vector::~Vector()
{
}

Object* Vector::get(int index)
{
    if (index > size_  || index < 0) return NULL;
    return values_->get(index);
}

bool Vector::set(int index, Object* o)
{
    if (index > size_ - 1 || index < 0) return false;
    values_->removeAt(index);
    values_->insert(index, o);
    return true;
}

string Vector::toString()
{
    return "vector";
}

string Vector::toStringValue()
{
    string ret = "#(";
    for (int i = 0; i < values_->size(); i++)
    {
        ret += values_->get(i)->toStringValue();
        if (i != values_->size() - 2) ret += " ";
    }
    ret += ")";
    return ret;
}

int Vector::type() const
{
    return Object::VECTOR;
}

Object* Vector::eval(Environment* env)
{
    return this;
}

bool Vector::eqv(Object* o)
{
    if (!o->isVector()) return false;
    Vector* s = (Vector*)o;
    return this == s;
}

bool Vector::eq(Object* o)
{
    return false;
}
