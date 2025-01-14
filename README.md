# STATIC-PHP-EMBED

## 要求`linux`

```sh
sudo apt update
sudo apt install gcc make xxd
```

## 库

ctype,fileinfo,mbstring,tokenizer,phar

## 示例

`demo.php`

```php
<?php

echo "你好世界,hello!\n";
```

编译

```sh
# 编译demo.php文件 为 php
./php-compile/compile.sh demo.php php
# 运行php
./php
```

结果

`你好世界,hello!`