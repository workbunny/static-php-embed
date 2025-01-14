script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
echo "开始编译...";
"$script_directory"/musl/obj/musl-gcc \
-static \
"$1" -o "$2" \
-I"$script_directory"/buildroot/include/php \
-I"$script_directory"/buildroot/include/php/main \
-I"$script_directory"/buildroot/include/php/TSRM \
-I"$script_directory"/buildroot/include/php/Zend \
-I"$script_directory"/buildroot/include/php/ext \
-I"$script_directory"/buildroot/include/php/ext/date/lib \
-L"$script_directory"/buildroot/lib \
-lphp -lrt -lm -ldl -lpthread \
-lm -lz \
-lm -lpthread -lresolv -ldl -lc;
echo "编译完成!";