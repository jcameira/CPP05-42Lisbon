#include <AForm.hpp>

AForm::AForm( void ): _name( "default" ), _is_signed( false ), _sign_grade( 150 ), _exec_grade( 150 ) {
	std::cout << "Form Default Constructor called" << std::endl;
}

AForm::AForm( const AForm &copy ): _name( copy.getName() ), _is_signed( false ), _sign_grade( copy.getSignGrade() ), _exec_grade( copy.getExecGrade() ) {
	std::cout << "Form Copy Constructor called to copy " << copy.getName() << " into " << this->getName() << std::endl;
	*this = copy;
}

AForm::AForm( const std::string name, int sign_grade, int exec_grade ): _name( name ), _is_signed( false ), _sign_grade( sign_grade ), _exec_grade( exec_grade ) {
	std::cout << "Form Constructor called for " << this->getName() << " with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade << std::endl;
	if ( this->_sign_grade > 150 || this->_exec_grade > 150 )
		throw( AForm::GradeTooLowException() );
	else if( this->_sign_grade < 1 || this->_exec_grade < 1 )
		throw( AForm::GradeTooHighException() );
}

AForm::~AForm( void ) {
	std::cout << "Form Deconstructor for " << _name << " called" << std::endl;
}   

AForm &AForm::operator=( const AForm &obj ) {
	std::cout << "Form Assignation operator called" << std::endl;
    if ( this != &obj ) {
        return ( *this );
    }
	return ( *this );
}

void AForm::beSigned( Bureaucrat &signer ) {
	if ( signer.getGrade() > this->_sign_grade )
		throw(Bureaucrat::GradeTooLowException());
	else if ( this->getIsSigned() == "✗ false" )
	{
		this->_is_signed = true;
		std::cout << this->_name << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->_name << " Form is already signed" << std::endl;
}

const std::string	AForm::getName( void ) const {
	return ( this->_name );
}

const std::string	AForm::getIsSigned( void ) const {
	if ( this->_is_signed )
		return ( "✓ true" );
	else
		return ( "✗ false" );
}

bool	AForm::getIsSignedBool( void ) const {
	return ( this->_is_signed );
}

int	AForm::getSignGrade(void ) const {
	return ( this->_sign_grade );
}

int	AForm::getExecGrade( void ) const {
	return ( this->_exec_grade );
}

void AForm::execute( Bureaucrat const &executor ) const {
	( void )executor;
}

const char *AForm::GradeTooLowException::what( void ) const throw() {
	return ( "Grade too low" );
};

const char *AForm::GradeTooHighException::what( void ) const throw() {
	return ( "Grade too high" );
};

const char *AForm::FormNotSignedException::what( void ) const throw() {
	return ( "Form needs to be signed before executing" );
};

std::ostream	&operator<<( std::ostream &o, AForm *a ) {
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;	
	return ( o );
}