

#ifndef DEBUG_STRING_COLOR_HPP
#define DEBUG_STRING_COLOR_HPP

/// RESET
// These codes set the actual text to the specified color
#define RESET_TEXT  "\x1B[0m" // Set all colors back to normal.

/// FOREGROUND
// These codes set the actual text to the specified color
#define D_FG_DEFAULT        "\x1B[39m" // Default
#define D_FG_BLACK          "\x1B[30m" // Black
#define D_FG_RED            "\x1B[31m" // Red
#define D_FG_GREEN          "\x1B[32m" // Green
#define D_FG_YELLOW         "\x1B[33m" // Yellow
#define D_FG_BLUE           "\x1B[34m" // Blue
#define D_FG_MAGENTA        "\x1B[35m" // Magenta
#define D_FG_CYAN           "\x1B[36m" // Cyan
#define D_FG_LIGHT_GRAY     "\x1B[37m" // White
#define D_FG_DARK_GRAY      "\x1B[90m" // Black
#define D_FG_LIGHT_RED      "\x1B[91m" // Red
#define D_FG_LIGHT_GREEN    "\x1B[92m" // Green
#define D_FG_LIGHT_YELLOW   "\x1B[93m" // Yellow
#define D_FG_LIGHT_BLUE     "\x1B[94m" // Blue
#define D_FG_LIGHT_MAGENTA  "\x1B[95m" // Magenta
#define D_FG_LIGHT_CYAN     "\x1B[96m" // Cyan
#define D_FG_WHITE          "\x1B[97m" // White

/// BACKGROUND
// These codes set the background color behind the text.
#define D_BG_DEFAULT        "\x1B[49m" // Default
#define D_BG_BLACK          "\x1B[40m"
#define D_BG_RED            "\x1B[41m"
#define D_BG_GREEN          "\x1B[42m"
#define D_BG_YELLOW         "\x1B[43m"
#define D_BG_BLUE           "\x1B[44m"
#define D_BG_MAGENTA        "\x1B[45m"
#define D_BG_CYAN           "\x1B[46m"
#define D_BG_WHITE          "\x1B[47m"

// These will set the text color and then set it back to normal afterwards.
#define FG_BLACK(x)         D_FG_BLACK         x RESET_TEXT
#define FG_RED(x)           D_FG_RED           x RESET_TEXT
#define FG_GREEN(x)         D_FG_GREEN         x RESET_TEXT
#define FG_YELLOW(x)        D_FG_YELLOW        x RESET_TEXT
#define FG_BLUE(x)          D_FG_BLUE          x RESET_TEXT
#define FG_MAGENTA(x)       D_FG_MAGENTA       x RESET_TEXT
#define FG_CYAN(x)          D_FG_CYAN          x RESET_TEXT
#define FG_LIGHT_GRAY(x)    D_FG_LIGHT_GRAY    x RESET_TEXT
#define FG_DARK_GRAY(x)     D_FG_DARK_GRAY     x RESET_TEXT
#define FG_LIGHT_RED(x)     D_FG_LIGHT_RED     x RESET_TEXT
#define FG_LIGHT_GREEN(x)   D_FG_LIGHT_GREEN   x RESET_TEXT
#define FG_LIGHT_YELLOW(x)  D_FG_LIGHT_YELLOW  x RESET_TEXT
#define FG_LIGHT_BLUE(x)    D_FG_LIGHT_BLUE    x RESET_TEXT
#define FG_LIGHT_MAGENTA(x) D_FG_LIGHT_MAGENTA x RESET_TEXT
#define FG_LIGHT_CYAN(x)    D_FG_LIGHT_CYAN    x RESET_TEXT
#define FG_WHITE(x)         D_FG_WHITE         x RESET_TEXT

// Example usage: cout << FG_BLUE("This text's color is now blue!") << endl;

