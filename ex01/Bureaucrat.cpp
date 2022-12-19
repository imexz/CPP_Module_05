/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:42:33 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 01:57:09 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150) {

	//std::cout << "Bureaucrat: Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name), _grade(grade) {

	//std::cout << "Bureaucrat: Parameterized Constructor called" << std::endl;
	if (_grade < 1)
		throw (GradeTooHighExcep);
	else if (_grade > 150)
		throw (GradeTooLowExcep);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade()) {  // for Testcase 5: _grade(src.getGrade() - 1

	//std::cout << "Bureaucrat: Copy Constructor called" << std::endl;
	if (_grade < 1)
		throw (GradeTooHighExcep);
	else if (_grade > 150)
		throw (GradeTooLowExcep);
}

Bureaucrat::~Bureaucrat(void) {

	//std::cout << "Bureaucrat: Destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src) {

	//std::cout << "Bureaucrat: Assignment Operator called" << std::endl;
	_grade = src.getGrade();
	if (_grade < 1)
		throw (GradeTooHighExcep);
	else if (_grade > 150)
		throw (GradeTooLowExcep);
	return (*this);
}

const std::string	Bureaucrat::getName(void) const {

	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const {

	return (_grade);
}

void	Bureaucrat::increment(void) {

	_grade--;
	if (_grade < 1)
		throw (GradeTooHighExcep);
	else if (_grade > 150)
		throw (GradeTooLowExcep);

}

void	Bureaucrat::decrement(void) {

	_grade++;
	if (_grade < 1)
		throw (GradeTooHighExcep);
	else if (_grade > 150)
		throw (GradeTooLowExcep);
}

void	Bureaucrat::signForm(Form &form) {

	switch ((int)(form.getGradeReq() >= _grade))
	{
	case 0:
		std::cout << getName() << " couldn't sign " << form.getName() << " because ";
		throw (GradeTooLowExcep);
		break;

	case 1:
		std::cout << getName() << " signed " << form.getName() << std::endl;
		break;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src) {

	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (o);
}
