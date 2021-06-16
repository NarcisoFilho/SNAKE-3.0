
#include "NotasMusicais.h"

#define TEMP 23

int main(){
        Beep( C5 , .40 * TEMP * t );
	Beep( E5 , .40 * TEMP * t );
	Beep( G5 , .25 * TEMP * t );
	Beep( G5 , 1.1 * TEMP * t );
	Sleep( .25 * TEMP * t );

	Beep( E5 , .25 * TEMP * t );
	Beep( G5 , 3 * TEMP * t );

	Sleep( 1 * TEMP * t );
	Beep( G5 , .5 * TEMP * t );
	Beep( C6 , .5 * TEMP * t );

	return 0;
}
