#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// Unfortunately I have to credit chatgpt with this one. 
// The only thing I did was change datatypes for my needs. 

char* returnClipboard() {
    char* text;
    if (OpenClipboard(NULL)) {
        HANDLE hData = GetClipboardData(CF_TEXT);
        if (hData != NULL) {
            char* clipboardText = (char*)GlobalLock(hData);
            if (clipboardText != NULL) {
                text = clipboardText;
                GlobalUnlock(hData);
            }
        }
        CloseClipboard();
    }
    return text;
}

int main() {
    // printf("%s", returnClipboard());
    char command[50] = "yt-dlp ";
    strcat(command, returnClipboard());
    printf("%s", command);
    // system(command);
    // printf("%s", returnClipboard());

    return 0;
}