# Release version
m4_define([package_version_major], [1])
m4_define([package_version_minor], [0])
m4_define([package_version_micro], [0])

# API Version
m4_define([api_version], [1])

# Initialize
AC_INIT([dbird], [package_version_major.package_version_minor.package_version_micro], [beentageband@gmail.com])


# Dependencies
PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

AC_SUBST([PACKAGE_VERSION_MAJOR], package_version_major)
AC_SUBST([PACKAGE_VERSION_MINOR], package_version_minor)
AC_SUBST([PACKAGE_VERSION_PATCH], package_version_micro)
AC_SUBST([API_VERSION], api_version)

DBIRD_PKG_REQ="jsoncpp >= 1.9.0"
PKG_CHECK_MODULES([DBIRD], [jsoncpp])
AC_SUBST(DBIRD_PKG_REQ)

# Autotools aux files
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# Automake config files

AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_FILES([Makefile tst/Makefile dbird.pc])
AC_CONFIG_SUBDIRS([tst])

# Safety check
AC_CONFIG_SRCDIR([launcher/master.cc])

# Compiler Flags
AC_PROG_CXX
AM_PROG_AR

# Libtool
LT_INIT
PKG_CHECK_MODULES([GMOCK], [gmock_main])

# Output
AC_OUTPUT
