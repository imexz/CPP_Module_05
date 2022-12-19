/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:40:30 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 01:54:14 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

		const std::string	_name;
		bool				_signed;
		const unsigned int	_gradeReq;
		const unsigned int	_gradeExe;

	public:

		Form(void);
		Form(const std::string name, const unsigned int gradeReq, const unsigned int gradeExe);
		Form(Form const &src);
		~Form(void);

		Form	&operator=(Form const &src);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		unsigned int		getGradeReq(void) const;
		unsigned int		getGradeExe(void) const;

		void				beSigned(Bureaucrat const &signee);

		class GradeTooHighException : public std::exception {

			virtual const char	*what() const throw() {
				return ("Form::GradeTooHighException thrown");
			};
		} GradeTooHighExcep;
		class GradeTooLowException : public std::exception {

			virtual const char	*what() const throw() {
				return ("Form::GradeTooLowException thrown");
			};
		} GradeTooLowExcep;

};

std::ostream	&operator<<(std::ostream &o, Form const &src);

#endif
