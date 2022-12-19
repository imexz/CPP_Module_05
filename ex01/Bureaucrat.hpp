/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:42:30 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 01:54:21 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:

		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat			&operator=(Bureaucrat const &src);

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		void				increment(void);
		void				decrement(void);
		void				signForm(Form &form);

		class GradeTooHighException : public std::exception {

			virtual const char	*what() const throw() {
				return ("Bureaucrat::GradeTooHighException thrown");
			};
		} GradeTooHighExcep;
		class GradeTooLowException : public std::exception {

			virtual const char	*what() const throw() {
				return ("Bureaucrat::GradeTooLowException thrown");
			};
		} GradeTooLowExcep;

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &src);

#endif
