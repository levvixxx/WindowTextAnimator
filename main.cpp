#include <iostream>
#include <windows.h>

using namespace std;

HWND h = NULL;
string title = "";
string newTitle = "";

int searchAp(){
    cout << "Enter the title of the active application:";
    std::getline(std::cin, title);
    cout << "Enter a new name for the active application:";
    std::getline(std::cin, newTitle);
    h = FindWindowA(NULL,title.c_str());
    if(h == NULL){
        cout << "Application not found!";
        return 1;
    }
    if(newTitle == ""){
        cout << "NewTitle null!";
        return 1;
    }
    return 0;
}

int startTyping(){
    while (true)
    {
        string result = "";
        for(int i = 0;i<newTitle.length();i++){
            if(!IsWindow(h)){
                return 0;
            }
            result += {newTitle[i]};
            SetWindowTextA(h,result.c_str());
            Sleep(800);
        }
        Sleep(2000);
        result = "";
    }
}


int main(){
    while(true){
        if(searchAp() == 0){
            if(startTyping() == 0){
                return 0;
            }
            break;
        }
    }
    return 0;
}
