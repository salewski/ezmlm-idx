#include "env.h"
#include "str.h"

/*@null@*/char *env_get(const char *s)
{
  int i;
  unsigned int slen;
  char *envi;
 
  slen = str_len(s);
  for (i = 0;(envi = environ[i]) != 0;++i)
    if ((!str_diffn(s,envi,slen)) && (envi[slen] == '='))
      return envi + slen + 1;
  return 0;
}

extern const char *env_findeq(const char *s)
{
  for (;*s;++s)
    if (*s == '=')
      return s;
  return 0;
}
