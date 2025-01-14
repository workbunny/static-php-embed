#include <sapi/embed/php_embed.h>
// 引入
#include "function.h"

int main(int argc, char **argv)
{
    // php嵌入开始
    PHP_EMBED_START_BLOCK(argc, argv)

    // 注册
    register_function();

    // PHP文件
    zend_file_handle file_handle;
    // 执行文件
    zend_stream_init_filename(&file_handle, "index.php");
    // 判断
    if (php_execute_script(&file_handle) == FAILURE)
    {
        php_printf("Failed to execute PHP script.\n");
    }

    // php嵌入结束
    PHP_EMBED_END_BLOCK()
    return 0;
}