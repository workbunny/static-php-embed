#include <sapi/embed/php_embed.h>

static zend_object_handlers class_object_handlers;

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

// 定义类的对象处理函数
static zend_object *create(zend_class_entry *ce)
{
    my_php_class_t *intern = zend_object_alloc(sizeof(my_php_class_t), ce);
    zend_object_std_init(&intern->std, ce);

    intern->std.handlers = &class_object_handlers;

    return &intern->std;
}

// 定义类的对象处理函数
static void free_obj_fun(zend_object *object)
{
    my_php_class_t *obj = (my_php_class_t *)((char *)object - XtOffsetOf(my_php_class_t, std));
    zend_object_std_dtor(&obj->std);
    efree(obj);
}
// 定义类的函数信息
static const zend_function_entry my_php_class[] = {
    ZEND_ME(MyPhpClass, __construct, arginfo__construct, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        ZEND_ME(MyPhpClass, myMethod, arginfo_myMethod, ZEND_ACC_PUBLIC)
            ZEND_FE_END};

// 设置对象处理器
static void setup_handlers(zend_object_handlers *handlers)
{
    memcpy(handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    handlers->offset = offsetof(my_php_class_t, std);
    handlers->free_obj = free_obj_fun;
}

// 注册类
void register_class()
{
    // 注册类
    zend_class_entry ce;
    zend_class_entry *class_entry;
    INIT_CLASS_ENTRY(ce, "MyPhpClass", my_php_class);

    class_entry = zend_register_internal_class(&ce);
    php_printf("??");
    class_entry->create_object = create;
    if (!class_entry)
    {
        fprintf(stderr, "Failed to register class MyPhpClass\n");
        exit(EXIT_FAILURE);
    }

    // 注册类的对象处理函数
    setup_handlers(&class_object_handlers);
    // 输出调试信息
    php_printf("Registered class MyPhpClass successfully.\n");
}