#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define LEN 6

typedef struct	s_s
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	count;
	unsigned int	index1;
	unsigned int	index2;
	unsigned int	index3;
	char			*character;
	char			*control_str;
	unsigned int	check;
	int				answer;
}				t_s;

typedef struct	s_prefix
{
	char			*name;
	char			*symbol;
	char			*base_10;
	char			*decimal;
	char			*short_scale;
	char			*long_scale;
	unsigned int	adoption_year;
	char			*language;
	char			*derived_word;
	struct s_prefix	*next;
}				t_prefix;

void	mem_set(char *str, char c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len - 1)
	{
		str[i] = c;
		i++;
	}
}

void	str_error(const char *str)
{
	write(1, str, strlen(str));
	printf("\033[2m***********************************************************************************************************************************************************************\033[0m\n");
}

void check_the_length_of_si_prefix(const char *str)
{
	if (strlen(str) > 5)
		str_error("\033[2mthere are no si metric prefix names longer than 5 characters\033[0m\n");
}

void initialize_arr(char *arr[20])
{
	arr[0] = "yocto";
	arr[1] = "zepto";
	arr[2] = "atto";
	arr[3] = "femto";
	arr[4] = "pico";
	arr[5] = "nano";
	arr[6] = "micro";
	arr[7] = "milli";
	arr[8] = "centi";
	arr[9] = "deci";
	arr[10] = "deca";
	arr[11] = "hecto";
	arr[12] = "kilo";
	arr[13] = "mega";
	arr[14] = "giga";
	arr[15] = "tera";
	arr[16] = "peta";
	arr[17] = "exa";
	arr[18] = "zetta";
	arr[19] = "yotta";
}

void	check_for_the_prefix(const char *str, char *arr[20])
{
	int		i;

	i = 0;
	while (strncmp(str, arr[i], strlen(arr[i])) == 0)
		i++;
	if (i == 20)
		str_error("\033[2mthere is no such si metric prefix\033[0m\n");
}

void	initialize_structure(t_s *s)
{
	s->i = 0;
	s->j = 0;
	s->k = 0;
	s->count = 0;
	s->index1 = 0;
	s->index2 = 0;
	s->index3 = 0;
	s->check = 0;
	s->answer = 0;
	s->control_str = "yzeptgmkhdcnfa";
	s->character = NULL;
}

void	find_coincidences(char **arr, t_s *s)
{
	while (s->k < 20)
	{
		if (*s->character == arr[s->k][s->j])
		{
			if (s->check == 0)
			{
				s->index1 = s->k;
				s->check++;
			}
			else if (s->check == 1)
			{
				s->index2 = s->k;
				s->check++;
			}
			else if (s->check == 2)
			{
				s->index3 = s->k;
				s->check++;
				break ;
			}
		}
		s->k++;
	}

}

void	check_the_first_letter(const char *str, char **arr, t_s *s)
{
	while (s->i < 20)
	{
		if (arr[s->i][s->j] == str[s->j])
		{
			s->character = strchr(s->control_str, str[s->j]);
			if (s->character != NULL)
			{
				find_coincidences(arr, s);
				break ;
			}
			s->count++;
		}
		s->i++;
	}
}

void	print_the_info(t_prefix *p)
{
	printf("   \033[2mPrefix\t\t\t\t\t\t\t\t\t\t\tEnglish_name\t\t\t\t\tEtymology\033[0m\n");
	printf("\033[2mName\tSymbol\tBase_10\t\t\t\tDecimal\t\t\t\t\tShort_scale\tLong_scale\tAdoption_year\tLanguage\tDerived_word\033[0m\n");
	printf("%s\t%s\t%s\t\t%s\t\t\t%s\t%s\t%i\t\t%s\t\t%s\n", p->name, p->symbol, p->base_10, p->decimal, p->short_scale, p->long_scale, p->adoption_year, p->language, p->derived_word);
}

void	print_the_info_1(t_prefix *p, int i)
{

	if (i == 0)
	{
		printf("   \033[2mPrefix\t\t\t\t\t\t\t\t\t\t\tEnglish_name\t\t\t\t\tEtymology\033[0m\n");
		printf("\033[2mName\tSymbol\tBase_10\t\t\t\tDecimal\t\t\t\t\tShort_scale\tLong_scale\tAdoption_year\tLanguage\tDerived_word\033[0m\n");
	}
	else if (i != 0)
		printf("%s\t%s\t%s\t\t%s\t\t\t%s\t%s\t%i\t\t%s\t\t%s\n", p->name, p->symbol, p->base_10, p->decimal, p->short_scale, p->long_scale, p->adoption_year, p->language, p->derived_word);
}

