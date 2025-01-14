/*
   +----------------------------------------------------------------------+
   | Copyright (c) The PHP Group                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | https://www.php.net/license/3_01.txt                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Stig Sæther Bakken <ssb@php.net>                             |
   +----------------------------------------------------------------------+
*/

#define CONFIGURE_COMMAND " './configure'  '--prefix=' '--with-valgrind=no' '--enable-shared=no' '--enable-static=yes' '--disable-all' '--disable-cgi' '--disable-phpdbg' '--disable-cli' '--disable-fpm' '--enable-embed=static' '--disable-micro' '--with-config-file-path=/usr/local/etc/php' '--with-config-file-scan-dir=/usr/local/etc/php/conf.d' '--enable-ctype' '--enable-fileinfo' '--enable-mbstring' '--disable-mbregex' '--enable-tokenizer' '--with-zlib' '--with-zlib-dir=/www/buildroot' '--enable-phar' 'CFLAGS=' 'PKG_CONFIG=/www/buildroot/bin/pkg-config' 'PKG_CONFIG_PATH=/www/buildroot/lib/pkgconfig'"
#define PHP_ODBC_CFLAGS	""
#define PHP_ODBC_LFLAGS		""
#define PHP_ODBC_LIBS		""
#define PHP_ODBC_TYPE		""
#define PHP_OCI8_DIR			""
#define PHP_OCI8_ORACLE_VERSION		""
#define PHP_PROG_SENDMAIL	"/usr/sbin/sendmail"
#define PEAR_INSTALLDIR         ""
#define PHP_INCLUDE_PATH	".:"
#define PHP_EXTENSION_DIR       "/lib/php/extensions/no-debug-non-zts-20230831"
#define PHP_PREFIX              ""
#define PHP_BINDIR              "/bin"
#define PHP_SBINDIR             "/sbin"
#define PHP_MANDIR              "/php/man"
#define PHP_LIBDIR              "/lib/php"
#define PHP_DATADIR             "/share/php"
#define PHP_SYSCONFDIR          "/etc"
#define PHP_LOCALSTATEDIR       "/var"
#define PHP_CONFIG_FILE_PATH    "/usr/local/etc/php"
#define PHP_CONFIG_FILE_SCAN_DIR    "/usr/local/etc/php/conf.d"
#define PHP_SHLIB_SUFFIX        "so"
#define PHP_SHLIB_EXT_PREFIX    ""
