### Usage

```c
#include "clog.h"

int main() {
    log_debug("debug message");
    log_info("info message");
    log_warn("warning");
    log_error("error message: %d", 505);
    return 0;
}
// 2024-12-30 10:41:00 [DEBUG] main:4 debug message
// 2024-12-30 10:41:00 [INFO]  main:5 info message
// 2024-12-30 10:41:00 [WARN]  main:6 warning
// 2024-12-30 10:41:00 [ERROR] main:7 error message: 505
```
