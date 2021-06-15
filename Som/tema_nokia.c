
#include "NotasMusicais.h"

#define TEMP 15

int main(){
	for( int bis = 2 ; bis ; bis-- ){
		Beep( E6 , TEMP / 2.0 * t ); 	
		Beep( D6 , TEMP * t );
		Beep( F5S , TEMP * t );
		Beep( G5S , TEMP * t );
		Sleep( TEMP * t * 2.3 / 3.0 );	

		Beep( C6S , TEMP / 2.0 * t ); 	
		Beep( B5 , TEMP * t );
		Beep( D5 , TEMP * t );
		Beep( E5 , TEMP * t );
		Sleep( TEMP * t * 2.3 / 3.0 );	

		Beep( B5 , TEMP  * t ); 	
		Beep( A5 , 2 * TEMP * t );
		Beep( C5S , 2 * TEMP * t );
		Beep( E5 , 2 * TEMP * t );
		Beep( A5 , 3 * TEMP * t );
	}

	return 0;
}