size_t  ft_strlen(const char *s)
{
    size_t  index;

    index = 0;
    while (s[index])
        index++;
    return (index);
}

char    *ft_strdup(const char *s1)
{
    char    *s2;
    int     s1_len;
    int     index;

    s1_len = ft_strlen(s1);
    if (!(s2 = (char *)malloc(s1_len + 1)))
        return (NULL);
    index = 0;
    while (s1[index] != '\0')
    {
        s2[index] = s1[index];
        index++;
    }
    s2[index] = '\0';
    return (s2);
}

int     ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - ('a' - 'A'));
    return (c);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  s1_index;
    size_t  s2_index;
    char    *new_str;

    if (!s1 || !s2)
        return (0);
    s1_index = ft_strlen(s1);
    s2_index = ft_strlen(s2);
    if (!(new_str = (char *)malloc(s1_index + s2_index + 1)))
        return (NULL);
    s1_index = 0;
    while (s1[s1_index] != '\0')
    {
        new_str[s1_index] = s1[s1_index];
        s1_index++;
    }
    s2_index = 0;
    while (s2[s2_index] != '\0')
    {
        new_str[s1_index] = s2[s2_index];
        s1_index++;
        s2_index++;
    }
    new_str[s1_index] = '\0';
    return (new_str);
}

static int      ft_count_num(int n)
{
    int index;
    int res;

    index = 0;
    res = n;
    if (n <= 0)
        index = 1;
    while (res != 0)
    {
        res = res / 10;
        index++;
    }
    return (index);
}

char            *ft_itoa(int n)
{
    char    *str;
    int     index;

    index = ft_count_num(n);
    if (!(str = (char *)malloc((index * sizeof(char) + 1))))
        return (NULL);
    str[index] = '\0';
    if (n == -2147483648)
    {
        n = -214748364;
        str[index-- - 1] = '8';
    }
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }
    while (index > 0 && str[index - 1] != '-')
    {
        str[index-- - 1] = n % 10 + '0';
        n = n / 10;
    }
    return (str);
}

int     ft_atoi(const char *str)
{
	int index;
	int sign;
	int atoi;

	index = 0;
	sign = 1;
	atoi = 0;
	while ((str[index] >= '\t' && str[index] <= '\r') || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		atoi = (atoi * 10) + (str[index] - '0');
		index++;
	}
	return (atoi * sign);
}

void	initialize_prefix_yotta(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = ft_toupper(arr[i][j]);
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^24";
	p->decimal = "1 000 000 000 000 000 000 000 000";
	p->short_scale = "septillion   ";
	p->long_scale = "quadrillion  ";
	p->adoption_year = 1991;
	p->language = "Greek";
	p->derived_word = "eight";
}

void	initialize_prefix_zetta(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = ft_toupper(arr[i][j]);
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^21";
	p->decimal = "1 000 000 000 000 000 000 000    ";
	p->short_scale = "sextillion   ";
	p->long_scale = "trilliard    ";
	p->adoption_year = 1991;
	p->language = "Latin";
	p->derived_word = "seven";
}

void	initialize_prefix_exa(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = ft_toupper(arr[i][j]);
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^18";
	p->decimal = "1 000 000 000 000 000 000        ";
	p->short_scale = "quintillion  ";
	p->long_scale = "trillion     ";
	p->adoption_year = 1975;
	p->language = "Greek";
	p->derived_word = "six";
}

void	initialize_prefix_peta(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = ft_toupper(arr[i][j]);
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^15";
	p->decimal = "1 000 000 000 000 000            ";
	p->short_scale = "quadrillion  ";
	p->long_scale = "billiard     ";
	p->adoption_year = 1975;
	p->language = "Greek";
	p->derived_word = "five";
}

void	initialize_prefix_tera(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = ft_toupper(arr[i][j]);
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^12";
	p->decimal = "1 000 000 000 000                ";
	p->short_scale = "trillion     ";
	p->long_scale = "billion      ";
	p->adoption_year = 1960;
	p->language = "Greek";
	p->derived_word = "four, monster";
}

