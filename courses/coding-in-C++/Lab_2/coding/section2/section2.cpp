#include <iostream>

class Note{
private:
std::string* text;
public:
Note(std::string par_text);
Note(const Note &par_note);
~Note();
bool display();
};
/**
 * @brief Construct a new Note:: Note object
 * 
 * @param par_text 
 */
Note::Note(std::string par_text){
text = new std::string;
*text = par_text;
};
/**
 * @brief Copie-Construct a new Note:: Note object
 * 
 * @param par_note 
 */
Note::Note(const Note &par_note){
text = new std::string;
*text = *par_note.text;
};
/**
 * @brief Destroy the Note:: Note object
 * 
 */
Note::~Note(){
    delete text;
    text = nullptr;
};
/**
 * @brief displays Note
 * 
 * @return true 
 * @return false 
 */
bool Note::display(){
    std::cout<<*text;
    return true;
};
int main(){
Note note1("Note 1");
Note note2(note1);
note2.display();
note2.~Note();
    return 0;
}
/**
 * Bei destruktur wird 2 mal den gleichen Speicherort versucht zum löschen
 * 
 */
