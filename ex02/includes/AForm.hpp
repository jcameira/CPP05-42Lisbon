#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>
# include <Bureaucrat.hpp>

class Bureaucrat;

class AForm
{
	protected:
		const std::string _name;
		bool _is_signed;
		const int _sign_grade;
		const int _exec_grade;

	public:
		AForm( void );
		AForm( const AForm &src );
		AForm( const std::string name, int sign_grade, int exec_grade );

		virtual	~AForm();

		AForm &operator=( const AForm &src );

		const std::string getName( void )const;
		const std::string getIsSigned( void )const;
		bool getIsSignedBool( void )const;
		int getSignGrade( void )const;
		int getExecGrade( void )const;

		void beSigned( Bureaucrat &signer );
		virtual void execute(Bureaucrat const &executor)const = 0;

	class GradeTooLowException : public std::exception {
	    public:
	    	virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
	    public:
	    	virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &o, AForm *a );

#endif