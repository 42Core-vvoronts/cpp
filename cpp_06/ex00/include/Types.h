/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 09:21:47 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/25 09:32:18 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include <string>

typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO
} t_type;

double parseToDouble(const std::string& literal, char** flag);
t_type detectType(double& literal);
bool isPseudo(double& base);
const char* verifyInput(const std::string& literal, char* flag);
bool isOverflow(const double& base, t_type type);
bool isValidChar(char c);
//
void convertChar(const double& base);
void convertInt(const double& base);
void convertFloat(const double& base);
void convertDouble(const double& base);
//
void displayPseudo(double& base);

#endif