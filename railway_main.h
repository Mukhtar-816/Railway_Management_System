
#ifndef RAILWAY_MAIN
#define RAILWAY_MAIN

//============================ USER/ADMIN Home ==========================//
void InitiatingCall();
void Home();


//=========================== Basic Functions ==========================//
void ViewTrains();
void BookTicket();
int generateRandomID();

//============================ AutoLoadFunctions =========================//
int createTextFile(int isExist);


//================ Authentication Modules =================//
void Authentication();
int AuthValidator(char username[], char pwd[]);
void SignUp();
void SignIn();
void Logout();


//=============================Intro Menu========================//
int IntroMenu(const char arr[][20], int len);



//=========================Error Handlers======================//
int Invalid_Error(char message[20]);


//========================load arrays=========================//
extern const char user_arr[6][20];  // Declare the user menu options
extern const char admin_arr[3][20];  // Declare the admin menu options
extern const char authentication_arr[3][20];
extern const char users[3][20];


#endif