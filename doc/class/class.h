#include <sapi/embed/php_embed.h>

static zend_class_entry *class_entry;
static zend_object_handlers my_php_class_handlers;

typedef struct my_php_class_t
{
    zend_object std;
} my_php_class_t;

// 定义类的构造函数 类名：MyPhpClass
PHP_METHOD(MyPhpClass, __construct)
{
    // RETURN_NULL();
}

// 定义类的构造函数的参数信息
ZEND_BEGIN_ARG_INFO_EX(arginfo__construct, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()

// 定义类的函数
PHP_METHOD(MyPhpClass, myMethod)
{
    long num; // 参数 num

    ZEND_PARSE_PARAMETERS_START(1, 1)
    Z_PARAM_LONG(num)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_LONG(num * 2);
}

// 定义方法的参数信息
ZEND_BEGIN_ARG_INFO_EX(arginfo_myMethod, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
ZEND_ARG_TYPE_INFO(0, num, IS_LONG, 0)
ZEND_END_ARG_INFO()

// 定义类的函数信息
static const zend_function_entry my_php_class[] = {
    ZEND_ME(MyPhpClass, __construct, arginfo__construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        ZEND_ME(MyPhpClass, myMethod, arginfo_myMethod, ZEND_ACC_PUBLIC)
            ZEND_FE_END};


// 创建对象函数
static zend_object *my_php_class_create(zend_class_entry *ce)
{
    my_php_class_t *obj = ecalloc(1, sizeof(my_php_class_t));
    zend_object_std_init(&obj->std, ce);
    object_properties_init(&obj->std, ce);
    return &obj->std;
}

// 注册类
PHP_MINIT_FUNCTION(MyPhpClass){
    
    zend_class_entry ce;
    
    INIT_CLASS_ENTRY(ce, "MyPhpClass", my_php_class);

    class_entry = zend_register_internal_class(&ce);

    class_entry->create_object = my_php_class_create; // 关键对象处理

    return SUCCESS;
}

// 模块结构
zend_module_entry MyPhpClass_module_entry = {
    STANDARD_MODULE_HEADER,
    "MyPhpClass",
    NULL,
    PHP_MINIT(MyPhpClass),
    NULL,
    NULL,
    NULL,
    NULL,
    "1.0",
    STANDARD_MODULE_PROPERTIES
};

// 获取模块
ZEND_GET_MODULE(MyPhpClass)