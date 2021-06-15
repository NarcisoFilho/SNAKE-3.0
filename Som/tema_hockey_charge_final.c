
#include "NotasMusicais.h"

#define TEMP 15

int main(){
	Beep( C5 , .50 * TEMP * t );
	Beep( E5 , .50 * TEMP * t );
	Beep( G5 , .50 * TEMP * t );
	Beep( G5 , .75 * TEMP * t );	
	Beep( E5 , .50 * TEMP * t );	
	Beep( G5 , 6 * TEMP * t );	
	Beep( G6 , .5 * TEMP * t );	

	return 0;
}