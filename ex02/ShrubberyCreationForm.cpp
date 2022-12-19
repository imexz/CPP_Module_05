/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:01:59 by mstrantz          #+#    #+#             */
/*   Updated: 2022/02/03 04:33:21 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
				Form("ShrubberyCreationForm", 145, 137, "unknown") {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
				Form(src) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
				Form("ShrubberyCreationForm", 145, 137, target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {

	(void) src;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

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
			std::ofstream	ofs;
			ofs.exceptions(std::ofstream::failbit | std::ofstream::badbit);
			try {
				ofs.open(getTarget().append("_shrubbery"), std::ofstream::out | std::ofstream::trunc);
				ofs \
					<<	"						 .                          \n"
					<<	"	                     M                          \n"
					<<	"	                    dM                          \n"
					<<	"	                    MMr                         \n"
					<<	"	                   AMMML                  .     \n"
					<<	"	                   MMMMM.                xf     \n"
					<<	"	   .              ;MMMMM               .MM-     \n"
					<<	"	    Mh..          +MMMMMM            .MMMM      \n"
					<<	"	    .MMM.         .MMMMML.          MMMMMh      \n"
					<<	"	     )MMMh.        MMMMMM         MMMMMMM       \n"
					<<	"	      mMMMMx.     .MMMMMMf      xnMMMMMM.       \n"
					<<	"	      .*MMMMM      MMMMMM.     nMMMMMMP.        \n"
					<<	"	        *MMMMMx    .MMMMM)    .MMMMMMM=         \n"
					<<	"	         *MMMMMh   .MMMMM.   JMMMMMMP           \n"
					<<	"	           MMMMMM   MMMM.  dMMMMMM             .\n"
					<<	"	            MMMMMM  .MMMM  .MMMMM(        .nnMP.\n"
					<<	"	=..          *MMMMx  MMM.  dMMMM.    .nnMMMMM*  \n"
					<<	"	  .MMn...     .MMMMr .MM   MMM.   .nMMMMMMM*.   \n"
					<<	"	   .mMMMMnn..   *MMM  MM  MMP.  .dMMMMMMM.      \n"
					<<	"	     ^MMMMMMMMx.  *ML .M .M*  .MMMMMM**.        \n"
					<<	"	        *PMMMMMMhn. *x > M  .MMMM**.            \n"
					<<	"	           .**MMMMhx/.h/ .=*.                   \n"
					<<	"	                    .3P.%....                   \n"
					<<	"	                  nP.     .*MMnx .;";
				ofs.close();
			}
			catch (std::ofstream::failure e) {
			std::cerr << "Exception opening/reading/closing outfile" << std::endl;
			break;
		}
	}
}