#ifndef HARL_HPP
# define HARL_HPP
# include "iostream"

class Harl
{
private:
	static void debug(void);
	static void info(void);
	static void warning(void);
	static void error(void);
public:
	Harl();
	void    complain( std::string level );
};

#endif
