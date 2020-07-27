#include <stdio.h>
#include <ucontext.h>
#include <execinfo.h>


static ucontext_t ctx [2];

static char st1 [8192];
static char st2 [8192];

static bool firstStackInit = false;

void dummy (void) {
  int j = 0; 
  printf ("&j=%p, &st1[0]=%p\n", &j, &st1[0]);
}

int main (void) {

  int i = 1;

  getcontext (&ctx [0]);

  printf ("&i=%p, sp=%p\n", &i, ctx[0].uc_stack.ss_sp);

  if (!firstStackInit) { 
    ctx[0].uc_stack.ss_sp = &st1[0];
    ctx[0].uc_stack.ss_size = sizeof (st1);
    firstStackInit = true;
    setcontext (&ctx[0]);
  }

  dummy ();


  return 0;
}


