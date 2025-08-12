#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat( void ): _name( "default" ), _grade( 150 ) {
	std::cout << "Bureaucrat Default Constructor called for " << _name <<
	" with grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( const std::string name, int grade ): _name( name ) {
    this->setGrade( grade );
	std::cout << "Bureaucrat Constructor called for " << _name <<
	" with grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &copy ): _name(copy.getName()) {
    *this = copy;
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat Deconstructor for " << _name << " called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &obj ) {
	std::cout << "Bureaucrat Assign operator called" << std::endl;
	if ( this != &obj )
	    this->_grade = obj.getGrade();
	return ( *this );
}

const std::string   Bureaucrat::getName( void ) const {
	return ( this->_name );
}

int	Bureaucrat::getGrade( void ) const {
	return ( this->_grade );
}

void	Bureaucrat::setGrade( int grade ) {
	if ( grade > 150 )
		throw ( Bureaucrat::GradeTooLowException() );
	else if ( grade < 1 )
		throw ( Bureaucrat::GradeTooHighException() );
	else
		this->_grade = grade;
}

void	Bureaucrat::incrementGrade( void ) {
	std::cout << "Trying to increment grade of " << this->_name << std::endl;
	this->setGrade( this->_grade - 1 );
}

void	Bureaucrat::decrementGrade( void ) {
	std::cout << "Trying to decrement grade of " << this->_name << std::endl;
	this->setGrade( this->_grade + 1 );
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ( "Grade too low" );
};

const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ( "Grade too high" );
};

std::ostream	&operator<<( std::ostream &o, Bureaucrat *a ) {
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << "." << std::endl;
	return (o);
}