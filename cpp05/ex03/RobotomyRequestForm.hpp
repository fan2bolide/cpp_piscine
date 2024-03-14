/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:44:01 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:44:02 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
	std::string	target;
	RobotomyRequestForm();
public:
	explicit RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	void execute(const Bureaucrat& executor);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
};

#endif
