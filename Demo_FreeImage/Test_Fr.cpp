#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "FreeImage.h"
 
// test functions
int main( )
{
   
#if defined(FREEIMAGE_LIB) || !defined(WIN32)
            FreeImage_Initialise();
#endif
   FIBITMAP *c_bitmap = NULL ;
        FIBITMAP *bitmap = FreeImage_Load( FIF_PNG , "test.png" , PNG_DEFAULT );
        if( bitmap )
        {
            c_bitmap = FreeImage_ColorQuantize( bitmap ,FIQ_NNQUANT);
            if( c_bitmap )
            {
                if( FreeImage_Save( FIF_BMP , c_bitmap , "test.jpg" , 0 ) )
                {
                    printf("Save success!/n");
                }
                else
                    printf("Save failed!/n");
           }
          else
              printf("Convet failed!/n");
           FreeImage_Unload( bitmap);
        }
        else
            printf("Load failed!/n");
#if defined(FREEIMAGE_LIB) || !defined(WIN32)
           FreeImage_DeInitialise();
#endif
    return 1 ;
}
