#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat( const std::string name, int grade );
		Bureaucrat( const Bureaucrat &copy );

		~Bureaucrat();

		Bureaucrat &operator=( const Bureaucrat &obj );

        const std::string getName( void ) const;
		int getGrade( void ) const;

        void setGrade( int grade );

		void incrementGrade( void );
		void decrementGrade( void );
		
	class GradeTooLowException : public std::exception
	{
	    public:
		    virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	    public:
		    virtual const char *what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &o, Bureaucrat *a );

#endif