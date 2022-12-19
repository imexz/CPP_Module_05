/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:43:11 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 22:40:21 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {

}

Intern::Intern(Intern const &src) {

	(void) src;
}

Intern::~Intern(void) {

}

Intern	&Intern::operator=(Intern const &src) {

	(void) src;
	return (*this);
}

Form	*Intern::makeForm(std::string form, std::string target) {

	std::string	forms[] = {
		"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"
	};
	Form	*(*formSource[3]) (std::string target_of_form) = {
		ShrubberyCreationForm::generateForm,
		RobotomyRequestForm::generateForm,
		PresidentialPardonForm::generateForm
	};
	for (int i = 0; i < 3; i++) {
		if (forms[i] == form) {
			std::cout << "Intern creates " << form << std::endl;
			return (formSource[i](target));
		}
	}
	throw (std::invalid_argument("Such a form does not exist"));
}
