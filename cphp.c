#include <sapi/embed/php_embed.h>
#define HEREDOC(...) #__VA_ARGS__

int main(int argc,char **argv){
    // php嵌入开始
    PHP_EMBED_START_BLOCK(argc,argv)

    const char *str = HEREDOC(
        echo "世界上最好的语言是PHP!\n";
    );

    // eval执行php代码
    zend_eval_string(str, NULL, "MY PHP APP");

    //php嵌入结束
    PHP_EMBED_END_BLOCK()
    return 0;
}
 
// int main(int argc,char **argv){
//     // php嵌入开始
//     PHP_EMBED_START_BLOCK(argc,argv)

//     zend_file_handle file_handle;
//     zend_stream_init_filename(&file_handle,"index.php");
    
//     if(php_execute_script(&file_handle) == FAILURE){
//         php_printf("php run ok!");
//     }

//     //php嵌入结束
//     PHP_EMBED_END_BLOCK()
//     return 0;
// }