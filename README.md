Command Args
=====================
Super simple command arguments parser for C++.
Yeah, there are a few, but I made this for a 
particular purpose, ended up using it quite a 
bit so it's worth it at this point to put it
up on GitHub so I can download it from multiple
points.

There are a few bugs here and there, notably 
there are a few instances where there are
null arguments that I'd like to pass but
it's easy enough to get around by adding
an explicit boolean.  

Compiling is super simple, installs all the
library code and header files in the appropriate
/usr/local prefix. If I get time I'll update
to the GNU build system, but a simple Makefile
works for now.  I've used on both OS X and Linux.

##Simple Example
```cpp
CmdArgs  cmd( argv[ 0 ],
              std::cout,
              std::cerr );

bool help( false );

cmd.addOption( new Option< bool >( help,
                                    "-h",
                                    "Print this message",
                                    []( const char *x, bool &v )
                                    {
                                       v = true;
                                       return( true );
                                    },
                                    nullptr,
                                    false,
                                    true ) );
bool printHeader( false );
cmd.addOption( new Option< bool >( printHeader,
                                    "-header",
                                    "Print the header and exit" ) );


cmd.addOption( new Option< std::string >( filename,
                                          "-f",
                                          "Set the output file name" ) );

cmd.addOption( new Option< int64_t >( length, 
                                      "-l",
                                      "Length of run" ) );
cmd.addOption( new Option< int64_t >( buff_size,
                                      "-b",
                                      "Buffer size" ) );

cmd.addOption( new Option< int64_t >( repeat,
                                      "-r",
                                      "Number of times to repeat simulation" ) );

cmd.processArgs( argc, argv );

/** give object command line **/
cmd.processArgs( argc, argv );

/** handle the user needing help **/
if( help )
{
   cmd.printArgs();
   exit( EXIT_SUCCESS );
}
```
