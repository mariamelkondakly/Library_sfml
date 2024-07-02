#include "home_page.h"
photos home_page::fantasy("fantasy.jpeg", 100, 250, 0.5, 0.5);
photos home_page::mystery("mystery.jpeg", 100, 450, 0.5, 0.5);
photos home_page::romance("romance.jpeg", 100, 650, 0.5, 0.5);
photos home_page::sci_fi("sci-fi.jpeg", 100, 850, 0.5, 0.5);
photos home_page::nonfiction("nonfiction.jpeg", 100, 1050, 0.5, 0.5);
buttons home_page::fantasyButton(300, 250, "Fantasy");
buttons home_page::mysteryButton(300, 450, "Mystery");
buttons home_page::romanceButton(300, 650, "Romance");
buttons home_page::scifiButton(300, 850, "Science Fiction");
buttons home_page::nonficButton(300, 1050, "Non Fiction");
texts home_page::fantasyDescription(300, 300, fdesc, 'w', colors::ntexts);
texts home_page::mysteryDescription(300, 300, mdesc, 'w', colors::ntexts);
texts home_page::romanceDescription(300, 300, rdesc, 'w', colors::ntexts);
texts home_page::scifiDescription(300, 300, sdesc, 'w', colors::ntexts);
texts home_page::nonficDescription(300, 300, ndesc, 'w', colors::ntexts);
bool home_page::isHomepageVisible = false;
string home_page::fdesc = "Get transported to magical worlds with epic quests and mythical creatures.\n Notable authors include Victoria Aveyard, and Stephanie Garber.";
string home_page::mdesc = "Mystery enthralls with suspenseful plots and enigmatic crimes. \n  Holly Jackson and Alex Michaelides psychologically rich stories that keep readers on the edge of their seats.";
string home_page::rdesc = "Romance delves into the complexities of love and relationships.\n Contemporary authors like Nora Roberts and Colleen Hoover explore the joys and challenges of romance.";
string home_page::sdesc = "Envision futuristic worlds and technological advancements. \n Writers like Marie Lu and Tahereh Mafi create thought - provoking narratives that push the boundaries of imagination.";
string home_page::ndesc = "Nonfiction educates and informs, offering real - world insights and stories. \n Authors like Yuval Noah Harari and Michelle Obama provide compelling, informative works that enlighten and inspire readers.";



void home_page::drawHomepage(RenderWindow& window) {
    if (file_management::selectedUser.isAdmin) {
        navbar::adminNavDraw(window, true);
    }
    else {
        navbar::readerNavDraw(window, true);
    }

        window.draw(fantasy.pic);
        window.draw(mystery.pic);
        window.draw(romance.pic);
        window.draw(sci_fi.pic);
        window.draw(nonfiction.pic);
        fantasyButton.buttonDraw(window);
        mysteryButton.buttonDraw(window);
        romanceButton.buttonDraw(window);
        scifiButton.buttonDraw(window);
        nonficButton.buttonDraw(window);
        window.draw(fantasyDescription.text);
        window.draw(mysteryDescription.text);
        window.draw(romanceDescription.text);
        window.draw(scifiDescription.text);
        window.draw(nonficDescription.text);










    
}

void home_page::genreTouched(Vector2f pos) {
        if (fantasyButton.button.getGlobalBounds().contains(pos)) {
            fantasyButton.buttonText.setFillColor(Color(107, 142, 35));
            mysteryButton.buttonText.setFillColor(Color(204, 85, 0));
            romanceButton.buttonText.setFillColor(Color(204, 85, 0));
            scifiButton.buttonText.setFillColor(Color(204, 85, 0));
            nonficButton.buttonText.setFillColor(Color(204, 85, 0));

        }
        else if (mysteryButton.button.getGlobalBounds().contains(pos)) {
            mysteryButton.buttonText.setFillColor(Color(107, 142, 35));
            fantasyButton.buttonText.setFillColor(Color(204, 85, 0));
            romanceButton.buttonText.setFillColor(Color(204, 85, 0));
            scifiButton.buttonText.setFillColor(Color(204, 85, 0));
            nonficButton.buttonText.setFillColor(Color(204, 85, 0));
        }
        else if (romanceButton.button.getGlobalBounds().contains(pos)) {
            romanceButton.buttonText.setFillColor(Color(107, 142, 35));
            mysteryButton.buttonText.setFillColor(Color(204, 85, 0));
            fantasyButton.buttonText.setFillColor(Color(204, 85, 0));
            scifiButton.buttonText.setFillColor(Color(204, 85, 0));
            nonficButton.buttonText.setFillColor(Color(204, 85, 0));

        }
        else if (scifiButton.button.getGlobalBounds().contains(pos)) {
            scifiButton.buttonText.setFillColor(Color(107, 142, 35));
            mysteryButton.buttonText.setFillColor(Color(204, 85, 0));
            romanceButton.buttonText.setFillColor(Color(204, 85, 0));
            fantasyButton.buttonText.setFillColor(Color(204, 85, 0));
            nonficButton.buttonText.setFillColor(Color(204, 85, 0));
        }
        else if (nonficButton.button.getGlobalBounds().contains(pos)) {
            nonficButton.buttonText.setFillColor(Color(107, 142, 35));
            mysteryButton.buttonText.setFillColor(Color(204, 85, 0));
            romanceButton.buttonText.setFillColor(Color(204, 85, 0));
            scifiButton.buttonText.setFillColor(Color(204, 85, 0));
            fantasyButton.buttonText.setFillColor(Color(204, 85, 0));
        }
        
}


