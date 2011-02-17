#ifndef ALIGNED_INCLUDED
#define ALIGNED_INCLUDED

union aligned
{
    char c,*cp; int i,*ip; long l,*lp; long long ll,*llp;
    float f,*fp; double d,*dp; long double ld,*ldp;
    void *vp;
    void (*fv)(void); void (*fo)(); void (*fe)(int,...);
    struct s * sp;
    union u * up;
} ;

#endif
