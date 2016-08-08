# c/c++ codesnippet

```c++
float constrainf(float val, float threshold)
{
	return (val >= 0.0 ? (val > threshold ? threshold : val) : (val < -threshold ? -threshold : val));
}
```

```C++
#include <unistd.h>
sleep(sec);
usleep(micro second)
```

```c
#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
```
