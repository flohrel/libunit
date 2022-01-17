#include "libunit.h"

void	print_signal(int32_t status)
{
	fprintf(stdout, RED);
	if (WTERMSIG(status) == SIGALRM)
		fprintf(stdout, "%20s\n", "Timeout");
	else if (WTERMSIG(status) == SIGSEGV)
		fprintf(stdout, "%20s\n", "Segfault");
	else if (WTERMSIG(status) == SIGBUS)
		fprintf(stdout, "%20s\n", "Bus error");
	else if (WTERMSIG(status) == SIGABRT)
		fprintf(stdout, "%20s\n", "Abort");
	else if (WTERMSIG(status) == SIGFPE)
		fprintf(stdout, "%20s\n", "Floating-point exception");
	else if (WTERMSIG(status) == SIGPIPE)
		fprintf(stdout, "%20s\n", "Broken pipe");
	else if (WTERMSIG(status) == SIGILL)
		fprintf(stdout, "%20s\n", "Illegal instruction");
	fprintf(stdout, RESET);
}

void	print_result(t_unit *unit, int32_t count)
{
	int32_t	status;
	(void)unit;

	wait(&status);
	fprintf(stdout, "%02d) %-20s", count, unit->name);
	if (WIFEXITED(status) == true)
	{
		if (WEXITSTATUS(status) == EXIT_SUCCESS)
			fprintf(stdout, GRN"%20s\n", "[OK]");
		else
			fprintf(stdout, RED"%20s\n", "[KO]");
	}
	else if (WIFSIGNALED(status))
		print_signal(status);
	else
		fprintf(stdout, RED"Unknown error\n");
	fprintf(stdout, RESET);
}

void	print_header(const char *str)
{
	uint32_t	i;
	size_t		len;

	i = 0;
	len = ft_strlen(str) + 20;
	fprintf(stdout, MAG);
	while (i++ < len)
		fprintf(stdout, "#");
	fprintf(stdout, "\n");
	fprintf(stdout, "#####     "CYN"%s"MAG"     #####\n", str);
	while (--i)
		fprintf(stdout, "#");
	fprintf(stdout, "\n");
	fprintf(stdout, RESET);
}