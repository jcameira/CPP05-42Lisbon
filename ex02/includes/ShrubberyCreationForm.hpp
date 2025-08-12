#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include <string>
#include <iostream>
#include <Bureaucrat.hpp>
#include <AForm.hpp>

class Bureaucrat;

class AFrom;

class ShrubberyCreationForm: public AForm
{
	private:
		const std::string _target;
		ShrubberyCreationForm( void );

	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm &src );

		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &src );

		std::string getTarget( void )const;
        
		void execute( Bureaucrat const &executor )const;

};

std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm *a );

#endif