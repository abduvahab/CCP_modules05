/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:25:10 by areheman          #+#    #+#             */
/*   Updated: 2023/01/08 17:01:22 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"


RobotomyRequestForm::RobotomyRequestForm(std::string target):\
		AForm("RobotomyRequestForm", 72, 45),target(target)
{
	std::cout<<"RobotomyRequestForm constructor"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)\
		:AForm(obj.getName(), obj.getGrade_to_sign(), \
		obj.getGrade_to_exe(), obj.isSigned()),target(obj.target)
{
	std::cout<<"RobotomyRequestForm copy constructor"<<std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	std::cout<<"RobotomyRequestForm copy assignement constructor"<<std::endl;
	if (this == &obj)
		return *this;
	target = obj.target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw isNotSigned();

	if (executor.getGrade() > this->getGrade_to_exe())
		throw GradeTooLowException();
	std::cout<<this->target<<" has been robotomized successfully 50% of the time"<<std::endl;	

}
void    RobotomyRequestForm::setTarget(std::string target)
{
    this->target = target;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm destructor"<<std::endl;
}