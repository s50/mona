#include "procedures/Procedure.h"

using namespace util;
using namespace std;
using namespace monash;

PROCEDURE(StringCopy, "string-copy")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), SString, s);
    return s->clone();
}

PROCEDURE(StringP, "string?")
{
    ARGC_SHOULD_BE(1);
    RETURN_BOOLEAN(ARGV(0)->isSString());
}

PROCEDURE(MakeString, "make-string")
{
    ARGC_SHOULD_BE_BETWEEN(1, 2);
    if (ARGC == 1)
    {
        CAST(ARGV(0), Number, n)
        return new SString(n->value(), n->lineno());
    }
    else
    {
        CAST(ARGV(0), Number, n);
        CAST(ARGV(1), Charcter, c);
        return new SString(n->value(), c->value(), n->lineno());
    }
}

PROCEDURE(StringLength, "string-length")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), SString, s);
    return new Number(s->value().size(), s->lineno());
}

PROCEDURE(StringRef, "string-ref")
{
    ARGC_SHOULD_BE(2);
    CAST(ARGV(0), SString, s);
    CAST(ARGV(1), Number, n);
    Object* ret = s->get(n->value());
    if (ret == NULL)
    {
        RAISE_ERROR(ARGV(0)->lineno(), "%s got wrong index", toString().data());
        return NULL;
    }
    return ret;
}

PROCEDURE(StringSet, "string-set!")
{
    ARGC_SHOULD_BE(3);
    CAST(ARGV(0), SString, s);
    CAST(ARGV(1), Number, n);
    CAST(ARGV(2), Charcter, c);
    bool isOK = s->set(n->value(), c);
    if (!isOK)
    {
        RAISE_ERROR(ARGV(0)->lineno(), "%s got wrong arguments", toString().data());
    }
    return SCM_UNDEF;
}


PROCEDURE(StringEqualP, "string=?")
{
    ARGC_SHOULD_BE(2);
    CAST(ARGV(0), SString, s);
    RETURN_BOOLEAN(s->equal(ARGV(1)));
}

PROCEDURE(StringToNumber, "string->number")
{
    ARGC_SHOULD_BE(1);
    CAST_RETURN_FALSE(ARGV(0), SString, str);
    String text = str->value();
    for (uint32_t i = 0; i < text.size(); i++)
    {
        if (!isdigit(text[i]))
        {
            return SCM_FALSE;
        }
    }
    return new Number(atoi(text.data()));
}

PROCEDURE(StringToSymbol, "string->symbol")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), SString, s);
    SExp* exp = new SExp(SExp::SYMBOL);
    exp->text = s->toStringValue();
    return new Quote(exp);
}

// see test/scheme.scm
// PROCEDURE(StringAppend, "string-append")
// {
//     ARGC_SHOULD_BE_GT(0)
//     ::util::String text = "";

//     for (Objects::const_iterator p = arguments->begin(); p != arguments->end(); ++p)
//     {
//         if ((*p)->type() != Object::STRING) continue;
//         String* s = (String*)(*p);
//         text += s->value();
//     }
//     return new String(text);
// }
