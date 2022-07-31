//
//  main.c
//  mol2inchi
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../INCHI-1-SRC/INCHI_BASE/src/inchi_api.h"

extern int MakeINCHIFromMolfileText( const char *moltext,
                         char *szOptions,
                         inchi_Output *result );

int main(int argc, const char * argv[]) {
    // insert code here...
    inchi_Output result;
    FILE* fp = fopen("/tmp/methane.mol", "rb");
    char text[10000];
    memset(&result, 0, sizeof(result));
    memset(text, 0, 10000);
    fread(text, 1, 10000, fp);
    fclose(fp);
    int x = MakeINCHIFromMolfileText(text, "", &result);
    printf("%d\n", x);
    printf("inchi: %s\n", result.szInChI);
    printf("aux: %s\n", result.szAuxInfo);
    printf("log: %s\n", result.szLog);
    printf("msg: %s\n", result.szMessage);
    
    return 0;
}
