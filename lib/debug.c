#include <stdarg.h>
#include <stdio.h>

int debug = 0;

void libsoc_set_debug(int level)
{
#ifdef DEBUG

	if (level) {
		debug = 1;
	} else {
		debug = 0;
	}

#else

	printf("libsoc-gpio: warning debug support missing!\n");

#endif
}

int libsoc_get_debug()
{
#ifdef DEBUG

  return debug;

#else

	printf("libsoc-debug: warning debug support missing!\n");

#endif
}

inline void libsoc_debug(const char *func, char *format, ...)
{
#ifdef DEBUG

	if (debug) {
		va_list args;

		fprintf(stderr, "libsoc-debug: ");

		va_start(args, format);
		vfprintf(stderr, format, args);
		va_end(args);

    fprintf(stderr, " (%s)", func);

		fprintf(stderr, "\n");
	}
#endif
}
