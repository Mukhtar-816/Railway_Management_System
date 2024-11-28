
#ifndef RAILWAY_MAIN
#define RAILWAY_MAIN

//============================ USER/ADMIN Home ==========================//
void InitiatingCall();
void Home();


//=========================== User Functions ==========================//
void ViewTrains();
void BookTicket();
int generateRandomID();
int checkUniqueID();
void CancelTicket();
void ShowUsersBookedTicket();
void ShowUsersCancelledTicket();

//============================= Admin Functions =============================//
void AddTrain();
void RemoveTrain();
void ViewAllBookings();

//============================ AutoLoadFunctions =========================//
int createTextFile(int isExist);


//================ Authentication Modules =================//
void Authentication();
int AuthValidator(char username[], char pwd[]);
void SignUp();
void SignIn();
void Logout();


//=============================Intro Menu========================//
int IntroMenu(const char arr[][30], int len);



//=========================Error Handlers======================//
int Invalid_Error(char message[20]);


//========================load arrays=========================//
extern const char user_arr[6][30];  // Declare the user menu options
extern const char admin_arr[5][30];  // Declare the admin menu options
extern const char authentication_arr[3][30];
extern const char users[3][30];


#endif