/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:10:09 by areheman          #+#    #+#             */
/*   Updated: 2023/01/05 16:38:42 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main(void)
{
	try
	{
		Bureaucrat tom("tom", 2);
		Bureaucrat sam("sam", 151);
		std::cout<<tom<<std::endl;
		std::cout<<sam<<std::endl;
		tom.increaseGrade();
		std::cout<<tom<<std::endl;
	//	tom.increaseGrade();
		sam.decreaseGrade();
		std::cout<<sam<<std::endl;
		sam.decreaseGrade();
		std::cout<<sam<<std::endl;
		
	}
	catch(const Bureaucrat::GradeTooHighExecption& e)
	{
		std::cout << e.what() <<std::endl;
	}
	catch(const Bureaucrat::GradeTooLowExecption& e)
	{
		std::cout << e.what() <<std::endl;
	}
		
}