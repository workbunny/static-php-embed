# 封装函数

## 返回值

```c
// 返回 true
RETURN_TRUE;
// 返回 false
RETURN_FALSE;
// 返回 null 相当于'return;'
RETURN_NULL();
// 返回 bool ,参数 b 传入 bool值
RETURN_BOOL(b);
// 返回 字符串 ,参数 s 传入 const char *
RETURN_STRING(s)
// 返回 int ,参数 i 传入 int 或者 long
RETURN_LONG(i);
// 返回 浮点,参数 d 传入 double 或者 float
RETURN_DOUBLE(d);
// 返回 数组 , zv 传入 zval 结构体
RETURN_COPY(zv);
```

`zval` 结构体

```c
zval arr;
// 初始化数组
array_init(&arr);
// 向数组中添加元素
add_next_index_long(&arr, 1);         // 添加整数
add_next_index_double(&arr, 3.14);    // 添加浮点数
add_next_index_string(&arr, "Hello"); // 添加字符串
```

## 参数类型定义

```c
IS_NULL 
IS_FALSE
IS_TRUE
IS_LONG
IS_DOUBLE
IS_STRING
IS_ARRAY
_IS_BOOL
```

示例

```c
ZEND_BEGIN_ARG_INFO_EX(demo02_arginfo, 0, 0, 1)
ZEND_ARG_TYPE_INFO(0, string_param, IS_STRING, 0) // 定义参数名string_param 是string类型IS_STRING
ZEND_END_ARG_INFO()
```