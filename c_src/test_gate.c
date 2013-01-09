#include "gate.h"

static void parse_approxidate(char **argv)
{
	char buff[100];
	for (; *argv; argv++) {
		time_t t;
		t = approxidate(*argv);
		strftime(buff, 100, "%d/%m/%Y %H:%M:%S", localtime(&t));
		printf("%s -> %s\n", *argv, buff);
	}
}

void usage() {
	printf("usage:\n"
	       "gate_test [date]...\n");
}

int main(int argc, char **argv)
{
	if (!*argv)
		usage();
        else
          parse_approxidate(argv+1);

	return 0;
}
