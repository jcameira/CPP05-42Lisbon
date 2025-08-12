#include <Form.hpp>

Form::Form( void ): _name( "default" ), _is_signed( false ), _sign_grade( 150 ), _exec_grade( 150 ) {
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form( const Form &copy ): _name( copy.getName() ), _is_signed( false ), _sign_grade( copy.getSignGrade() ), _exec_grade( copy.getExecGrade() ) {
	std::cout << "Form Copy Constructor called to copy " << copy.getName() << " into " << this->getName() << std::endl;
	*this = copy;
}

Form::Form( const std::string name, int sign_grade, int exec_grade ): _name( name ), _is_signed( false ), _sign_grade( sign_grade ), _exec_grade( exec_grade ) {
	std::cout << "Form Constructor called for " << this->getName() << " with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade << std::endl;
	if ( this->_sign_grade > 150 || this->_exec_grade > 150 )
		throw( Form::GradeTooLowException() );
	else if( this->_sign_grade < 1 || this->_exec_grade < 1 )
		throw( Form::GradeTooHighException() );
}

Form::~Form( void ) {
	std::cout << "Form Deconstructor for " << _name << " called" << std::endl;
}   

Form &Form::operator=( const Form &obj ) {
	std::cout << "Form Assignation operator called" << std::endl;
    if ( this != &obj ) {
        return ( *this );
    }
	return ( *this );
}

void Form::beSigned( Bureaucrat &signer ) {
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

const std::string	Form::getName( void )const {
	return ( this->_name );
}

const std::string	Form::getIsSigned( void )const {
	if ( this->_is_signed )
		return ( "✓ true" );
	else
		return ( "✗ false" );
}

bool	Form::getIsSignedBool( void )const {
	return ( this->_is_signed );
}

int	Form::getSignGrade(void )const {
	return ( this->_sign_grade );
}

int	Form::getExecGrade( void )const {
	return ( this->_exec_grade );
}

const char *Form::GradeTooLowException::what( void ) const throw() {
	return ( "Grade too low" );
};

const char *Form::GradeTooHighException::what( void ) const throw() {
	return ( "Grade too high" );
};

std::ostream	&operator<<( std::ostream &o, Form *a ) {
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getSignGrade() <<
	"\n\texec-grade:\t" << a->getExecGrade() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return ( o );
}