#include<stdio.h>
#include"get_next_line.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define SAMPLE_N 24

int main(void)
{
	int i;
	int j;
	int fd[30];
	char *line;
	int r;

	i = 0;
	fd[0] = open("./TESTCASE/64bit_line.txt", O_RDONLY);
	fd[1] = open("./TESTCASE/64bit_paragraph.txt", O_RDONLY);
	fd[2] = open("./TESTCASE/bar.txt", O_RDONLY);
	fd[3] = open("./TESTCASE/empty.txt", O_RDONLY);
	fd[4] = open("./TESTCASE/fewchar_perline.txt", O_RDONLY);
	fd[5] = open("./TESTCASE/long_line.txt", O_RDONLY);
	fd[6] = open("./TESTCASE/normal.txt", O_RDONLY);
	fd[7] = open("./TESTCASE/only_newline.txt", O_RDONLY);
	fd[8] = open("./TESTCASE/1_newline", O_RDONLY);
	fd[9] = open("./TESTCASE/41_char", O_RDONLY);
	fd[10] = open("./TESTCASE/42_char", O_RDONLY);
	fd[11] = open("./TESTCASE/43_char", O_RDONLY);
	fd[12] = open("./TESTCASE/4_newlines", O_RDONLY);
	fd[13] = open("./TESTCASE/alphabet", O_RDONLY);
	fd[14] = open("./TESTCASE/empty_file", O_RDONLY);
	fd[15] = open("./TESTCASE/empty_lines", O_RDONLY);
	fd[16] = open("./TESTCASE/half_marge_bottom", O_RDONLY);
	fd[17] = open("./TESTCASE/half_marge_top", O_RDONLY);
	fd[18] = open("./TESTCASE/huge_alphabet", O_RDONLY);
	fd[19] = open("./TESTCASE/huge_file", O_RDONLY);
	fd[20] = open("./TESTCASE/huge_line", O_RDONLY);
	fd[21] = open("./TESTCASE/huge_lines", O_RDONLY);
	fd[22] = open("./TESTCASE/huge_lines2", O_RDONLY);
	fd[23] = open("./TESTCASE/mix_marge1", O_RDONLY);
	fd[24] = open("./TESTCASE/mix_marge2", O_RDONLY);

	while (i < SAMPLE_N)
	{
		j = 0;
		r = 0;
		while (j < 200)
		{
			r = get_next_line(fd[i], &line);
//			if (i == 1)
//			printf("%d : %s\n", r, line);
			free(line);
			line = NULL;
			if (fd[i] == -1)
			{
				printf("fd%-4d: file didnt open\n", i);
				break ;
			}
			if (r == -1)
			{
				printf("fd%-4d: error in gnl\n", i);
				break ;
			}
			if (r == 0)
			{
				printf("fd%-4d: finish reading in line%d\n", i, j+1);
				break ;
			}
			j++;
		}
		i++;
	}
	for (int i=0; i<SAMPLE_N; i++)
		close(fd[i]);
	printf("done\n");
	system("leaks check");
//	while(1);
	return (0);
}
