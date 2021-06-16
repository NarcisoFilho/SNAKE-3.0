
#include "NotasMusicais.h"

int main(){
	Beep( G5 , 12 * t );
	Sleep( 10 * t );

	Beep( G5 , 8 * t );
	Beep( G5 , 8 * t );
	Beep( A5 , 12 * t );
	Beep( G5 , 12 * t );
	Sleep( 40 * t );

	Beep( B5 , 8 * t );
	Sleep( 3 * t );
	Beep( C6 , 18 * t );

	return 0;
}