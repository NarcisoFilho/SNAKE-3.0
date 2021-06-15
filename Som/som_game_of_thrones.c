
#include "NotasMusicais.h"

int main(){
	const int s = 8;
	const int n = 16;
	const int l = 24;
	const int sl = 50;
	const int hl = 100;

	Beep( A5 , l * t );
	Beep( D5 , l * t );

	Beep( F5 , s * t );
	Beep( G5 , s * t );
	Beep( A5 , l * t );
	Beep( D5 , l * t );		
	
	for( int bis = 3 ; bis ; bis-- ){

		Beep( F5 , s * t );
		Beep( G5 , s * t );
		Beep( A5 , l * t );
		Beep( D5 , l * t );		
	}

	for( int bis = 3 ; bis ; bis-- ){
		Beep( F5S , s * t );
		Beep( G5 , s * t );
		Beep( A5 , l * t );
		Beep( D5 , l * t );		
	}

	Beep( F5S , l * t );
	//Beep( G5 , l * t );	
	
/*
	for( int bis = 3 ; bis ; bis-- ){
		Beep( A5 , l * t );
		Beep( D5 , l * t );
		Beep( F5 , l * t );
		Beep( G5 , l * t );
		Beep( A5 , l * t );
		Beep( D5 , l * t );
	
		Beep( F5 , 20 * t );
		Beep( G5 , 20 * t );
		Beep( E5 , 20 * t );

		Beep( G5 , 20 * t );
		Beep( C5 , 20 * t );
		Beep( F5 , 20 * t );
		Beep( E5 , 20 * t );
		Beep( G5 , 20 * t );
		Beep( C5 , 20 * t );
		Beep( F5 , 20 * t );
		Beep( E5 , 20 * t );
		Beep( D5 , 20 * t );
	}
*/

	Beep( A6 , hl * t );
	Beep( D6 , sl * t );
	
	Beep( F6 , n * t );
	Beep( G6 , n * t );
	Beep( A6 , hl * t );
	
	Beep( D6 , sl * t );	
	
	Beep( F6 , s * t );
	Beep( G6 , s * t );
	Beep( E6 , n * t );
	
	
	Beep( F6 , 20 * t );
	Beep( G6 , 20 * t );
	Beep( E6 , 20 * t );	
exit( 2 );
	Beep( G6 , 20 * t );
	Beep( C6 , 20 * t );
	Beep( E6 , 20 * t );
	Beep( F6 , 20 * t );
	Beep( E6 , 20 * t );
	Beep( C6 , 20 * t );	
	Beep( D6 , 20 * t );	

	Beep( D6 , 20 * t );
	Beep( C6 , 20 * t );
	Beep( D5 , 20 * t );
	Beep( A5 , 20 * t );
	Beep( A5S , 20 * t );
	Beep( F5 , 20 * t );	
	Beep( G5 , 20 * t );	
	Beep( A5 , 20 * t );

	Beep( D6 , 20 * t );
	Beep( C6 , 20 * t );
	Beep( D5 , 20 * t );
	Beep( A5 , 20 * t );
	Beep( A5S , 20 * t );
	Beep( F5 , 20 * t );	
	Beep( E5 , 20 * t );	
	Beep( D5 , 20 * t );	


	return 0;
}