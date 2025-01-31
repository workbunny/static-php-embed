#!/bin/bash

# 1.运行目录

script_directory="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# 2.是否安装了musl-gcc

file="/usr/local/musl/lib/musl-gcc.specs"
if [ ! -f "$file" ]; then
    echo "首次编译准备动作...";
    cd "$script_directory"/musl
    make install;
    cd "$script_directory"
fi;

# 3.将PHP文件转化为C文件

# 获取文件名（不带扩展名）和扩展名

# 移除最后一个点及其后面的所有内容，即移除扩展名
filename="${1%.*}"

# 获取最后一个点之后的内容，即获取扩展名
extension="${1##*.}"

# 检查是否确实有扩展名存在
if [ "$filename" != "$1" ] && [ -n "$extension" ]; then
    new_filename="${filename}_${extension}"
else
# 如果没有扩展名，则保持原样
    new_filename="$1"  
fi;

xxd_name="index_php"
xxd -i "$1" | sed "s/${new_filename}/$xxd_name/g; s/${new_filename}_len/${xxd_name}_len/g" > ${script_directory}/datafile.c;

# 4.开始编译

echo "开始编译...";
"$script_directory"/musl/obj/musl-gcc \
-static \
"$script_directory"/build.c -o "$2" \
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
echo "压缩文件...";
"$script_directory"/upx/upx "$2";
echo "编译成功~";
echo "运行指令:./$2";
