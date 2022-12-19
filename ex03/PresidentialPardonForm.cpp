/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:04:14 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 22:14:12 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
				Form("PresidentialPardonForm", 25, 5, "unknown") {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
				Form(src) {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
				Form("PresidentialPardonForm", 25, 5, target) {

}

PresidentialPardonForm::~PresidentialPardonForm(void) {

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src) {

	(void) src;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {

	switch ((int) (getSigned() && executor.getGrade() <= getGradeExe()))
	{
		case 0:
			if (!getSigned()) {
				throw (UnsignedFormExcep);
			}
			else {
				std::cout << executor.getName() << " couldn't execute " << getName() << " because ";
				throw (GradeTooLowExcep);
			}
			break;

		case 1:
			std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
			break;
	}
}

Form	*PresidentialPardonForm::generateForm(std::string target) {

	return (new PresidentialPardonForm(target));
}
