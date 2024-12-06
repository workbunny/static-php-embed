x86_64-linux-musl-cc \
$(./buildroot/bin/php-config --includes) \
-L$(./buildroot/bin/php-config --prefix)/lib \
cphp.c -o cphp.bin \
-lphp \
$(./buildroot/bin/php-config --libs) \
-lm -lpthread -lresolv -ldl -lc \
-Wl,-rpath=$(./buildroot/bin/php-config --prefix)/lib \
-lpq -lpgport -lpgcommon -lgomp -lstdc++ -static