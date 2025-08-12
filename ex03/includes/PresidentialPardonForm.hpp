#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include <string>
#include <iostream>
#include <Bureaucrat.hpp>
#include <AForm.hpp>

class Bureaucrat;

class AFrom;

class PresidentialPardonForm: public AForm
{
	private:
		const std::string _target;
		PresidentialPardonForm( void );

	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm &src );

		~PresidentialPardonForm();

		PresidentialPardonForm &operator=( const PresidentialPardonForm &src );

		std::string getTarget( void )const;
        
		void execute( Bureaucrat const &executor )const;

};

std::ostream	&operator<<( std::ostream &o, PresidentialPardonForm *a );

#endif