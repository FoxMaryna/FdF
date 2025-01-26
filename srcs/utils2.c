#include "../fdf.h"

static int count_words(char *str)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str != ' ' && *str != '\t' && *str != '\n')
        {
            if (!in_word)
            {
                in_word = 1;
                count++;
            }
        }
        else
            in_word = 0;
        str++;
    }
    return count;
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}

char **ft_split(char *str, char c)
{
    int word_count = 0;
    int i = 0, j = 0, k = 0;
    char **out;

    while (str[i])
    {
        while (str[i] && (str[i] == c))
            i++;
        if (str[i])
            word_count++;
        while (str[i] && (str[i] != c))
            i++;
    }

    out = malloc(sizeof(char *) * (word_count + 1));
    if (!out)
        return NULL;

    i = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == c))
            i++;
        j = i;
        while (str[i] && (str[i] != c))
            i++;
        if (i > j)
        {
            out[k] = malloc(sizeof(char) * ((i - j) + 1));
            if (!out[k])
            {
                while (k > 0)
                    free(out[--k]);
                free(out);
                return NULL;
            }
            ft_strncpy(out[k], &str[j], i - j);
            out[k][i - j] = '\0';
            k++;
        }
    }
    out[k] = NULL;
    return out;
}


int ft_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    
    if (*str == '-' || *str == '+')
    {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }
    
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    
    return sign * result;
}

void ft_free_split(char **split)
{
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}

int ft_word_count(char const *str, char c)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str != c)
        {
            if (!in_word)
            {
                in_word = 1;
                count++;
            }
        }
        else
            in_word = 0;
        str++;
    }
    return count;
}
