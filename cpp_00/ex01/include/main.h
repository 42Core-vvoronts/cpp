/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:29:16 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 20:35:57 by vvoronts         ###   ########.fr       */
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
#include "PrettyPrint.h"

class Contact;

#define WIDTH 10

void align(std::string str, unsigned int width);
void printEmptyBook(void);
void printBook(Contact *contacts, int index);
void promptForDetails(std::vector<std::string>& userInput);
void setContactInfo(Contact& contact, std::vector<std::string>& userInput);




#endif