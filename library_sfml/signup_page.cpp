#include "signup_page.h"

buttons signup_page::signup_submit(1400, 700, "Submit", false);
buttons signup_page::login_submit(1400, 700, "Submit", false);
TextField signup_page::signup_field_username(500, 380);
TextField signup_page::signup_field_password(500, 580);
TextField signup_page::login_field_username(500, 380);
TextField signup_page::login_field_password(500, 580);
Circle signup_page::reader_check(700, 710, "As a reader");
Circle signup_page::admin_check(350, 710, "As an adminstrator");
texts signup_page::userText(350, 300, "Username", 'n', colors::ntexts);
texts signup_page::passText(350, 500, "Password", 'n', colors::ntexts);
texts signup_page::warning(1000, 300, "Wrong username or password, please trying again", 'w', colors::warning);
texts signup_page::signup(260, 100, "SIGN UP", 't', colors::title);
texts signup_page::login(260, 100, "LOG IN", 't', colors::title);
photos signup_page::decoration("decoration.jpeg", 1212, 200, 0.5, 0.5);
photos signup_page::decoration2("decoration2.jpeg", 1100, 200, 0.5, 0.5);
bool signup_page::isLoginVisible = false;
bool signup_page::isSignupVisible = false;
bool signup_page::isWarning = false;

signup_page::signup_page() {}

void signup_page::draw_signup_page(RenderWindow& window)
{
	window.draw(userText.text);
	window.draw(passText.text);
	admin_check.circleDraw(window);
	reader_check.circleDraw(window);
	signup_field_username.fieldDraw(window);
	signup_submit.buttonDraw(window);
	signup_field_password.fieldDraw(window);
	window.draw(signup.text);
	window.draw(decoration.pic);
}

void signup_page::draw_login_page(RenderWindow& window)
{
	window.draw(userText.text);
	window.draw(passText.text);
	window.draw(login.text);
	login_field_username.fieldDraw(window);
	login_submit.buttonDraw(window);
	login_field_password.fieldDraw(window);
	window.draw(decoration2.pic);


}

void signup_page::resetInputFlags() {
	signup_field_username.inputEntered = false;
	signup_field_password.inputEntered = false;
	login_field_username.inputEntered = false;
	login_field_password.inputEntered = false;
}

bool signup_page::onSignUpSubmit(User& user, String username, String password, texts& warning)
{
	warning.text.setPosition(350, 780);

	if (username.getSize() == 0 || password.getSize() == 0) {
		warning.text.setString("Don't leave the username or password empty.");
		return false;
	}
	else if (password.getSize() < 3) {
		warning.text.setString("Password is too short.");
		return false;
	}
	else {
		for (int i = 0; i < file_management::users.size(); i++) {
			if (username == file_management::users[i].username) {
				warning.text.setString("Username already used, try another username.");
				return false;
			}
		}
		user.username = username;
		user.password = password;
		if (user.isAdmin) {
			user.usertype = "Admin";
		}
		else {
			user.usertype = "Reader";
		}
		file_management::users.push_back(user);
		
	}
	user.username = "";
	user.password = "";
	user.usertype = "";
	user.isAdmin = false;
	signup_field_username.data = "";
	signup_field_password.data = "";
	signup_field_username.input.setString("");
	signup_field_password.input.setString("");
	admin_check.onUncheck();
	reader_check.onUncheck();


	return true;
}

bool signup_page::onLoginSubmit(User& user, String username, String password, texts& warning) {
	warning.text.setPosition(500, 690);
	if (username.getSize() == 0 || password.getSize() == 0) {
		warning.text.setString("Don't leave the username or password empty.");
		
		return false;
	}

	bool userFound = false;
	for (auto& u : file_management::users) {
		if (username == u.username && password == u.password) {
			file_management::selectedUser = u;
			userFound = true;
			break;
		}
	}

	if (!userFound) {
		warning.text.setString("Invalid username or password.");
		return false;
	}
	else {
		user.username = "";
		user.password = "";
		user.usertype = "";
		user.isAdmin = false;
		login_field_username.data = "";
		login_field_password.data = "";
		login_field_username.input.setString("");
		login_field_password.input.setString("");

		return true;
	}
}

void signup_page::onSignupHover(Vector2f pos)
{

	if (signup_page::isLoginVisible && signup_page::login_submit.button.getGlobalBounds().contains(pos)) {
		signup_page::login_submit.onHover();
	}
	else if (signup_page::isSignupVisible && signup_page::signup_submit.button.getGlobalBounds().contains(pos)) {
		signup_page::signup_submit.onHover();
	}
	else {
		signup_page::login_submit.onUnHover();
		signup_page::signup_submit.onUnHover();

	}
}

void signup_page::onButtonsClicked(Vector2f pos, User& newuser)
{
	if (signup_page::isSignupVisible && signup_page::admin_check.CheckFloat.contains(pos)) {
		newuser.isAdmin = true;
		signup_page::admin_check.onCheck();
		signup_page::reader_check.onUncheck();
	}
	else if (signup_page::isSignupVisible && signup_page::reader_check.CheckFloat.contains(pos)) {
		newuser.isAdmin = false;
		signup_page::reader_check.onCheck();
		signup_page::admin_check.onUncheck();
	}
	else if (signup_page::isSignupVisible && signup_page::signup_field_username.fieldFloat.contains(pos)) {
		signup_page::signup_field_username.inputEntered = true;
		signup_page::signup_field_username.onselect();
		signup_page::signup_field_password.inputEntered = false;
		signup_page::signup_field_password.onunselect();
	}
	else if (signup_page::isSignupVisible && signup_page::signup_field_password.fieldFloat.contains(pos)) {
		signup_page::signup_field_username.inputEntered = false;
		signup_page::signup_field_username.onunselect();
		signup_page::signup_field_password.inputEntered = true;
		signup_page::signup_field_password.onselect();
	}
	else if (signup_page::isLoginVisible && signup_page::login_field_username.fieldFloat.contains(pos)) {
		signup_page::login_field_username.inputEntered = true;
		signup_page::login_field_username.onselect();
		signup_page::login_field_password.inputEntered = false;
		signup_page::login_field_password.onunselect();
	}
	else if (signup_page::isLoginVisible && signup_page::login_field_password.fieldFloat.contains(pos)) {
		signup_page::login_field_username.inputEntered = false;
		signup_page::login_field_username.onunselect();
		signup_page::login_field_password.inputEntered = true;
		signup_page::login_field_password.onselect();
	}
	else if (signup_page::isSignupVisible && signup_page::signup_submit.button_float.contains(pos)) {
		if (signup_page::onSignUpSubmit(newuser, signup_page::signup_field_username.data, signup_page::signup_field_password.data, signup_page::warning)) {
			signup_page::isSignupVisible = false;
			signup_page::isLoginVisible = true;
			signup_page::resetInputFlags();
			signup_page::isWarning = false;

		}
		else {
			signup_page::isWarning = true;
		}
	}
	else if (signup_page::isLoginVisible && signup_page::login_submit.button_float.contains(pos)) {
		if (signup_page::onLoginSubmit(newuser, signup_page::login_field_username.data, signup_page::login_field_password.data, signup_page::warning)) {
			signup_page::isLoginVisible = false;
			signup_page::isWarning = false;
			home_page::isHomepageVisible = true;
		}
		else {
			signup_page::isWarning = true;
		}
	}
}

