/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:42:35 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 01:50:22 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define TEST1 1
#define TEST2 1
#define TEST3 1
#define TEST4 1
#define TEST5 0

int	main(void) {

	try {
		std::cout << std::endl <<"Basic Test: No Exception should be thrown" << std::endl;
		Bureaucrat	b("Hermann", 142);
		Form	form1;
		Form	form2("FormA", 142, 140);

		std::cout << b <<std::endl;
		std::cout << form1 <<std::endl;
		std::cout << form2 <<std::endl;
		b.signForm(form2);
		form2.beSigned(b);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	if (TEST1) {
		std::cout << std::endl <<"Test1: Exception: GradeTooHigh should be thrown" << std::endl;
		try {
			Form	form("tooHigh", 0, 1);
			//Form	form("tooHigh", 1, 0);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (TEST2) {
		std::cout << std::endl << "Test2: Exception: GradeTooLow should be thrown" << std::endl;
		try {
			Form	form("tooLow", 151, 1);
			//Form	form("tooLow", 1, 151);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (TEST3) {
		std::cout << std::endl << "Test3: Exception: GradeTooLow should be thrown" << std::endl;

		try {
			Bureaucrat	b("Hermann", 142);
			Form	form("FormA", 142, 140);

			b.decrement();
			std::cout << b <<std::endl;
			std::cout << form <<std::endl;
			b.signForm(form);
			//form.beSigned(b);
		}
		catch (std::exception &e) {
				std::cout << e.what() << std::endl;
		}
	}
	if (TEST4) {
		std::cout << std::endl << "Test4: Exception: GradeTooLow should be thrown" << std::endl;

		try {
			Bureaucrat	b("Hermann", 142);
			Form	form("FormA", 142, 140);

			b.decrement();
			std::cout << b <<std::endl;
			std::cout << form <<std::endl;
			//b.signForm(form);
			form.beSigned(b);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (TEST5) {

		try {

		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
