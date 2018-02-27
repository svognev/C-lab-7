#include <string.h> 

char* process(char* line)
{
	int len = (int)(strlen(line));
	int i, j, k, allLett = 1;
	char tmpSym;
	i = tmpSym = 0;
	j = k = len - 1;

	while (i < j)
	{
		if ((line[i] >= '0') && (line[i] <= '9')) // found a number from the beginning
		{
			allLett = 0;
			while ((line[j] >= '0') && (line[j] <= '9') && (j > i)) // found a letter from the end
				j--;
			if ((line[j] >= 'a') && (line[j] <= 'z')) // characters exchange
			{
				tmpSym = line[i];
				line[i] = line[j];
				line[j] = tmpSym;
				if (j == i + 1) // last exchange
					break;
			}
			else if (j <= i) // all remaining are numbers
				break;
		}
		else if (allLett) // found a letter from the beginning
		{
			while ((line[k] >= 'a') && (line[k] <= 'z') && (k > i))
				k--;
			if (k <= i) // all remaining are letters
				break;
			else
				allLett = 0;
		}
		i++;
	}

	return line;
}