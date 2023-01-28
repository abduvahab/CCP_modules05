/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:22:32 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 12:02:52 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.h"

class Bureaucrat;

class AForm
{
	private:
		std::string  const name;
		bool				_signed;
		int const			grade_to_sign;
		int const			grade_to_exe;
		AForm();
	protected:
		AForm(std::string const name, int const grade_to_sign, int const grade_to_exe, bool _signed);
		
	public:
		AForm(std::string const name, int const grade_to_sign, int const grade_to_exe);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();
		std::string getName() const;
		int			getGrade_to_sign() const;
		int			getGrade_to_exe() const;
		bool			isSigned() const;
	
		void	beSigned(const Bureaucrat& obj);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException: public std::exception
	{
		public:
			const char* what() const throw(){return "Grade Too Heigh";}
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char* what() const throw(){return "Grade Too Low";}
	};
	class isNotSigned: public std::exception
	{
		public:
			const char* what() const throw(){return "is not Sigend";}
	};
};

std::ostream& operator<<(std::ostream& o, const AForm& obj);

#endif