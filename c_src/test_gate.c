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
	printf("usage: test_gate date...\n");
}

int main(int argc, char **argv)
{
	argv++;
	if (!*argv)
		usage();
        else
          parse_approxidate(argv);

	return 0;
}
