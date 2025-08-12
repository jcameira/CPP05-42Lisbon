#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(): AForm( "RobotomyRequestForm", 25, 5 ), _target( "default" ) {
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm( "RobotomyRequestForm", 25, 5 ), _target( target ) {
	std::cout << "RobotomyRequestForm Constructor for target " << this->_target << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm &src ): AForm( "RobotomyRequestForm", 25, 5 ), _target( src.getTarget() ) {
	std::cout << "RobotomyRequestForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->_name << std::endl;

	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Deconstructor " << this->_name << " called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src ) {
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if ( this != &src )
		return ( *this );
	return ( *this );
}

void	RobotomyRequestForm::execute( Bureaucrat const &executor )const {
	if ( executor.getGrade() > this->getExecGrade() )
		throw ( Bureaucrat::GradeTooLowException() );
	else if ( this->getIsSignedBool() == false )
		throw ( AForm::FormNotSignedException() );
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	RobotomyRequestForm::getTarget( void )const {
	return ( this->_target );
}

std::ostream	&operator<<( std::ostream &o, RobotomyRequestForm *a ) {
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return ( o );
}