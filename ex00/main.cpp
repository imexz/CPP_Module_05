/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:42:35 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 00:38:47 by mstrantz         ###   ########.fr       */
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
		Bureaucrat bob("Bob", 142);
		Bureaucrat bob2(bob);
		Bureaucrat x;

		std::cout << bob << std::endl;
		std::cout << x << std::endl;
		std::cout << "Before incrementing grade: " << bob2 << std::endl;
		bob2.increment();
		std::cout << "After incrementing grade: " << bob2 << std::endl;
		bob2.decrement();
		std::cout << "After decrementing grade: " << bob2 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	if (TEST1) {
		std::cout << std::endl <<"Test1: Exception: GradeTooHigh should be thrown" << std::endl;
		try {
			Bureaucrat temp1("Irelia", 0);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (TEST2) {
		std::cout << std::endl << "Test2: Exception: GradeTooLow should be thrown" << std::endl;
		try {
			Bureaucrat temp2("Teemo", 151);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (TEST3) {
		std::cout << std::endl << "Test3: Exception: GradeTooLow should be thrown" << std::endl;
		Bureaucrat bob("Bob", 142);
		try {
			for (int i = bob.getGrade(); i < 152; i++) {
				bob.decrement();
				std::cout << bob << std::endl;
			}
		}
		catch (std::exception &e) {
				std::cout << e.what() << std::endl;
		}
	}
	if (TEST4) {
		std::cout << std::endl << "Test4: Exception: GradeTooHigh should be thrown" << std::endl;
		Bureaucrat bob("Bob", 142);
		try {
			for (int i = bob.getGrade(); i > 0 ; i--) {
				bob.increment();
			}
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	if (TEST5) {
		// change Bureaucrat.cpp Copy Constructor initialization list attribute src.getGrade() to src.getGrade() - 1
		std::cout << std::endl << "Test5: Exception: GradeTooHigh should be thrown, but uncaught ->abort" << std::endl;
		Bureaucrat nono1("Karthus", 1);
		std::cout << nono1 << std::endl;
		try {
				Bureaucrat nono2(nono1);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
