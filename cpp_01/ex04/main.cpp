/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:35:26 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/04 10:52:37 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/**
 * @param olds Old substring to be replaced
 * @param news New substring to replace with
 * @param origs The original string
 *
 * @return A result string with all occurrences of olds replaced by news
 *
 * @brief Replaces all occurrences of olds in origs with news
 */
std::string replaceString(const std::string& olds, const std::string& news, const std::string& origs) 
{
	std::string result;
	size_t position = 0;
	size_t start = 0;

	while ((position = origs.find(olds, start)) != std::string::npos) {
		result.append(origs, start, position - start);
		result += news;
		start = position + olds.length();
	}
	result.append(origs, start, origs.length() - start);
	return result;
}

/**
 * @param ifs Input file stream
 * @param ofs Output file stream
 * @param s1 String to search for
 * @param s2 String to replace with
 *
 * @brief Copies content from ifs to ofs, replacing every occurrence of s1 with s2
 *
 * Line-by-line to keep memory low
 */
void copyReplace(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2)
{
	std::string		line;
	
	while (getline(ifs, line))
	{
		ofs << replaceString(s1, s2, line) << std::endl;
	}
}

/**
 * @param argc Argument count
 * @param argv Argument vector
 *
 * @return 1 if arguments are invalid, 0 otherwise
 *
 * @brief Validates program input
 *
 * Usage: <filename> <s1> <s2> and <s1> cannot be empty
 */
int isInvalidArguments(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error! Usage: <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cout << "Error! <s1> cannot be empty." << std::endl;
		return (1);
	}
	return (0);
}

/**
 * @param argc Argument count
 * @param argv Argument vector
 *
 * @brief Input: <filename> <s1> <s2>
 *
 * Opens the file <filename> and copy its content into a new file
 * <filename>.replace, replacing every occurrence of s1 with s2.
 *
 * @example ./mysed file.txt a XXX
 */
int main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		file_original;
	std::string		file_replace;
	std::string		s1;
	std::string		s2;

	if (isInvalidArguments(argc, argv))
		return (1);
	
	file_original =  argv[1];
	file_replace = file_original + ".replace";
	s1 = argv[2];
	s2 = argv[3];

	// Open original file for reading
	infile.open(file_original.c_str());
	if (!infile) 
	{
		std::cout << "Error! Could not open the input file" << std::endl;
		return (1);
	}
	// Open new file for writing
	outfile.open(file_replace.c_str());
	if (!outfile.is_open()) {
		std::cout << "Error! Could not create the output file" << std::endl;
		return (1);
	}

	copyReplace(infile, outfile, s1, s2);

	// Close both files
	infile.close();
	outfile.close();
	return (0);
}
