/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:42:35 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 16:02:29 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define TESTS_1 1
#define TESTS_2 1
#define TESTS_3 1
#define TESTS_4 1
#define TESTS_5 1

int main( void )
{
	#if TESTS_1
	{
		std::cout << "TEST1 ----------------------------------------------" << std::endl;
		try
		{
			Bureaucrat	b1("Cito", 5);
			Form		*form = new ShrubberyCreationForm("Target1");
			RobotomyRequestForm	rrf("Blitzcrank");
			PresidentialPardonForm	ppf("J.Assange");

			std::cout << "No Exception should be thrown" << std::endl;
			std::cout << *form << std::endl;
			std::cout << std::endl;
			std::cout << rrf << std::endl;
			std::cout << std::endl;
			std::cout << ppf << std::endl;
			std::cout << std::endl;
			b1.signForm(*form);
			form->beSigned(b1);
			form->execute(b1);
			std::cout << std::endl;
			b1.signForm(rrf);
			rrf.beSigned(b1);
			rrf.execute(b1);
			std::cout << std::endl;
			b1.signForm(ppf);
			ppf.beSigned(b1);
			ppf.execute(b1);
			std::cout << std::endl;
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
			Bureaucrat				b2("Bernhard", 147);
			PresidentialPardonForm	ppf("Target2");

			std::cout << "Should throw Bureaucrat::GradeTooLowException: " << std::endl;
			std::cout << ppf << std::endl;
			b2.signForm(ppf);
			ppf.beSigned(b2);
			ppf.execute(b2);
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
			Bureaucrat				b2("Bernhard", 147);
			PresidentialPardonForm	ppf("Target2");

			std::cout << "Should throw Form::GradeTooLowException, no execution of ppf.execute(b2)" << std::endl;
			std::cout << ppf << std::endl;
			ppf.beSigned(b2);
			ppf.execute(b2);
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
			Bureaucrat				b1("Lead", 3);
			Bureaucrat				b2("Bernhard", 147);
			PresidentialPardonForm	ppf("Target2");

			std::cout << "Should throw Form::GradeTooLowException" << std::endl;
			std::cout << ppf << std::endl;
			b1.signForm(ppf);
			ppf.beSigned(b1);
			ppf.execute(b2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	#endif

	#if TESTS_5
	{
		std::cout << std::endl << "TEST5 ----------------------------------------------" << std::endl;
		try
		{
			Bureaucrat				b1("Lead", 3);
			RobotomyRequestForm		rrf("Target2");

			std::cout << "Should throw Form::UnsignedException" << std::endl;
			std::cout << rrf << std::endl;
			rrf.execute(b1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	#endif

	return 0;
}