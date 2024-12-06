# spc build

```sh
./spc doctor --auto-fix
```

```sh
./spc build --build-all "amqp,apcu,bcmath,calendar,ctype,curl,dba,dom,event,exif,fileinfo,filter,gd,gettext,iconv,igbinary,imagick,intl,libxml,mbregex,mbstring,memcache,mongodb,msgpack,mysqli,mysqlnd,opcache,openssl,pcntl,pdo,pdo_mysql,pdo_pgsql,pdo_sqlite,pdo_sqlsrv,pgsql,phar,posix,readline,redis,session,shmop,simdjson,simplexml,soap,sockets,sodium,sqlite3,sqlsrv,sysvmsg,sysvsem,sysvshm,tokenizer,xml,xmlreader,xmlwriter,xsl,zip,zlib" --with-upx-pack
```

# 坑

修改 buildroot/bin/php-config 文件

```sh
#perfix=""
perfix="/path/to/buildroot"
```

# 示例一 

```c
#include <sapi/embed/php_embed.h>
#define HEREDOC(...) #__VA_ARGS__

int main(int argc,char **argv){
    // php嵌入开始
    PHP_EMBED_START_BLOCK(argc,argv)

    const char *str = HEREDOC(
        echo "世界上最好的语言是PHP!\n";
    );

    // eval执行php代码
    zend_eval_string(str, NULL, "MY PHP APP");

    //php嵌入结束
    PHP_EMBED_END_BLOCK()
    return 0;
}
```

# build.sh 编译 

编译器[musl-cc](https://musl.libc.org/)

```sh
x86_64-linux-musl-cc \
$(./buildroot/bin/php-config --includes) \
-L/usr/lib \
-L$(./buildroot/bin/php-config --prefix)/lib \
cphp.c -o cphp.bin \
-lphp \
$(./buildroot/bin/php-config --libs) \
-lm -lpthread -lresolv -ldl -lc \
-Wl,-rpath=$(./buildroot/bin/php-config --prefix)/lib \
-lpq -lpgport -lpgcommon -lgomp -lstdc++ -static
# -lpq -lpgport -lpgcommon
# -fsanitize=thread -pie -fPIC \
```

# [更多](https://github.com/php/php-src/tree/master/sapi/embed)