#ifndef DATAVALIDATION_H
#define DATAVALIDATION_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

enum class symbol_names {
    At,
    Hyphen,
    Unerscore,
    Dot,
    Zero,
    Nine,
    A,
    Z,
    a,
    z,
    Slash,
};

const unsigned max_email_length = 320;

bool is_valid_email(const std::string&);
bool is_valid_phone_number(const std::string&);
bool check_email_prefix(const std::string&);
bool check_email_domain(const std::string&);
bool is_letter(const char);
bool is_number(const char);
bool is_dot_or_dash(const char);
bool is_valid_character(const char);

#endif // DATAVALIDATION_H
