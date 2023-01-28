/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:39:55 by areheman          #+#    #+#             */
/*   Updated: 2023/01/08 14:42:32 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):\
		AForm("ShrubberyCreationForm", 145, 137),target(target)
{
	std::cout<<"ShrubberyCreationForm constructor"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)\
		:AForm(obj.getName(), obj.getGrade_to_sign(), \
		obj.getGrade_to_exe(), obj.isSigned()),target(obj.target)
{
	std::cout<<"ShrubberyCreationForm copy constructor"<<std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	std::cout<<"ShrubberyCreationForm copy assignement constructor"<<std::endl;
	if (this == &obj)
		return *this;
	target = obj.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
	std::cout<<"ShrubberyCreationForm destructor"<<std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw isNotSigned();

	if (executor.getGrade() > this->getGrade_to_exe())
		throw GradeTooLowException();
	std::ofstream of;
	of.open(this->getName() + "_shrubbery", std::fstream::out);
	of << "                      ___" << std::endl;
    of << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
    of << "             ,-'          __,,-- \\" << std::endl;
    of << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
    of << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
    of << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
    of << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    of << "     (     ,-'                  `." << std::endl;
    of << "      `._,'     _   _             ;" << std::endl;
    of << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    of << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
    of << "        `--\'   \"Hb  HH  dF\"" << std::endl;
    of << "                \"Hb HH dF" << std::endl;
    of << "                 \"HbHHdF" << std::endl;
    of << "                  |HHHF" << std::endl;
    of << "                  |HHH|" << std::endl;
    of << "                  |HHH|" << std::endl;
    of << "                  |HHH|" << std::endl;
    of << "                  |HHH|" << std::endl;
    of << "                  dHHHb" << std::endl;
    of << "                .dFd|bHb.               o" << std::endl;
    of << "      o       .dHFdH|HbTHb.          o /" << std::endl;
    of << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
    of << "##########################################" << std::endl;
	of.close();
}