
#ifndef RAILWAY_MAIN
#define RAILWAY_MAIN



//============================autoLoadFunctions=========================/
int createTextFile(int isExist);
void loadUsersFile();

//----------------Authentication Modules-----------------//
int Authentication();
int SignUp();
int SignIn();
int Logout();


//=============================Intro Menu========================//
int IntroMenu(const char arr[][20], int len);


//=========================Error Handlers======================//
int Invalid_Error(char message[20]);

//========================load arrays=========================//
extern const char user_arr[6][20];  // Declare the user menu options
extern const char admin_arr[3][20];  // Declare the admin menu options
extern const char authentication_arr[3][20];
extern const char users[2][20];


#endif