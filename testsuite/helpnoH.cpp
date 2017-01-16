#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmd>
#include <unistd.h>

int
main( int argc, char **argv )
{
    CmdArgs cmd( argv[ 0 ],
                 std::cout,
                 std::cerr );

    bool help( false );
    cmd.addOption( new Option< bool >( help,
                                       "-h",
                                       "This is help, print menu" ) );
    cmd.processArgs( argc, argv );

    if( help )
    {
       cmd.printArgs();
       system( "touch foo" );
    }

    /** exec self and see if it fails **/
    if( argc < 2 )
    {
        
        execl( argv[ 0 ], "-h", "true" );
    }
    else
    {

    }

    return( EXIT_SUCCESS );
}
