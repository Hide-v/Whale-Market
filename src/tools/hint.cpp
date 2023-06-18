#include "../../include/tools/hint.h"
#include "../../include/tools/color.h"
#include <iostream>

static const std::string  BANNER = "\
\t__          ___           _          __  __            _        _       _\n\
\t\\ \\        / / |         | |        |  \\/  |          | |      | |     | |\n\
\t \\ \\  /\\  / /| |__   __ _| | ___    | \\  / | __ _ _ __| | _____| |_    | |\n\
\t  \\ \\/  \\/ / | '_ \\ / _` | |/ _ \\   | |\\/| |/ _` | '__| |/ / _ \\ __|   | |\n\
\t   \\  /\\  /  | | | | (_| | |  __/   | |  | | (_| | |  |   <  __/ |_    |_|\n\
\t    \\/  \\/   |_| |_|\\__,_|_|\\___|   |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|   (_)\n\
";

static const std::string SUCCESS = "\t\t*** Operation Successful! ***";
static const std::string FAILURE = "\t\t*** Operation Failed! ***";
static const std::string ILLEGAL = "\t\t*** Illegal Input! ***";
static const std::string LOADING = "\t\t*** Loading ... ***";
static const std::string EXITING = "\t\t*** Exiting ... ***";

static const std::string INVALID = "\
\t  _____                           _   _       _   _\n\
\t |_   _|                         | | (_)     | | | |\n\
\t   | |    _ __   __   __   __ _  | |  _    __| | | |\n\
\t   | |   | '_ \\  \\ \\ / /  / _` | | | | |  / _` | | |\n\
\t  _| |_  | | | |  \\ V /  | (_| | | | | | | (_| | |_|\n\
\t |_____| |_| |_|   \\_/    \\__,_| |_| |_|  \\__,_| (_)\n\
";

void welcomeMessage()
{
    std::cout << "\n" << BOLD << FRONT_RED << "Welcome to" << RESET << '\n';
    std::cout << BOLD << FRONT_BLUE << BANNER << RESET << '\n';
    std::cout << FRONT_BLUE << "This is WinterCode Project for C-Beginners" << RESET << '\n' << '\n';
}

void successMessage() { std::cout << FRONT_GREEN << SUCCESS << RESET << '\n' << '\n'; }
void failureMessage() { std::cout << FRONT_RED << FAILURE << RESET << '\n' << '\n'; }
void illegalMessage() { std::cout << FRONT_RED << ILLEGAL << RESET << '\n' << '\n'; }
void loadingMessage() { std::cout << FRONT_BLUE << LOADING << RESET << '\n' << '\n'; }
void exitingMessage() { std::cout << FRONT_RED << EXITING << RESET << '\n' << '\n'; }

void invalidMessage() { 
    std::cout << '\n' << FRONT_RED << INVALID << RESET << '\n' << '\n';
    std::cout << '\n' << FRONT_RED << BOLD << "This Function is Waiting For you to Implement ..." << \
        RESET << '\n' << '\n';   

}