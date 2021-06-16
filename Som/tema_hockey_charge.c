
#include "NotasMusicais.h"

#define TEMP 23

int main(){
	for( int bis = 2 ; bis ; bis-- ){
		Beep( A5S , 1 * TEMP * t );
		Beep( F5 , 1 * TEMP * t );
		Beep( G5 , 1 * TEMP * t );
		Beep( A5 , 1 * TEMP * t );
	}

	for( int bis = 2 ; bis ; bis-- ){
		Beep( B5 , .87 * TEMP * t );
		Beep( F5S , .87 * TEMP * t );
		Beep( G5S , .87 * TEMP * t );
		Beep( A5S , .87 * TEMP * t );
	}

	for( int bis = 2 ; bis ; bis-- ){
		Beep( C6 , .75 * TEMP * t );
		Beep( G5 , .75 * TEMP * t );
		Beep( A5 , .75 * TEMP * t );
		Beep( B5 , .75 * TEMP * t );
	}

	Beep( C6 , 3 * TEMP * t );

	Beep( C5 , .40 * TEMP * t );
	Beep( E5 , .40 * TEMP * t );
	Beep( G5 , .25 * TEMP * t );
	Beep( G5 , 1.1 * TEMP * t );
	Sleep( .25 * TEMP * t );

	Beep( E5 , .25 * TEMP * t );
	Beep( G5 , 3 * TEMP * t );

	return 0;
}