// These will set the text's background color then reset it back.
#define BG_BLACK(x)   D_BG_BLACK   x RESET_TEXT
#define BG_RED(x)     D_BG_RED     x RESET_TEXT
#define BG_GREEN(x)   D_BG_GREEN   x RESET_TEXT
#define BG_YELLOW(x)  D_BG_YELLOW  x RESET_TEXT
#define BG_BLUE(x)    D_BG_BLUE    x RESET_TEXT
#define BG_MAGENTA(x) D_BG_MAGENTA x RESET_TEXT
#define BG_CYAN(x)    D_BG_CYAN    x RESET_TEXT
#define BG_WHITE(x)   D_BG_WHITE   x RESET_TEXT

// Example usage: cout << BG_WHITE(FG_BLUE("I am blue text on a white background!")) << endl;

// These functions will set the background to the specified color indefinitely.
// NOTE: These do NOT call RESET_TEXT afterwards. Thus, they will set the background color indefinitely until the user executes cout << RESET_TEXT
// OR if a function is used that calles RESET_TEXT i.e. cout << FG_RED("Hello World!") will reset the background color since it calls RESET_TEXT.
// To set text COLOR indefinitely, see SetFore functions below.
#define SET_BG_BLACK   D_BG_BLACK
#define SET_BG_RED     D_BG_RED
#define SET_BG_GREEN   D_BG_GREEN
#define SET_BG_YELLOW  D_BG_YELLOW
#define SET_BG_BLUE    D_BG_BLUE
#define SET_BG_MAGENTA D_BG_MAGENTA
#define SET_BG_CYAN    D_BG_CYAN
#define SET_BG_WHITE   D_BG_WHITE

// Example usage: cout << SET_BG_RED << "This text's background and all text after it will be red until RESET_TEXT is called in some way" << endl;

// These functions will set the text color until RESET_TEXT is called. (See above comments)
#define SET_FG_BLACK         D_FG_BLACK
#define SET_FG_RED           D_FG_RED
#define SET_FG_GREEN         D_FG_GREEN
#define SET_FG_YELLOW        D_FG_YELLOW
#define SET_FG_BLUE          D_FG_BLUE
#define SET_FG_MAGENTA       D_FG_MAGENTA
#define SET_FG_CYAN          D_FG_CYAN
#define SET_FG_LIGHT_GRAY    D_FG_LIGHT_GRAY
#define SET_FG_DARK_GRAY     D_FG_DARK_GRAY
#define SET_FG_LIGHT_RED     D_FG_LIGHT_RED
#define SET_FG_LIGHT_GREEN   D_FG_LIGHT_GREEN
#define SET_FG_LIGHT_YELLOW  D_FG_LIGHT_YELLOW
#define SET_FG_LIGHT_BLUE    D_FG_LIGHT_BLUE
#define SET_FG_LIGHT_MAGENTA D_FG_LIGHT_MAGENTA
#define SET_FG_LIGHT_CYAN    D_FG_LIGHT_CYAN
#define SET_FG_WHITE         D_FG_WHITE

// Example usage: cout << SET_FG_RED << "This text and all text after it will be red until RESET_TEXT is called in some way" << endl;

#define BOLD(x)      "\x1B[1m" x RESET_TEXT // Embolden text then reset it.
#define BRIGHT(x)    "\x1B[1m" x RESET_TEXT // Brighten text then reset it. (Same as bold but is available for program clarity)
#define UNDERLINE(x) "\x1B[4m" x RESET_TEXT // Underline text then reset it.

// Example usage: cout << BOLD(FG_BLUE("I am bold blue text!")) << endl;

// These functions will embolden or underline text indefinitely until RESET_TEXT is called in some way.

#define SET_BOLD      "\x1B[1m" // Embolden text indefinitely.
#define SET_BRIGHT    "\x1B[1m" // Brighten text indefinitely. (Same as bold but is available for program clarity)
#define SET_UNDERLINE "\x1B[4m" // Underline text indefinitely.

// Example usage: cout << SET_BOLD << "I and all text after me will be BOLD/Bright until RESET_TEXT is called in some way!" << endl;

#endif /* DEBUG_STRING_COLOR_HPP */
