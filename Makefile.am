AUTOMAKE_OPTIONS=foreign 1.7
ACLOCAL_AMFLAGS=-I build-aux/m4

# foobar
bin_PROGRAMS=foobar

# libfoobar
lib_LTLIBRARIES=libfoobar.la

foobar_SOURCES=foobar.cpp
foobar_LDADD=./libfoobar.la

libfoobar_la_SOURCES=libfoobar.cpp
libfoobar_la_HEADERS=foo/libfoobar.hpp
libfoobar_ladir=$(includedir)/foo


