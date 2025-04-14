

#include <iostream>
#include <windows.h>
#include <string>
// #include <conio.h> // Include if you need getch() within this function, otherwise handle input outside.

// If you need to display game data, you might need the Game struct definition.
// If not, you can remove the commented parameter and related code.
// #include "./player.h" // Assuming Game struct is defined here or elsewhere

using namespace std;

// Helper function to draw content within the border (optional)
// void drawEndGameContent(HANDLE hConsole, int width, int height, const Game& gameSaved)
void drawEndGameContent(HANDLE hConsole, int width, int height)
{
    // --- End Example     // --- Example Content ---
    string msg1 = "Parabéns você venceu!";
    // string scoreMsg = "Final Score: " + to_string(gameSaved.points); // Example using Game data
    string msg2 = "Press any key to continue...";

    // Center the text (simple calculation)
    COORD pos1 = {(SHORT)((width - msg1.length()) / 2), (SHORT)(height / 2 - 1)};
    // COORD scorePos = {(SHORT)((width - scoreMsg.length()) / 2), (SHORT)(height / 2)};
    COORD pos2 = {(SHORT)((width - msg2.length()) / 2), (SHORT)(height / 2 + 1)};

    // Ensure positions are valid
    if (pos1.X < 0) pos1.X = 0;
    if (pos1.Y < 0) pos1.Y = 0;
    // if (scorePos.X < 0) scorePos.X = 0;
    // if (scorePos.Y < 0) scorePos.Y = 0;
    if (pos2.X < 0) pos2.X = 0;
    if (pos2.Y < 0) pos2.Y = 0;


    SetConsoleCursorPosition(hConsole, pos1);
    cout << msg1;

    // SetConsoleCursorPosition(hConsole, scorePos);
    // cout << scoreMsg;

    SetConsoleCursorPosition(hConsole, pos2);
    cout << msg2;
    // --- End Example
    


    // Hide cursor until input is needed (optional aesthetic)
    // CONSOLE_CURSOR_INFO cursorInfo;
    // GetConsoleCursorInfo(hConsole, &cursorInfo);
    // cursorInfo.bVisible = false; //hide the cursor
    // SetConsoleCursorInfo(hConsole, &cursorInfo);
}


// Main function to print the end game screen with a border
// void printEndGamre(const Game& gameSaved) // Pass game data if needed
void printEndGame()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // Store original console code pages
    UINT oldOutputCP = GetConsoleOutputCP();
    UINT oldInputCP = GetConsoleCP();

    // Set console code page to UTF-8 to support box drawing characters
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); // Also set input CP if needed, though less critical here

    system("cls"); // Clear the screen first

    // Get console screen buffer info to determine dimensions
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        cerr << "Error getting console screen buffer info." << endl;
        // Restore original code pages on error
        SetConsoleOutputCP(oldOutputCP);
        SetConsoleCP(oldInputCP);
        return;
    }

    // Use the dimensions of the VISIBLE window, not the whole buffer
    // srWindow defines the rectangle of the currently visible console window
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // +1 because indices are 0-based

    // Basic check for minimum size to draw a border
    if (width <= 2 || height <= 2) {
         cerr << "Console window too small to draw border." << endl;
         SetConsoleOutputCP(oldOutputCP);
         SetConsoleCP(oldInputCP);
         return;
    }

    // --- Direct Drawing of the Border ---

    // Draw top border (excluding corners)
    SetConsoleCursorPosition(hConsole, {1, 0}); // Start after corner
    for (short i = 1; i < width - 1; ++i) {
        cout << "\u2550"; // Double horizontal line (═)
    }

    // Draw bottom border (excluding corners)
    SetConsoleCursorPosition(hConsole, {1, (short)(height - 1)}); // Start after corner
    for (short i = 1; i < width - 1; ++i) {
        cout << "\u2550"; // Double horizontal line (═)
    }

    // Draw left border (excluding corners)
    for (short j = 1; j < height - 1; ++j) {
        SetConsoleCursorPosition(hConsole, {0, j});
        cout << "\u2551"; // Double vertical line (║)
    }

    // Draw right border (excluding corners)
    for (short j = 1; j < height - 1; ++j) {
        SetConsoleCursorPosition(hConsole, {(short)(width - 1), j});
        cout << "\u2551"; // Double vertical line (║)
    }

    // Draw corners using box drawing characters
    SetConsoleCursorPosition(hConsole, {0, 0});                           cout << "\u2554"; // Top-left (╔)
    SetConsoleCursorPosition(hConsole, {(short)(width - 1), 0});          cout << "\u2557"; // Top-right (╗)
    SetConsoleCursorPosition(hConsole, {0, (short)(height - 1)});         cout << "\u255A"; // Bottom-left (╚)
    SetConsoleCursorPosition(hConsole, {(short)(width - 1), (short)(height - 1)}); cout << "\u255D"; // Bottom-right (╝)

    // --- End Border Drawing ---


    // Draw the content inside the border
    // drawEndGameContent(hConsole, width, height, gameSaved); // Pass game data if needed
    drawEndGameContent(hConsole, width, height);


    // Restore original console code pages (important!)
    SetConsoleOutputCP(oldOutputCP);
    SetConsoleCP(oldInputCP);

    // The original code had getch() in the player loop after calling printEndGamre.
    // It's generally better to handle input waiting outside this display function.
    // If you absolutely need it here, uncomment the include and the line below:
    getch();
}

