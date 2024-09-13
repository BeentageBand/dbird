ACLOCAL_AMFLAGS = -I m4 --install

AM_CPPFLAGS = \
-I ../applications/connection-manager-app \
-I ../applications/push-data-app \
-I ../applications/read-data-app \
-I ../bird-types \
-I ../ccjuice \
-I ../injection \
-I ../protocols/http \
-I ../protocols/modem \
-I ../protocols/sip \
-I ../services/connection-service \
-I ../services/data-access-service \
-I ../services/data-reader-service \
-I ../services/server-service \
-I ../system/ipc \
-I ../system/persistency \
-I ../system/worker \
-I ../utilities

# Unittest

check_PROGRAMS = unittest
unittest_SOURCES = \
bird-types-gmock.h  \
connection-http.cc  \
connection-manager-app.cc  \
connection-sip.cc  \
data-access-persistency.cc  \
protocols-gmock.h  \
push-data-app.cc  \
read-data-app.cc  \
services-gmock.h  \
system-gmock.h

unittest_CPP_FLAGS = $(GMOCK_CFLAGS) $(DBIRD_CFLAGS)
unittest_LDADD = $(GMOCK_LIBS) $(DBIRG_LIBS)
unittest_LDFLAGS = -no-install