void	initialize_prefix_giga(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = ft_toupper(arr[i][j]);
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^9";
	p->decimal = "1 000 000 000                    ";
	p->short_scale = "billion      ";
	p->long_scale = "milliard      ";
	p->adoption_year = 1960;
	p->language = "Greek";
	p->derived_word = "giant";
}

void	initialize_prefix_mega(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = ft_toupper(arr[i][j]);
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^6";
	p->decimal = "1 000 000                        ";
	p->short_scale = "million      ";
	p->long_scale = "             ";
	p->adoption_year = 1873;
	p->language = "Greek";
	p->derived_word = "great";
}

void	initialize_prefix_kilo(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^3";
	p->decimal = "1 000                            ";
	p->short_scale = "thousand     ";
	p->long_scale = "             ";
	p->adoption_year = 1795;
	p->language = "Greek";
	p->derived_word = "thousand";
}

void	initialize_prefix_hecto(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^2";
	p->decimal = "100                              ";
	p->short_scale = "hundred     ";
	p->long_scale = "             ";
	p->adoption_year = 1795;
	p->language = "Greek";
	p->derived_word = "hundred";
}

void	initialize_prefix_deca(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "a");
	p->base_10 = "10^1";
	p->decimal = "10                               ";
	p->short_scale = "ten          ";
	p->long_scale = "             ";
	p->adoption_year = 1795;
	p->language = "Greek";
	p->derived_word = "ten";
}

void	initialize_prefix_deci(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-1";
	p->decimal = "0.1                              ";
	p->short_scale = "tenth        ";
	p->long_scale = "             ";
	p->adoption_year = 1795;
	p->language = "Latin";
	p->derived_word = "ten";
}

void	initialize_prefix_centi(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-2";
	p->decimal = "0.01                             ";
	p->short_scale = "hundredth    ";
	p->long_scale = "             ";
	p->adoption_year = 1795;
	p->language = "Latin";
	p->derived_word = "hundred";
}

void	initialize_prefix_milli(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-3";
	p->decimal = "0.001                            ";
	p->short_scale = "thousandth   ";
	p->long_scale = "             ";
	p->adoption_year = 1795;
	p->language = "Latin";
	p->derived_word = "thousand";
}

void	initialize_prefix_micro(t_prefix *p, char *arr[20], unsigned int i)
{
	p->name = arr[i];
	p->symbol = ft_strdup("μ");
	p->base_10 = "10^-6";
	p->decimal = "0.000 001                        ";
	p->short_scale = "millionth    ";
	p->long_scale = "             ";
	p->adoption_year = 1873;
	p->language = "Greek";
	p->derived_word = "small";
}

void	initialize_prefix_nano(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-9";
	p->decimal = "0.000 000 001                    ";
	p->short_scale = "billionth    ";
	p->long_scale = "milliardth   ";
	p->adoption_year = 1960;
	p->language = "Greek";
	p->derived_word = "dwarf";
}

void	initialize_prefix_pico(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-12";
	p->decimal = "0.000 000 000 001                ";
	p->short_scale = "trillionth   ";
	p->long_scale = "billionth    ";
	p->adoption_year = 1960;
	p->language = "Spanish";
	p->derived_word = "peak";
}

void	initialize_prefix_femto(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-15";
	p->decimal = "0.000 000 000 000 001            ";
	p->short_scale = "quadrillionth";
	p->long_scale = "billiardth   ";
	p->adoption_year = 1964;
	p->language = "Danish";
	p->derived_word = "fifteen";
}

void	initialize_prefix_atto(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-18";
	p->decimal = "0.000 000 000 000 000 001       ";
	p->short_scale = "quintillionth";
	p->long_scale = "trillionth   ";
	p->adoption_year = 1964;
	p->language = "Danish";
	p->derived_word = "eighteen";
}

void	initialize_prefix_zepto(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-21";
	p->decimal = "0.000 000 000 000 000 000 001    ";
	p->short_scale = "sextillionth ";
	p->long_scale = "trilliardth  ";
	p->adoption_year = 1991;
	p->language = "Latin";
	p->derived_word = "seven";
}

