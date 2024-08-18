#include "home_page.h"
photos home_page::fantasy("assets/fantasy.jpeg", 200, 300, 0.4, 0.4);
photos home_page::mystery("assets/mystery.jpeg", 200, 760, 0.4, 0.4);
photos home_page::romance("assets/romance.jpeg", 200, 1220, 0.4, 0.4);
photos home_page::sci_fi("assets/sci-fi.jpeg", 200, 1680, 0.4, 0.4);
photos home_page::nonfiction("assets/nonfiction.jpeg", 200, 2140, 0.4, 0.4);
buttons home_page::fantasyButton(650, 300, "Fantasy",70);
buttons home_page::mysteryButton(650, 760, "Mystery",70);
buttons home_page::romanceButton(650, 1220, "Romance",70);
buttons home_page::scifiButton(650, 1680, "Science Fiction",70);
buttons home_page::nonficButton(650, 2140, "Non Fiction",70);
string home_page::fdesc = "Fantasy transports readers to magical worlds with epic quests and mythical creatures.\nNotable authors include Stephanie Garber, whose intricate magic systems captivate,\nand Victoria Aveyard, renowned for his complex characters and sprawling narratives.";
string home_page::mdesc = "Mystery enthralls with suspenseful plots and enigmatic crimes.\nModern masters like Karen MCcanus and Holly Jackson craft gripping,\npsychologically rich stories that keep readers on the edge of their seats.";
string home_page::rdesc = "Romance delves into the complexities of love and relationships.\nContemporary authors like Emily Henry and Colleen Hoover deliver heartfelt,\nemotionally charged tales that explore the joys and challenges of romance.";
string home_page::sdesc = "Sci-Fi envisions futuristic worlds and technological advancements.\nWriters like Taherah Mafi and Marie Lu create thought-provoking narratives\nthat push the boundaries of imagination and explore profound ethical dilemmas.";
string home_page::ndesc = "Nonfiction educates and informs, offering real-world insights and stories.\nAuthors like Yuval Noah Harari and Michelle Obama provide compelling,\ninformative works that enlighten and inspire readers with their depth and authenticity.";
texts home_page::fantasyDescription(730, 500, fdesc, 'w', colors::ntexts);
texts home_page::mysteryDescription(730, 960, mdesc, 'w', colors::ntexts);
texts home_page::romanceDescription(730, 1420, rdesc, 'w', colors::ntexts);
texts home_page::scifiDescription(730, 1880, sdesc, 'w', colors::ntexts);
texts home_page::nonficDescription(730, 2340, ndesc, 'w', colors::ntexts);
texts home_page::explore(200, 120, "Explore our genres", 't', colors::title);
bool home_page::isHomepageVisible = false;




void home_page::drawHomepage(RenderWindow& window) {
    if (file_management::users[file_management::selectedUser].usertype=="Admin") {
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
        window.draw(explore.text);
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
        else {
            fantasyButton.buttonText.setFillColor(Color(204,85,0));
            mysteryButton.buttonText.setFillColor(Color(204, 85, 0));
            romanceButton.buttonText.setFillColor(Color(204, 85, 0));
            scifiButton.buttonText.setFillColor(Color(204, 85, 0));
            nonficButton.buttonText.setFillColor(Color(204, 85, 0));
        }
        
}

void home_page::enableScrolling() {
    Scrollable::setLowerBound(nonfiction.pic.getPosition().y + nonfiction.pic.getScale().y+500);
}
void home_page::checkingClicks()
{
    if (Books_page::isFantasyClicked|| Books_page::isRomanceClicked|| Books_page::isScifiClicked|| Books_page::isNonfictionClicked|| Books_page::isMysteryClicked) {
        home_page::isHomepageVisible = false;
        Books_page::isBookspageVisible = true;

    }
}
void home_page::genreClicked(Vector2f pos) {

    if (fantasyButton.button.getGlobalBounds().contains(pos)) {
        Books_page::isFantasyClicked = true;
        Books_page::isMysteryClicked = false;
        Books_page::isRomanceClicked = false;
        Books_page::isScifiClicked = false;
        Books_page::isNonfictionClicked = false;
    }
    else if (mysteryButton.button.getGlobalBounds().contains(pos)) {
        Books_page::isMysteryClicked = true;
        Books_page::isFantasyClicked = false;
        Books_page::isRomanceClicked = false;
        Books_page::isScifiClicked = false;
        Books_page::isNonfictionClicked = false;
    }
    else if (romanceButton.button.getGlobalBounds().contains(pos)) {
        Books_page::isRomanceClicked = true;
        Books_page::isMysteryClicked = false;
        Books_page::isFantasyClicked = false;
        Books_page::isScifiClicked = false;
        Books_page::isNonfictionClicked = false;
    }
    else if (scifiButton.button.getGlobalBounds().contains(pos)) {
        Books_page::isScifiClicked = true;
        Books_page::isMysteryClicked = false;
        Books_page::isRomanceClicked = false;
        Books_page::isFantasyClicked = false;
        Books_page::isNonfictionClicked = false;
    }
    else if (nonficButton.button.getGlobalBounds().contains(pos)) {
        Books_page::isNonfictionClicked = true;
        Books_page::isMysteryClicked = false;
        Books_page::isRomanceClicked = false;
        Books_page::isFantasyClicked = false;
        Books_page::isScifiClicked = false;
    }
    else {
        Books_page::isNonfictionClicked = false;
        Books_page::isMysteryClicked = false;
        Books_page::isRomanceClicked = false;
        Books_page::isFantasyClicked = false;
        Books_page::isScifiClicked = false;
    }
    checkingClicks();
}

