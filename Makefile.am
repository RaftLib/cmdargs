AUTOMAKE_OPTIONS=foreign
ACLOCAL_AMFLAGS=-I m4
SUBDIRS=lib
include_HEADERS = $(top_srcdir)/include/cmd
include_DIRS=
nobase_include_HEADERS = $(top_srcdir)/include/cmd \
                         $(top_srcdir)/include/cmdargs/command_arguments.h \
                         $(top_srcdir)/include/cmdargs/command_option_multiple.tcc \
                         $(top_srcdir)/include/cmdargs/command_option_base.hpp \
                         $(top_srcdir)/include/cmdargs/command_option_single.tcc


AM_LDFLAGS =                          
if STATIC
AM_LDFLAGS += -static -static-libgcc -static-libstdc++
endif
