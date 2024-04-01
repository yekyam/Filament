#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

/*
 * all functions must return bool and must take no arguments
 * tester object - wrapper around vec of functions
 * register a test - aka add to the vec of functions a function
 * run all tests - aka run all functions in the vec and check for success (true)
 */

using TestSignature = std::function<bool()>;

class Tester
{
    private:
	std::vector<std::pair<std::string, TestSignature>> functions;
	std::string color_fail = "\033[31m";   // red
	std::string color_passed = "\033[32m"; // green
	std::string color_normal = "\033[0m";  // normal

    public:
	void add_test(const std::string &test_name, TestSignature test)
	{
		functions.push_back(std::make_pair(test_name, test));
	}

	bool run_all_tests()
	{
		std::cout << "\n===== Start of Tests =====\n";
		int num_test_passed = 0;
		for (auto it = functions.begin(); it != functions.end(); it++)
		{
			std::cout << "Result of test " << it->first << ": ";
			bool result = it->second();
			if (result)
			{
				std::cout << color_passed << "Passed" << color_normal << '\n';
				num_test_passed++;
			} else
			{
				std::cout << color_fail << "Failed:(" << color_normal << '\n';
			}
		}
		std::cout << "===== End of Tests =====\n\n";
		std::cout << "Passed " << num_test_passed << " out of " << functions.size() << " tests.\n";
		return num_test_passed == functions.size();
	}
};