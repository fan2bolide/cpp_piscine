/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:44:18 by bajeanno          #+#    #+#             */
/*   Updated: 2024/03/13 16:49:45 by bajeanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string	target;
	PresidentialPardonForm();
public:
	explicit PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();
	void execute(const Bureaucrat& executor);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
};

#endif