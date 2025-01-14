#include <sapi/embed/php_embed.h>

// ----------------定义一个返回void 和无参数 函数

// 定义函数
PHP_FUNCTION(hello_world)
{
    php_printf("Hello, World from C function!\n");
}

// 定义函数的参数信息 参数名 hello_world_arginfo
ZEND_BEGIN_ARG_INFO_EX(hello_world_arginfo, 0, 0, 0)
// 如果有参数，则在这里添加 ZEND_ARG_INFO(0, "parameter_name");
// 由于此函数没有参数，我们保持这个宏调用为空
ZEND_END_ARG_INFO()

// ----------------定义一个返回void 和无参数 函数     end

// ---------------- 定义一个传int 返回 int 的函数
PHP_FUNCTION(demo01)
{
    long int_param;
    // 解析参数 第二个参数 "l" 为long参数 "ls"为是带有long、string参数
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &int_param) == FAILURE)
    {
        RETURN_NULL();
    }
    RETURN_LONG(int_param);
}

ZEND_BEGIN_ARG_INFO_EX(demo01_arginfo, 0, 0, 1)
ZEND_ARG_TYPE_INFO(0, int_param, IS_LONG, 0) // 定义参数名int_param 是int类型IS_LONG
ZEND_END_ARG_INFO()

// ---------------- 定义一个传int 返回 int 的函数   end

// ---------------- 定义一个传string 返回 string 的函数
PHP_FUNCTION(demo02)
{
    char *string_param; //字符串
    size_t string_param_len; //字符串的长度，要带上

    // 解析参数 第二个参数 "l" 为long参数 "ls"为是带有long、string参数以此类推
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &string_param, &string_param_len) == FAILURE)
    {
        RETURN_NULL();
    }
    // 返回字符串
    RETURN_STRING(string_param);
}

ZEND_BEGIN_ARG_INFO_EX(demo02_arginfo, 0, 0, 1)
ZEND_ARG_TYPE_INFO(0, string_param, IS_STRING, 0) // 定义参数名string_param 是string类型IS_STRING
ZEND_END_ARG_INFO()

// ---------------- 定义一个传string 返回 string 的函数   end

/**
 * @brief 注册自定义
 *
 */
void register_function()
{
    // 注册自定义方法 结构
    zend_function_entry functions[] = {
        PHP_FE(hello_world, hello_world_arginfo)
            PHP_FE(demo01, demo01_arginfo)
                PHP_FE(demo02, demo02_arginfo)
                    PHP_FE_END};
    // 注册方法
    zend_register_functions(NULL, functions, NULL, MODULE_PERSISTENT);
}