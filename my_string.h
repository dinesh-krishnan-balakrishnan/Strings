//include stdlib to have size_t, which is just an int
#include <stdlib.h>


extern size_t my_strlen ( const char * str );
extern void * my_memset ( void * ptr, int value, size_t num );
extern char * my_strcat ( char * destination, const char * source );
extern char * my_strcpy ( char * destination, const char * source );
extern size_t my_strcspn ( const char * str1, const char * str2 );

char * my_strncpy ( char * destination, const char * source, size_t num );
char * my_strchr (       char * str, int character );
void * my_memmove ( void * destination, const void * source, size_t num );
char * my_strncat ( char * destination, const char * source, size_t num );
int  my_strncmp ( const char * str1, const char * str2, size_t num );
int  my_strcmp ( const char * str1, const char * str2 );
char * my_strrchr (       char * str, int character );
char * my_strstr (       char * str1, const char * str2 );




