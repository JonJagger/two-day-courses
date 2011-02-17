#ifndef CTA_INCLUDED
#define CTA_INCLUDED

/*
 * This compile time assertion relies on the fact that C does not
 * allow you to define an array of length zero. A constant-boolean-expression, 
 * when converted to an integer evaluates to either zero (false) or one (true)
 * respectively. Therefore, if we attempt to declare an array whose
 * length is a compile-time constant-boolean-expression we will either
 * be declaring an array of length one (if the expression is true), or
 * an array of length zero (if the expression is false). Thus we gain
 * a compile-time failure if the boolean-expression is false.
 */

#define COMPILE_TIME_ASSERTION(prefix,assertion)                    \
    char CONCAT2(prefix,_COMPILE_TIME_ASSERTS_,__LINE__) [ assertion ]

#define CONCAT2(a,b,c) CONCAT1(a,b,c)

#define CONCAT1(a,b,c) (a ## b ## c)

#endif
