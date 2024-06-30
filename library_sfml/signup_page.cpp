#include "signup_page.h"
signup_page::signup_page() :
	signup_submit(1400, 700, "Submit"),
	login_submit(1400, 700, "Submit"),
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
	login(260, 100, "LOG IN", 't', colors::title)
{
	isLoginVisible = false;
	isSignupVisible = false;
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
}

void signup_page::draw_login_page(RenderWindow& window)
{
	window.draw(userText.text);
	window.draw(passText.text);
	window.draw(login.text);
	login_field_username.fieldDraw(window);
	login_submit.buttonDraw(window);
	signup_field_password.fieldDraw(window);

}
