/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:24:59 by areheman          #+#    #+#             */
/*   Updated: 2023/01/06 16:01:57 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

int main(void)
{
	try
	{
		Bureaucrat tom("tom", 4);
		Form f1("form1",4,150);
		std::cout<<tom<<std::endl;
		std::cout<<f1;
		tom.signForm(f1);
		std::cout<<f1;
		Form f2(f1);
		std::cout<<f2;
		
	}
	catch(std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}