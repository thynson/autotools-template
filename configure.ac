#
# Copyright (C) 2013 LAN Xingcan
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

# Minial autoconf version require, you may increase it if needed
AC_PREREQ([2.67])

# Change belows to your project name and version
AC_INIT([auto-template], [0.0.1])

# Path for stock files, don't change unless you knows what you are doing
AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_AUX_DIR([build-aux])

# Path for custom macro (e.g. m4/boostrap.m4)
AC_CONFIG_MACRO_DIRS([m4])

# Path for generated header, you may change it if needed
AC_CONFIG_HEADER([config.h])

# Initialize automake with 1.11 as minimal required version, and tell automake
# to distribute this project with a tar.xz format tarball
AM_INIT_AUTOMAKE([1.11 dist-xz])

# Initial compiler, use AC_PROG_CC([clang gcc etc]) to provides candicates
AC_PROG_CC([gcc])

# if you don't need C++ support, remove the following
# lines out
AC_PROG_CXX([g++])
AC_LANG([C++])

# mandatory require c++11, remove it out if c++11 is not needed or C++ is
# totally not needed; this macro need autoconf-archieve installed on you
# machine
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

#
# Note for here: If you want to add some magic flags to CFLAGS, CXXFLAGS, etc
# write them here. e.g.:
#
# CFLAGS="-flto $(CFLAGS) "
# CXXFLAGS="$(CXXFLAGS) -fno-rtti"
# ...
#
# you should respect the origin value of those flags by expanding them,
# otherwise flags provided by end users will takes no effect and make them
# confused. Further more, If you want to leave some flags overridable by end
# user(who compile the distributed source), for e.g., optimization flag,
# write it before the place where original value is expanded.
#

# libtoolization. you may want if this is a library project
AM_PROG_LIBTOOL
LT_INIT

# example for custom m4 macro(defined at m4/boost.m4)
# for more detail about it, see https://github.com/tsuna/boost.m4
BOOST_REQUIRE([1.48])
BOOST_ASIO
BOOST_SYSTEM
BOOST_CHRONO


# Less verbos when make
AM_SILENT_RULES([yes])

# Output files
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([src/Makefile])
AC_OUTPUT



