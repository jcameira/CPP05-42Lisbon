#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(): AForm( "PresidentialPardonForm", 25, 5 ), _target( "default" ) {
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm( "PresidentialPardonForm", 25, 5 ), _target( target ) {
	std::cout << "PresidentialPardonForm Constructor for target " << this->_target << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &src ): AForm( "PresidentialPardonForm", 25, 5 ), _target( src.getTarget() ) {
	std::cout << "PresidentialPardonForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->_name << std::endl;

	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Deconstructor " << this->_name << " called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &src ) {
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if ( this != &src )
		return ( *this );
	return ( *this );
}

void	PresidentialPardonForm::execute( Bureaucrat const &executor )const {
	if ( executor.getGrade() > this->getExecGrade() )
		throw ( Bureaucrat::GradeTooLowException() );
	else if ( this->getIsSignedBool() == false )
		throw ( AForm::FormNotSignedException() );
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	PresidentialPardonForm::getTarget( void )const {
	return ( this->_target );
}

std::ostream	&operator<<( std::ostream &o, PresidentialPardonForm *a ) {
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return ( o );
}