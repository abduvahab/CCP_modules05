/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:27:21 by areheman          #+#    #+#             */
/*   Updated: 2023/01/08 14:46:14 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(std::string target):\
		AForm("PresidentialPardonForm", 25, 5),target(target)
{
	std::cout<<"PresidentialPardonForm constructor"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)\
		:AForm(obj.getName(), obj.getGrade_to_sign(), \
		obj.getGrade_to_exe(), obj.isSigned()),target(obj.target)
{
	std::cout<<"PresidentialPardonForm copy constructor"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	std::cout<<"PresidentialPardonForm copy assignement constructor"<<std::endl;
	if (this == &obj)
		return *this;
	target = obj.target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw isNotSigned();

	if (executor.getGrade() > this->getGrade_to_exe())
		throw GradeTooLowException();
	std::cout<<this->target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm destructor"<<std::endl;
}