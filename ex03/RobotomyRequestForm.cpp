/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:04:24 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 22:12:53 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void) :
				Form("RobotomyRequestForm", 72, 45, "unknown") {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
				Form(src) {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
				Form("RobotomyRequestForm", 72, 45, target) {

}

RobotomyRequestForm::~RobotomyRequestForm(void) {

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src) {

	(void) src;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {

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
			std::cout << "* Drilling noises * ";
			srand ((unsigned int)time(NULL));
			int	pseudo_random = rand() % 100 + 1;
			if (pseudo_random % 2)
				std::cout << getTarget() << " has been robotomized" << std::endl;
			else
				std::cout << "Robotomy failed" << std::endl;
			break;
	}
}

Form	*RobotomyRequestForm::generateForm(std::string target) {

	return (new RobotomyRequestForm(target));
}
