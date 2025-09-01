/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:29:16 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 19:47:01 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <iostream>
#include <string>
#include <sstream> //to convert int to string
#include <stdlib.h>
#include <cctype>
#include <limits>
#include <vector>
#include <iomanip>

class Contact;

#define WIDTH 10
#define ROW "+----------+----------+----------+----------+"
// Colors and messages
#define PROMPT  "\033[94m>\033[0m "
#define ENTER_COMMAND "Enter command: "
#define HELLO "☎️ \033[94mWelcome to the PhoneBook!\033[0m\n"
#define BYE "\n☎️ \033[94mBye!\033[0m"
#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"
#define ADDING "Adding a new contact..."
#define WARNING "\033[91mField cannot be empty!\033[0m"
#define NAME "Name: "
#define LASTNAME "Last Name: "
#define NICKNAME "Nickname: "
#define PHONE "Phone Number: "
#define SECRET "Darkest Secret: "
#define SEARCHING "Enter index: "
#define SUCCESS "Success!"
#define HELP "Available commands:\n  ADD — Create a new contact entry\n  SEARCH — Find an existing contact\n  EXIT — Close the application\n"

void align(std::string str, unsigned int width);
void printEmptyBook(void);
void printBook(Contact *contacts, int index);
void promptForDetails(std::vector<std::string>& userInput);
void setContactInfo(Contact& contact, std::vector<std::string>& userInput);




#endif