/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:14:11 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 12:08:11 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "iostream"
#include "string"
#include "exception"

class Bureaucrat
{
	private:
			std::string const 	name;
			int					grade;
			Bureaucrat();
	public:
			Bureaucrat(std::string const name, int grade);
			Bureaucrat(const Bureaucrat& obj);
			~Bureaucrat();
//			std::string GradeTooHighExecption() const;
//			std::string GradeTooLowExecption() const;
			Bureaucrat& operator=(const Bureaucrat& obj);

			std::string	getName() const;
			int			getGrade()const;
			void		increaseGrade();
			void		decreaseGrade();
			
	class GradeTooHighExecption:public std::exception
	{
		public:
			const char* what() const throw(){return "Grade Too High";}
	};
	class GradeTooLowExecption:public std::exception
	{
		public:
			const char* what() const throw(){return "Grade Too Low";}
	};
};

std::ostream& operator<<(std::ostream& ou, const Bureaucrat& o);

#endif