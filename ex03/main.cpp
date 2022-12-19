/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:42:35 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 22:47:11 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define TESTS_1 1
#define TESTS_2 1
#define TESTS_3 1
#define TESTS_4 1


int main( void )
{
	#if TESTS_1
	{
		std::cout << "TEST1 ----------------------------------------------" << std::endl;
		try
		{
			Intern	someIntern;
			Form	*form;

			form = someIntern.makeForm("PresidentialPardonForm", "Toto");
			std::cout << *form << std::endl;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	#endif

	#if TESTS_2
	{
		std::cout << std::endl << "TEST2 ----------------------------------------------" << std::endl;
		try
		{
			Intern	someIntern;
			Form	*form;

			form = someIntern.makeForm("NonExistingForm", "Toto");
			std::cout << *form << std::endl;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	#endif

	#if TESTS_3
	{
		std::cout << std::endl << "TEST3 ----------------------------------------------" << std::endl;
		try
		{
			Intern	someIntern;
			Form	*form;

			form = someIntern.makeForm("ShrubberyCreationForm", "Toto");
			std::cout << *form << std::endl;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	#endif

	#if TESTS_4
	{
		std::cout << std::endl << "TEST4 ----------------------------------------------" << std::endl;
		try
		{
			Intern	someIntern;
			Form	*form;

			form = someIntern.makeForm("RobotomyRequestForm", "Toto");
			std::cout << *form << std::endl;
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	#endif

	return 0;
}
