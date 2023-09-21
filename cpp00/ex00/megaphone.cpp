#include <iostream>

int ft_write(char *str)
{
	int i = 0;
	if (!str)
		std::cout << "(null)" << std::endl;
	while (str[i])
	{
		std::cout << str[i];
		i++;
	}
	return (i);
}

int ft_write_upcase(char *str)
{
	int i = 0;
	if (!str)
		std::cout << "(null)" << std::endl;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			std::cout << (char)(str[i] - ('a' - 'A'));
		else
			std::cout << str[i];
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argc > 1)
	{
		argv++;
		ft_write_upcase(*argv);
		argc--;
	}
	std::cout << std::endl;
	return 0;
}
