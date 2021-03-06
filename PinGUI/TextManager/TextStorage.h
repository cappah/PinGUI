#ifndef TEXTSTORAGE_H
#define TEXTSTORAGE_H

/**

    PinGUI

    Copyright (c) 2017 Lubomir Barantal <l.pinsius@gmail.com>

    This software is provided 'as-is', without any express or implied
    warranty. In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.

**/

#include "../TextManager/TextManager.h"
#include "../stuff.h"

class additionalStorage{

    public:
        clipboard_type* type;

        additionalStorage()
        {
        };
        additionalStorage(clipboard_type* Type):
            type(Type)
        {

        };
        ~additionalStorage()
        {
        };
};

class TextStorage
{
    private:
        //It is holding pointers to texts and also a pointer to the textmanager
        std::vector<std::shared_ptr<Text>> _TEXTS;

        std::shared_ptr<TextManager> _texter;

        //Pointer to an additional informations - in case of clipboards, etc.
        std::shared_ptr<additionalStorage> _additionalStorage;

        /**
            Private methods
        **/
        void handleIntegerInput(char*& ch, int& position, PinGUI::writingModInfo& info);

        void handleFloatInput(char*& ch, int& position, PinGUI::writingModInfo& info);

        bool checkNegativeInput(char*& ch, int& position);

        bool isFloatInput(char*& ch);

        bool isNegativeInput(char*& ch);

    public:
        TextStorage(std::shared_ptr<TextManager> text);
        ~TextStorage();

        void addText(const std::string& text, GUIPos x, GUIPos y) ;

        void addText(GUIPos x, GUIPos y, int* var);

        void addText(GUIPos x, GUIPos y, float* var);

        void addText(GUIPos x, GUIPos y, std::string* var);

		void addAdjustableText(const std::string& text, GUIPos x, GUIPos y, unsigned int size, unsigned int maxSize);

        void destroyText(int position = 0);

		void destroyStorage();

        void addChar(char* ch, int position, PinGUI::writingModInfo& info);

        void removeChar(int position);

        std::shared_ptr<Text> getText(int position = 0);

        std::vector<std::shared_ptr<Text>>* getVector();

        std::shared_ptr<TextManager> getTextManager();

        void setAdditionalInfo(clipboard_type* Type);

        void setShow(bool state);
};

#endif // TEXTSTORAGE_H
