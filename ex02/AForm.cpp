/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:37:29 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 11:57:02 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"
/*
AForm::AForm()
{
	std::cout<<"AForm default constructor"<<std::endl;
}
*/
AForm::AForm(std::string const name, \
		int const grade_to_sign, int const grade_to_exe)\
		:name(name), _signed(false)\
		, grade_to_sign(grade_to_sign)\
		, grade_to_exe(grade_to_exe)
{
	if (grade_to_exe < 1 || grade_to_exe < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_exe > 150 || grade_to_sign > 150)
		throw AForm::GradeTooLowException();
	std::cout<<"AForm constructor with arguments"<<std::endl;
}

AForm::AForm(std::string const name, \
		int const grade_to_sign, int const grade_to_exe, bool _signed)\
		:name(name), _signed(_signed)\
		, grade_to_sign(grade_to_sign)\
		, grade_to_exe(grade_to_exe)
{
	if (grade_to_exe < 1 || grade_to_exe < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_exe > 150 || grade_to_sign > 150)
		throw AForm::GradeTooLowException();
	std::cout<<"AForm constructor with arguments"<<std::endl;
}

AForm::AForm(const AForm& obj)\
		:name(obj.name), _signed(obj._signed)\
		, grade_to_sign(obj.grade_to_sign)\
		, grade_to_exe(obj.grade_to_exe)
{
	std::cout<<"AForm copy constructor"<<std::endl;	
}

AForm& AForm::operator=(const AForm& obj)
{
	std::cout<<"AForm copy assignement constructor"<<std::endl;	
	if (this == &obj)
		return *this;
	_signed = obj.isSigned();
	return *this;
}


AForm::~AForm()
{
	std::cout<<"AForm destructor"<<std::endl;
}

std::string AForm::getName() const
{
	return name;
}

int	AForm::getGrade_to_exe() const
{
	return grade_to_exe;
}

int	AForm::getGrade_to_sign() const
{
	return grade_to_sign;
}

bool	AForm::isSigned() const
{
	return _signed;
}

void	AForm::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() <= grade_to_sign)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o, const AForm& obj)
{
	o<<"AForm name : "<<obj.getName()<<std::endl;
	o<<"AForm is signed : "<<(obj.isSigned()?"yes":"no")<<std::endl;
	o<<"Grade requied to sign is : "<<obj.getGrade_to_sign()<<std::endl;
	o<<"Grade required to execute is : "<<obj.getGrade_to_exe()<<std::endl;
	
	return o;
}

