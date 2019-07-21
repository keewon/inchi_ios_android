# InChI build for Android/iOS

InChI : https://www.inchi-trust.org/downloads/ 


Tested/Built on MacOSX


## Diff between InChI 1.05 and InChI here
### ichicano.c
Before
```
#include <sys/timeb.h>
```

After
```
#ifndef COMPILE_ANSI_ONLY
#include <sys/timeb.h>
#endif
```

### util.c
Before
```
#if defined(COMPILE_ANSI_ONLY) && defined(__APPLE__)
```

After
```
#if defined(COMPILE_ANSI_ONLY)
```
