#include "BSQ.h"

int	ft_line_len(char *line)
{
	int	i;

	i = 0;
	while(line[i])
		i++;
	return (i);
}