void	initialize_prefix_yocto(t_prefix *p, char *arr[20], unsigned int i)
{
	unsigned int		j;
	char				c;

	j = 0;
	p->name = arr[i];
	c = arr[i][j];
	p->symbol = ft_strjoin(&c, "\0");
	p->base_10 = "10^-24";
	p->decimal = "0.000 000 000 000 000 000 000 001";
	p->short_scale = "septillionth ";
	p->long_scale = "quadrillionth";
	p->adoption_year = 1991;
	p->language = "Greek";
	p->derived_word = "eight";
}

void	print_all(char *arr[20], unsigned int i)
{
	t_prefix 	p;

	while (i < 20)
	{
		if (i == 0)
		{
			initialize_prefix_yocto(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 1)
		{
			initialize_prefix_zepto(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 2)
		{
			initialize_prefix_atto(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 3)
		{
			initialize_prefix_femto(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 4)
		{
			initialize_prefix_pico(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 5)
		{
			initialize_prefix_nano(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 6)
		{
			initialize_prefix_micro(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 7)
		{
			initialize_prefix_milli(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 8)
		{
			initialize_prefix_centi(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 9)
		{
			initialize_prefix_deci(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 10)
		{
			initialize_prefix_deca(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 11)
		{
			initialize_prefix_hecto(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 12)
		{
			initialize_prefix_kilo(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 13)
		{
			initialize_prefix_mega(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 14)
		{
			initialize_prefix_giga(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 15)
		{
			initialize_prefix_tera(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 16)
		{
			initialize_prefix_peta(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 17)
		{
			initialize_prefix_exa(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 18)
		{
			initialize_prefix_zetta(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
		else if (i == 19)
		{
			initialize_prefix_yotta(&p, arr, i);
			print_the_info_1(&p, i);
			i++;
		}
	}
	exit (EXIT_SUCCESS);
}

void	choose_the_prefix(char *arr[20], int s_index)
{
	t_prefix 	p;
	unsigned int	i;

	i = 0;
	while (i < 20)
	{
		if (s_index <= 9)
		{
			if (strncmp(arr[i], arr[s_index], strlen(arr[s_index])))
			{
				i++;
				continue ;
			}
			else
			{
				break ;
			}
		}
		else if (s_index >= 9)
		{
			if (strncmp(arr[i], arr[s_index], strlen(arr[s_index])))
			{
				i++;
				continue ;
			}
			else
			{
				break ;
			}
		}
	}
	if (i == 0)
		initialize_prefix_yocto(&p, arr, i);
	else if (i == 1)
		initialize_prefix_zepto(&p, arr, i);
	else if (i == 2)
		initialize_prefix_atto(&p, arr, i);
	else if (i == 3)
		initialize_prefix_femto(&p, arr, i);
	else if (i == 4)
		initialize_prefix_pico(&p, arr, i);
	else if (i == 5)
		initialize_prefix_nano(&p, arr, i);
	else if (i == 6)
		initialize_prefix_micro(&p, arr, i);
	else if (i == 7)
		initialize_prefix_milli(&p, arr, i);
	else if (i == 8)
		initialize_prefix_centi(&p, arr, i);
	else if (i == 9)
		initialize_prefix_deci(&p, arr, i);
	else if (i == 10)
		initialize_prefix_deca(&p, arr, i);
	else if (i == 11)
		initialize_prefix_hecto(&p, arr, i);
	else if (i == 12)
		initialize_prefix_kilo(&p, arr, i);
	else if (i == 13)
		initialize_prefix_mega(&p, arr, i);
	else if (i == 14)
		initialize_prefix_giga(&p, arr, i);
	else if (i == 15)
		initialize_prefix_tera(&p, arr, i);
	else if (i == 16)
		initialize_prefix_peta(&p, arr, i);
	else if (i == 17)
		initialize_prefix_exa(&p, arr, i);
	else if (i == 18)
		initialize_prefix_zetta(&p, arr, i);
	else if (i == 19)
		initialize_prefix_yotta(&p, arr, i);
	sleep(1);
	printf("\n");
	sleep(1);
	print_the_info(&p);
}

void	while_for_check_1(t_s *s, char *arr[20])
{
		while (s->answer > 0)
		{
			if (s->answer == 1)
			{
				printf("Great!\nHere is some info about %s prefix\n", arr[s->index1]);
				choose_the_prefix(arr, s->index1);
				break ;
			}
			else 
			{
				printf("\033[2mthere is no such option\033[0m\n");
				printf("\033[2mdid you mean \033[0m%s(1)?\n", arr[s->index1]);
			}
		}
}

void	while_for_check_2(t_s *s, char *arr[20])
{
		while (s->answer > 0)
		{
			if (s->answer == 1 || s->answer == 2)
			{
				if (s->answer == 1)
				{
					printf("Great!\nHere is some info about %s prefix\n", arr[s->index1]);
					choose_the_prefix(arr, s->index1);
				}
				else if (s->answer == 2)
				{
					printf("Great!\nHere is some info about %s prefix\n", arr[s->index2]);
					choose_the_prefix(arr, s->index2);
				}
				break ;
			}
			else if (s->answer < 1 || s->answer > 2)
			{
				printf("\033[2mthere is no such option\033[0m\n");
				printf("\033[2mdid you mean \033[0m%s(1), %s(2)?\n", arr[s->index1], arr[s->index2]);
				scanf("%d", &s->answer);
			}
		}

}

void	while_for_check_3(t_s *s, char *arr[20])
{
		while (s->answer > 0)
		{
			if (s->answer >= 1 && s->answer <= 3)
			{
				if (s->answer == 1)
				{
					printf("Great!\nHere is some info about %s prefix\n", arr[s->index1]);
					choose_the_prefix(arr, s->index1);
				}
				else if (s->answer == 2)
				{
					printf("Great!\nHere is some info about %s prefix\n", arr[s->index2]);
					choose_the_prefix(arr, s->index2);
				}
				else if (s->answer == 3)
				{
					printf("Great!\nHere is some info about %s prefix\n", arr[s->index3]);
					choose_the_prefix(arr, s->index3);
				}
				break ;
			}
			else if (s->answer < 1 || s->answer > 3)
			{
				printf("\033[2mthere is no such option\033[0m\n");
				printf("\033[2mdid you mean \033[0m%s(1), %s(2) or %s(3)?\n", arr[s->index1], arr[s->index2], arr[s->index3]);
				scanf("%d", &s->answer);
			}
		}
}

void	suggest_something_if_there_is_a_coincidence(const char *str, char *arr[20])
{
	t_s s;
	initialize_structure(&s);

	check_the_first_letter(str, arr, &s);
	if (s.check == 0)
	{
		str_error("\033[2mthere is no such si metric prefix\033[0m\n");
		exit(EXIT_FAILURE);
	}
	else if (s.check == 1)
	{
		printf("\033[2mdid you mean \033[0m%s(1)?\n", arr[s.index1]);
		scanf("%d", &s.answer);
		while_for_check_1(&s, arr);
	}
	else if (s.check == 2)
	{
		printf("\033[2mdid you mean \033[0m%s(1) or %s(2)?\n", arr[s.index1], arr[s.index2]);
		scanf("%d", &s.answer);
		while_for_check_2(&s, arr);
	}
	else if (s.check == 3)
	{
		printf("\033[2mdid you mean \033[0m%s(1), %s(2) or %s(3)?\n", arr[s.index1], arr[s.index2], arr[s.index3]);
		scanf("%d", &s.answer);
		while_for_check_3(&s, arr);
	}
}

void output_prompt()
{
	printf("\033[2m***********************************************************************************************************************************************************************\033[0m\n");
	printf("enter a si metric prefix:\n\033[2mif you do not know what to "
		   "enter\ntry to type any letter, for example 'p'\nor \"all\", if you "
		   "would like to "
		   "see "
		   "all the si prefixes\n\033[0m");
	return ;
}

int		main(void)
{
	char			str[LEN];
	char			*arr[20];

	initialize_arr(arr);
	mem_set(str, '\0', LEN);
	str[LEN - 1] = '\n';
	output_prompt();
	scanf("%s", str);
	if (strncmp(str, "all", ft_strlen(str) + 1) == 0)
		print_all(arr, 0);
	check_the_length_of_si_prefix(str);
	check_for_the_prefix(str, arr);
	suggest_something_if_there_is_a_coincidence(str, arr);
	printf("\033[2m***********************************************************************************************************************************************************************\033[0m\n");
	return (0);
}
