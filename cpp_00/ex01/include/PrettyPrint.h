/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrettyPrint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:29:16 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 12:04:42 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRETTY_PRINT_H
# define PRETTY_PRINT_H

// Colors and messages
#define PROMPT  "\033[94m>\033[0m "
#define ENTER_COMMAND "Enter command: "
#define HELLO "\n☎️ \033[94mWelcome to the PhoneBook!\033[0m\n"
#define BYE "☎️ \033[94mBye!\033[0m"
#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"
#define ADDING "Adding a new contact..."
#define WARNING "\033[91mField cannot be empty!\033[0m"
#define INVALID_INDEX "\033[91mInvalid index!\033[0m"
#define INVALID_INPUT "\033[91mInvalid input! Please enter a valid number.\033[0m"
#define NAME "First Name: "
#define LASTNAME "Last Name: "
#define NICKNAME "Nickname: "
#define PHONE "Phone Number: "
#define SECRET "Darkest Secret: "
#define SEARCHING "Enter index: "
#define SUCCESS "\033[92mSuccess!\033[0m"
#define HELP "Available commands:\n  ADD — Create a new contact entry\n  SEARCH — Find an existing contact\n  EXIT — Close the application\n"
#define ROW "+----------+----------+----------+----------+"

#endif