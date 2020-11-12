#include <stdlib.h>
#include <stdio.h>

int			is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

long long	get_word_cnt(char *str, char *charset)
{
	long long cnt;

	cnt = 0;
	while (*str)
	{
		if (!is_in_charset(*str, charset))
		{
			++cnt;
			while (*str && !is_in_charset(*str, charset))
				++str;
		}
		++str;
	}
	return (cnt);
}

void		ft_strcpy(char *dst, char *from, char *until)
{
	while (from < until)
		*(dst++) = *(from++);
	*dst = 0;
}

char		**ft_split(char *str, char *charset)
{
	char		**ret;
	long long	idx;
	char		*from;

	ret = (char**)malloc(sizeof(char*) * get_word_cnt(str, charset) + 1);
	idx = 0;
	while (*str)
	{
		if (!is_in_charset(*str, charset))
		{
			from = str;
			while (*str && !is_in_charset(*str, charset))
				++str;
			ret[idx] = (char*)malloc(str - from + 1);
			ft_strcpy(ret[idx++], from, str);
		}
		++str;
	}
	ret[idx] = 0;
	return (ret);
}

int main()
{
	char **huhu;
	huhu = ft_split("coucouPjePRsuisOUTunPTpetitRUOTPblagueur.", "PROUT");
	int i = 0;
	while (i < 7)
	{
		printf("%s ", huhu[i++]);
	}
}