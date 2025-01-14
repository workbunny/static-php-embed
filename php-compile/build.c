#include <sapi/embed/php_embed.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datafile.c"

char *remove_all_substrings(const char *str, const char *target)
{
    if (str == NULL || target == NULL || strlen(target) == 0)
        return strdup(str); // 如果target为空，则返回原字符串的副本

    size_t str_len = strlen(str);
    size_t target_len = strlen(target);
    char *result = malloc(str_len + 1); // 分配最大可能的结果大小
    char *p_result = result;            // 用于遍历结果字符串的指针
    const char *p_str = str;            // 用于遍历源字符串的指针

    if (result == NULL)
    {
        // 内存分配失败
        return NULL;
    }

    while (*p_str != '\0')
    {
        // 检查是否匹配目标子串
        if (strncmp(p_str, target, target_len) == 0)
        {
            p_str += target_len; // 跳过目标子串
        }
        else
        {
            *p_result++ = *p_str++; // 复制非匹配字符到结果
        }
    }

    *p_result = '\0'; // 结束新字符串

    // 如果整个字符串都被移除了，释放内存并返回空字符串
    if (result[0] == '\0')
    {
        free(result);
        return strdup("");
    }

    return result;
}

int main(int argc, char **argv)
{
    // php嵌入开始
    PHP_EMBED_START_BLOCK(argc, argv)

    // 先移除"<?php"
    char *intermediate_result = remove_all_substrings(index_php, "<?php");
    // 再移除"?>"
    char *final_result = remove_all_substrings(intermediate_result, "?>");
    if (final_result != NULL)
    {
        if (zend_eval_stringl(final_result, strlen(final_result), NULL, "index") == FAILURE)
        {
            php_printf("Failed to execute PHP script.\n");
        }
    }
    else
    {
        php_printf("You can only run PHP scripts.\n");
    }
    
    // 清理分配的内存
    free(intermediate_result);
    free(final_result);
    // php嵌入结束
    PHP_EMBED_END_BLOCK()
    return 0;
}