#include <cstdio>
#include <string>

#include "mask_enum.hpp"


void printUsage( const std::string &a );
void printArg( const int argc , char *argv[] );


int main( const int argc , char *argv[] )
{
	// input handling
	if( argc != 3 )
	{
		printUsage( argv[0] );
		exit( EXIT_FAILURE );
	}

	// do calculation
	const uint32_t val = strtoul( argv[1] , NULL , 0 );
	const uint32_t mask = strtoul( argv[2] , NULL , 0 );
	MaskEnum a( val , mask );

	// output results
	const auto results = a.getOutput();
	for( const auto &i : *results )
	{
		printf( "%u\n" , i );
	}

//	system( "pause" );
	return 0;
}


void printUsage( const std::string &a )
{
	fprintf( stderr , "\n" );
	fprintf( stderr , "Mask Enumerator\n\n" );
	fprintf( stderr , "Usage: %s value mask\n" , a.c_str() );
	fprintf( stderr , "Example1: %s  0 65535\n" , a.c_str() );
	fprintf( stderr , "Example1: %s  0 0xfffef\n" , a.c_str() );
//	fprintf( stderr , "Example2: %s 50 0b11011\n" , a.c_str() );
	return;
}


void printArg( const int argc , char *argv[] )
{
	printf( "argc: %d\n" , argc );

	for( auto i = 1 ; i < argc ; ++i )
	{
		printf( "argv[%d]: %s\n" , i , argv[i] );
	}
	return;
}
