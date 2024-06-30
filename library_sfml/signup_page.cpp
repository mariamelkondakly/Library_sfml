#include "signup_page.h"


signup_page::signup_page() :
	signup_submit(1400, 700, "Submit",false),
	login_submit(1400, 700, "Submit",false),
	signup_field_username(500, 380),
	signup_field_password(500, 580),
	login_field_username(500, 380),
	login_field_password(500, 580),
	reader_check(700, 710, "As a reader"),
	admin_check(350, 710, "As an adminstrator"),
	userText(350, 300, "Username", 'n', colors::ntexts),
	passText(350, 500, "Password", 'n', colors::ntexts),
	warning(1000, 300, "Wrong username or password, please trying again", 'w', colors::warning),
	signup(260, 100,"SIGN UP", 't', colors::title),
	login(260, 100, "LOG IN", 't', colors::title),
	decoration("decoration.jpeg",1212,200,0.5,0.5),
decoration2("decoration2.jpeg",1100,200,0.5,0.5)
{
	isLoginVisible = false;
	isSignupVisible = false;
	isWarning = false;
	

}

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

void signup_page::resetInputFlags(signup_page& signup) {
	signup.signup_field_username.inputEntered = false;
	signup.signup_field_password.inputEntered = false;
	signup.login_field_username.inputEntered = false;
	signup.login_field_password.inputEntered = false;
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
			file_management::selectedUser = &u;
			userFound = true;
			break;
		}
	}

	if (!userFound) {
		warning.text.setString("Invalid username or password.");
		return false;
	}
	return true;
}

