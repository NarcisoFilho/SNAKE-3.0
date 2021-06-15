
#include "NotasMusicais.h"

int main(){
	for( int bis = 10 ; bis ; bis-- ){
		Beep( A5S , 10 * t );	
		for( int bis = 7; bis ; bis-- )
			Beep( A5 , 10 * t );
	}
	
	for( int bis = 10 ; bis ; bis-- ){
		Beep( G5 , 10 * t );	
		for( int bis = 2 ; bis ; bis-- ){
			Beep( E6 , 10 * t );
			Beep( E6 , 10 * t );
			Beep( G5 , 10 * t );		
			Beep( A5 , 10 * t );		
			Beep( B5 , 10 * t );		
			Beep( C6 , 10 * t );		
		}
	}
	
	return 0;
}