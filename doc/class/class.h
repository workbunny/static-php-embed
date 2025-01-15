#include <sapi/embed/php_embed.h>
#include <Zend/zend_alloc.h>
#include <Zend/zend_objects.h>

static zend_object_handlers class_object_handlers;

typedef struct my_php_class_t
{
    zend_object std;
} my_php_class_t;

// 定义类的构造函数 类名：MyPhpClass
PHP_METHOD(MyPhpClass, __construct)
{
    RETURN_NULL();
}

// 定义类的构造函数的参数信息
ZEND_BEGIN_ARG_INFO_EX(arginfo__construct, 0, 0, 0)
ZEND_END_ARG_INFO()

// 定义类的函数
PHP_METHOD(MyPhpClass, myMethod)
{
    long num; // 参数 num
    // 解析参数
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &num) == FAILURE)
    {
        RETURN_THROWS();
    }
    RETURN_LONG(num * 2);
}

// 定义方法的参数信息
ZEND_BEGIN_ARG_INFO_EX(arginfo_myMethod, 0, 0, 1)
ZEND_ARG_TYPE_INFO(0, num, IS_LONG, 0)
ZEND_END_ARG_INFO()

zend_object *create(zend_class_entry *ce)
{
    my_php_class_t *intern = ecalloc(1, sizeof(my_php_class_t) + zend_object_properties_size(ce));
    zend_object_std_init(&intern->std, ce);
    object_properties_init(&intern->std, ce);

    intern->std.handlers = &class_object_handlers;

    return &intern->std;
}

void free_obj_fun(zend_object *object)
{
    my_php_class_t *obj = (my_php_class_t *)((char *)object - XtOffsetOf(my_php_class_t, std));
    zend_object_std_dtor(&obj->std);
    efree(obj);
}
// 定义类的函数信息
zend_function_entry my_php_class[] = {
    PHP_ME(MyPhpClass, __construct, arginfo__construct, ZEND_ACC_PUBLIC)
        PHP_ME(MyPhpClass, myMethod, arginfo_myMethod, ZEND_ACC_PUBLIC)
            PHP_FE_END};

// 注册类
void register_class()
{
    // 注册类
    zend_class_entry ce;
    zend_class_entry *class_entry;
    INIT_CLASS_ENTRY(ce, "MyPhpClass", my_php_class);
    class_entry = zend_register_internal_class(&ce);
    if (!class_entry)
    {
        fprintf(stderr, "Failed to register class MyPhpClass\n");
        exit(EXIT_FAILURE);
    }
    class_entry->create_object = create;
    // 注册类的对象处理函数
    memcpy(&class_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    class_object_handlers.offset = XtOffsetOf(my_php_class_t, std);
    class_object_handlers.free_obj = free_obj_fun;
}