#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include <string>
#include <iostream>
#include <Bureaucrat.hpp>
#include <AForm.hpp>

class Bureaucrat;

class AFrom;

class RobotomyRequestForm: public AForm
{
	private:
		const std::string _target;
		RobotomyRequestForm( void );

	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm &src );

		~RobotomyRequestForm();

		RobotomyRequestForm &operator=( const RobotomyRequestForm &src );

		std::string getTarget( void )const;
        
		void execute( Bureaucrat const &executor )const;

};

std::ostream	&operator<<( std::ostream &o, RobotomyRequestForm *a );

#endif