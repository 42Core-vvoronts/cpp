/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:29:16 by vvoronts          #+#    #+#             */
/*   Updated: 2025/08/18 10:53:22 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <limits>

#define MAX_CONTACTS 8
// Text
#define PROMPT  "\033[94m>\033[0m "
#define ENTER_COMMAND "Enter command: "
#define HELLO "☎️ \033[94mWelcome to the PhoneBook!\033[0m\n"
#define BYE "\n☎️ \033[94mBye!\033[0m"
#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"
#define ADDING "Adding a new contact..."
#define NAME "Name: "
#define LASTNAME "Last Name: "
#define NICKNAME "Nickname: "
#define PHONE "Phone Number: "
#define SECRET "Secret: "
#define SEARCHING "Searching for contacts..."
#define SUCCESS "Success!"
#define HELP "Available commands:\n  ADD — Create a new contact entry\n  SEARCH — Find an existing contact\n  EXIT — Close the application\n"

#endif