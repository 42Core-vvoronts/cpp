/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:52:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/09 18:05:32 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void separator(const std::string &title) {
	std::cout << "\n=== " << title << " ===\n" << std::endl;
}

int main() {
	separator("Test 1: Form construction with valid grades");
	try {
		Form f1("Tax Form", 50, 25);
		std::cout << f1 << std::endl;
		Form f2("Budget Request", 1, 150);
		std::cout << f2 << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("Test 2: Form construction with grade too high");
	try {
		Form f3("Invalid Form", 0, 50);
		std::cout << f3 << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("Test 3: Form construction with grade too low");
	try {
		Form f4("Invalid Form", 50, 151);
		std::cout << f4 << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("Test 4: Bureaucrat successfully signs form");
	try {
		Form form1("Contract", 100, 50);
		Bureaucrat alice("Alice", 50);
		std::cout << form1 << std::endl;
		std::cout << alice << std::endl;
		alice.signForm(form1);
		std::cout << form1 << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("Test 5: Bureaucrat fails to sign (grade too low)");
	try {
		Form form2("Top Secret Document", 10, 5);
		Bureaucrat bob("Bob", 50);
		std::cout << form2 << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(form2);
		std::cout << form2 << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("Test 6: High-ranking bureaucrat signs difficult form");
	try {
		Form form3("Presidential Order", 1, 1);
		Bureaucrat president("President", 1);
		std::cout << form3 << std::endl;
		std::cout << president << std::endl;
		president.signForm(form3);
		std::cout << form3 << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("Test 7: Multiple bureaucrats, multiple forms");
	try {
		Form formA("Permit A", 75, 50);
		Form formB("Permit B", 120, 100);
		Bureaucrat charlie("Charlie", 70);
		Bureaucrat david("David", 130);
		
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
		std::cout << charlie << std::endl;
		std::cout << david << std::endl;
		
		charlie.signForm(formA);
		charlie.signForm(formB);
		david.signForm(formA);
		david.signForm(formB);
		
		std::cout << "\nFinal form states:" << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("Test 8: Form copy constructor and assignment");
	try {
		Form original("Original", 60, 30);
		Bureaucrat eve("Eve", 50);
		eve.signForm(original);
		
		Form copy1(original);
		Form copy2 = original;
		
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy 1:   " << copy1 << std::endl;
		std::cout << "Copy 2:   " << copy2 << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("Test 9: Edge case - grade boundaries");
	try {
		Form highestForm("Highest Grade Form", 1, 1);
		Form lowestForm("Lowest Grade Form", 150, 150);
		Bureaucrat topBoss("Top Boss", 1);
		Bureaucrat lowEmployee("Low Employee", 150);
		
		topBoss.signForm(highestForm);
		topBoss.signForm(lowestForm);
		lowEmployee.signForm(lowestForm);
		lowEmployee.signForm(highestForm);
		
		std::cout << highestForm << std::endl;
		std::cout << lowestForm << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	separator("All tests completed");
	return 0;
}

