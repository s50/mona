#include "procedures/Procedure.h"

using namespace util;
using namespace std;
using namespace monash;

Objects* pairToObjects(Pair* pair)
{
    Objects* objects = new Objects;
    Pair* p = pair;
    for (;;)
    {
        Object* car = p->getCar();
        Object* cdr = p->getCdr();
        if (car != NULL)
        {
            objects->add(car);
        }
        if (cdr == NULL) break;
        if (!cdr->isPair()) break;
        p = (Pair*)cdr;
    }
    return objects;
}

PROCEDURE(CallWithCurrentContinuation, "call-with-current-continuation")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), Procedure, procedure);

    Continuation* continuation = new Continuation;
    if (0 == cont_save(&(continuation->cont)))
    {
        Objects* arguments = new Objects;
        arguments->add(continuation);
        return Kernel::apply(procedure, arguments, env);
    }
    else
    {
        Object* result = continuation->callArugument->eval(env);
        return result;
    }

    RAISE_ERROR(lineno(), "unknown call/cc");
}

PROCEDURE(NotSupported, "not-supported")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), SString, s);
    RAISE_ERROR(0, "%s not supported\n", s->toStringValue().data());
    RETURN_BOOLEAN(false);
}

PROCEDURE(ProcedureP, "procedure?")
{
    ARGC_SHOULD_BE(1);
    RETURN_BOOLEAN(ARGV(0)->isProcedure());
}

PROCEDURE(BooleanP, "boolean?")
{
    ARGC_SHOULD_BE(1);
    RETURN_BOOLEAN(ARGV(0)->isBoolean());
}


PROCEDURE(Exit, "exit")
{
    exit(-1);
}


PROCEDURE(Apply, "apply")
{
   ARGC_SHOULD_BE(2);
   CAST(ARGV(1), Pair, p);
   return Kernel::apply(ARGV(0), pairToObjects(p), env);
}

PROCEDURE(Eval, "eval")
{
    ARGC_SHOULD_BE(2);
    CAST(ARGV(0), Quote, q);
    CAST(ARGV(1), Environment, e);

    Object* o;
    // see Translator::translateQuote
    SExp* n = q->sexp();
    e->macroFilter().filter(n);
    int ret = e->translator().translate(&n, &o);
    if (ret != Translator::SUCCESS)
    {
        RAISE_ERROR(n->lineno, "eval got error [%s]", toString().data(), q->toStringValue().data());
    }
    return o->eval(e);
}

PROCEDURE(NullEnvironment, "null-environment")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), Number, n);
    if (n->value() != 5)
    {
        RAISE_ERROR(lineno(), "%s got wrong version" , toString().data());
    }
    MacroFilter f;
    Translator translator;
    return new Environment(f, translator, lineno());
}

PROCEDURE(SchemeReportEnvironment, "scheme-report-environment")
{
    ARGC_SHOULD_BE(1);
    CAST(ARGV(0), Number, n);
    if (n->value() != 5)
    {
        RAISE_ERROR(lineno(), "%s got wrong version" , toString().data());
    }
    return env;
}
