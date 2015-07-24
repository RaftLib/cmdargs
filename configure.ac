#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cmdargs], [1.0], [jonathan.c.beard@gmail.com])
AC_CONFIG_SRCDIR([lib/command_arguments.cpp])
AC_CONFIG_MACRO_DIR([m4])
#AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_ARG_ENABLE([static],[--enable-static      turn off features we dont want],
[case "${enableval}" in
   yes) static=true  ;;
   no)  static=false ;;
   *) AC_MSG_ERROR([bad value ${enableval} for --enable-static]) ;;
 esac],[static=false])

AM_CONDITIONAL([STATIC], [test x$static = xtrue])

# Checks for programs.
LT_INIT
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.
# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T

# Checks for library functions.
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile
                 lib/Makefile])

AC_OUTPUT
