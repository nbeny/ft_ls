#include <stdio.h>
#include <time.h>
 
int main (void)
{
    time_t epoch = 0, t = time(NULL);
    printf("Epoque (heure de %s) : %s", *tzname, ctime(&epoch));
    printf(" soit heure GMT : %s\n", asctime(gmtime(&epoch)) );
    printf("On est le (heure de %s) : %s", *tzname, ctime(&t));
    printf(" soit heure GMT : %s", asctime(gmtime(&t)) );
    return 0;
}
