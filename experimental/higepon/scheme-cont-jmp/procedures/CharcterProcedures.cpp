#include "procedures/Procedure.h"
#include "libcont/cont.h"

using namespace std;
using namespace util;
using namespace monash;

PROCEDURE(CharcterP, "char?")
{
    ARGC_SHOULD_BE(1);
    RETURN_BOOLEAN(ARGV(0)->isCharcter());
}

PROCEDURE(CharcterEqualP, "char=?")
{
    ARGC_SHOULD_BE(2);
    CAST(ARGV(0), Charcter, c);
    RETURN_BOOLEAN(c->eqv(ARGV(1)));
}

PROCEDURE(CharcterGtP, "char>?")
{
    ARGC_SHOULD_BE(2);
    CAST(ARGV(0), Charcter, c);
    RETURN_BOOLEAN(c->gt(ARGV(1)));
}

PROCEDURE(CharcterLtP, "char<?")
{
    ARGC_SHOULD_BE(2);
    CAST(ARGV(0), Charcter, c);
    RETURN_BOOLEAN(c->lt(ARGV(1)));
}

PROCEDURE(CharcterGeP, "char>=?")
{
    ARGC_SHOULD_BE(2);
    CAST(ARGV(0), Charcter, c);
    RETURN_BOOLEAN(c->ge(ARGV(1)));
}

PROCEDURE(CharcterLeP, "char<=?")
{
    ARGC_SHOULD_BE(2);
    CAST(ARGV(0), Charcter, c);
    RETURN_BOOLEAN(c->le(ARGV(1)));
}

PROCEDURE(CharcterToInteger, "char->integer")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), Charcter, c);
    return c->toNumber();
}

PROCEDURE(IntegerToCharcter, "integer->char")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), Number, n);
    return Charcter::fromNumber(n);
}
