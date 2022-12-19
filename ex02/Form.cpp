/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:40:34 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 04:21:57 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :  _name("unknown"), _signed(false), _gradeReq(150), _gradeExe(150), _target("unknown"){

}

Form::Form(const std::string name, const unsigned int gradeReq, const unsigned int gradeExe, const std::string target) :
	_name(name), _signed(false), _gradeReq(gradeReq), _gradeExe(gradeExe), _target(target) {

	if (_gradeReq < 1 || _gradeExe < 1)
		throw (GradeTooHighExcep);
	else if (_gradeReq > 150 || _gradeExe > 150)
		throw (GradeTooLowExcep);
}

Form::Form(Form const &src) :	_name(src.getName()), _signed(false), _gradeReq(src.getGradeReq()),
								_gradeExe(src.getGradeExe()), _target(src.getTarget()) {

	if (_gradeReq < 1 || _gradeExe < 1)
		throw (GradeTooHighExcep);
	else if (_gradeReq > 150 || _gradeExe > 150)
		throw (GradeTooLowExcep);
}

Form::~Form(void) {

}

Form	&Form::operator=(Form const &src) {

	(void) src;
	return (*this);
}

const std::string	Form::getName(void) const {

	return (_name);
}

bool	Form::getSigned(void) const {

	return (_signed);
}

unsigned int	Form::getGradeReq(void) const {

	return (_gradeReq);
}

unsigned int	Form::getGradeExe(void) const {

	return (_gradeExe);
}

std::string	Form::getTarget(void) const {

	return (_target);
}

void	Form::beSigned(Bureaucrat const &signee) {

	switch ((int)(signee.getGrade() <= _gradeReq))
	{
	case 0:
		throw(GradeTooLowExcep);
		break;

	case 1:
		_signed = true;
		break;
	}
}

std::ostream	&operator<<(std::ostream &o, Form const &src) {

	o << "Name:            " << src.getName() << std::endl;
	o << "Signed:          " << src.getSigned() << std::endl;
	o << "Grade Required:  " << src.getGradeReq() << std::endl;
	o << "Grade Execution: " << src.getGradeExe() << std::endl;
	o << "Target:          " << src.getTarget() << std::endl;
	return (o);
}
