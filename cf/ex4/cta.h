/* cta.h */

#ifndef CTA_INCLUDED
#define CTA_INCLUDED

#define COMPILE_TIME_ASSERTION(cta)  extern char CTA_NAME[ (cta) ? +1 : -1 ]

#define CTA_NAME  CTA_CONCAT(compile_time_assertion_on_line_,__LINE__)
#define CTA_CONCAT(lhs,rhs)  CTA_CONCAT_AGAIN(lhs, rhs)
#define CTA_CONCAT_AGAIN(lhs,rhs)   lhs ## rhs

#endif
