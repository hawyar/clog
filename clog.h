#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define LOG_COLOR_RED     "\x1b[31m"
#define LOG_COLOR_GREEN   "\x1b[32m"
#define LOG_COLOR_YELLOW  "\x1b[33m"
#define LOG_COLOR_BLUE    "\x1b[36m"
#define LOG_COLOR_RESET   "\x1b[0m"

static inline int use_color(void) {
    return getenv("NO_COLOR") == NULL;
}

#define COLOR_START(color) (use_color() ? color : "")
#define COLOR_END() (use_color() ? LOG_COLOR_RESET : "")

#define LOG_TIME() \
    time_t t = time(NULL); \
    char time_str[20]; \
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&t))

#define log_debug(...) do { \
    LOG_TIME(); \
    printf("%s %s[DEBUG]%s %s:%d ", \
        time_str, \
        COLOR_START(LOG_COLOR_BLUE), \
        COLOR_END(), \
        __func__, __LINE__); \
    printf(__VA_ARGS__); \
    printf("\n"); \
} while(0)

#define log_info(...) do { \
    LOG_TIME(); \
    printf("%s %s[INFO]%s  %s:%d ", \
        time_str, \
        COLOR_START(LOG_COLOR_GREEN), \
        COLOR_END(), \
        __func__, __LINE__); \
    printf(__VA_ARGS__); \
    printf("\n"); \
} while(0)

#define log_warn(...) do { \
    LOG_TIME(); \
    printf("%s %s[WARN]%s  %s:%d ", \
        time_str, \
        COLOR_START(LOG_COLOR_YELLOW), \
        COLOR_END(), \
        __func__, __LINE__); \
    printf(__VA_ARGS__); \
    printf("\n"); \
} while(0)

#define log_error(...) do { \
    LOG_TIME(); \
    printf("%s %s[ERROR]%s %s:%d ", \
        time_str, \
        COLOR_START(LOG_COLOR_RED), \
        COLOR_END(), \
        __func__, __LINE__); \
    printf(__VA_ARGS__); \
    printf("\n"); \
} while(0)

#endif
