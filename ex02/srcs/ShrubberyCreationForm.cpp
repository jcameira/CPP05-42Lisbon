#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm( "ShrubberyCreationForm", 25, 5 ), _target( "default" ) {
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm( "ShrubberyCreationForm", 25, 5 ), _target( target ) {
	std::cout << "ShrubberyCreationForm Constructor for target " << this->_target << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm &src ): AForm( "ShrubberyCreationForm", 25, 5 ), _target( src.getTarget() ) {
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << src.getName() <<
	" into " << this->_name << std::endl;

	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Deconstructor " << this->_name << " called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src ) {
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if ( this != &src )
		return ( *this );
	return ( *this );
}

void	ShrubberyCreationForm::execute( Bureaucrat const &executor )const {
	if ( executor.getGrade() > this->getExecGrade() )
		throw ( Bureaucrat::GradeTooLowException() );
	else if ( this->getIsSignedBool() == false )
		throw ( AForm::FormNotSignedException() );
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget( void )const {
	return ( this->_target );
}

std::ostream	&operator<<( std::ostream &o, ShrubberyCreationForm *a ) {
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return ( o );
}